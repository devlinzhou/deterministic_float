﻿/* 
 * Copyright (C) 2022 zhou xuan, Email: zhouxuan6676@gmail.com 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. 
 * You may obtain a copy of the License at * 
 * http://www.apache.org/licenses/LICENSE-2.0 * 
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
 * See the License for the specific language governing permissions and 
 * limitations under the License. 
 */
#include "deterministic_float.h"
#include "glacier_float.h"
#include "glacier_platform.h"

#include <initializer_list>
#include <random>
#include <functional>
#include <iomanip>
#include <thread>

#if UseProfiler_RDTSCP

static double CountCpuGhz() {

    Myclock::time_point tStart = Myclock::now();;
    uint64_t uStart = GTimer::get_CPUCycles();
        
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    uint64_t uEnd = GTimer::get_CPUCycles();
    Myclock::time_point tEnd = Myclock::now();

    double time = double(std::chrono::duration_cast<Myres>(tEnd - tStart).count() * 1e-9);

    double CpuGhz = double(uEnd - uStart) / (time * 1000000000);
    return CpuGhz;

}

double GTimer::InvCPUGHZ = 0.000001f / CountCpuGhz();
#endif


class GFloatTest
{
public:
    std::vector<float>  fa;
    std::vector<float>  fb;
    std::vector<float>  fc;
    std::vector<double>  da;
    std::vector<double>  db;
    std::vector<double>  dc;
    std::vector<GFloat> Ga;
    std::vector<GFloat> Gb;
    std::vector<GFloat> Gc;

    int N;
    double time1 = 0;
    double time2 = 0;
    GTimer Timer;
    std::ofstream m_string;

    GFloatTest(int TN)
    {
        GFloat::Init();
        N = TN;
        fa.resize(N);
        fb.resize(N);
        fc.resize(N);
        da.resize(N);
        db.resize(N);
        dc.resize(N);
        Ga.resize(N);
        Gb.resize(N);
        Gc.resize(N);

        std::string FileName;
#ifdef _WIN64
        FileName = "../../Test_BenchMark_Win";
        if( GetCpuName().find( "12900H" ) != std::string::npos )
        {
            FileName += "_12900H.md";
        }
        else if( GetCpuName().find( "5950X" ) != std::string::npos )
        {
            FileName += "_5950X.md";
        }
        else
        {
            FileName = "_None.md";
        }    

        m_string =  std::ofstream (FileName);
#elif __OSX__ 
        FileName = "../Test_BenchMark_OSX.md";
#endif    
        
        std::stringstream Tstring;

        std::time_t TNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

#ifdef _MSC_VER 
        char str[26];
        ctime_s(str, sizeof str, &TNow);
#else
        char* str = ctime(&TNow);
#endif    
        Tstring << "# GFloat Test And BenchMark" << std::endl;
        Tstring << " * Test time : "<< str  << std::endl;


        Tstring << "|Operation System| C++ Compiler version |CPU  | Base Frequency  |" <<std::endl;
        Tstring << "|:--:|:--:|:--:|:--:|" << std::endl;
        Tstring << "|" << 
            getOSName() << "|" <<
            GetCompileName()  << std::setprecision(3) << "|" <<
            GetCpuName() << "|" <<
            GTimer::GetCpuFrequency_Compute() / 1000000.f << " GHz or " <<" " <<
            GTimer::GetCpuFrequency_CpuInfo() / 1000.f <<" GHz " << "|"<< std::endl;
        
        
        Tstring << " * Performance: float vs GFloat,  Call " << N << " times" << std::endl;
        Tstring << " * Error : the relative error between cmath (double) and GFloat Math " << std::endl << std::endl;

        Tstring << "| Function | input data range |avg relative error | max relative error | max abs error | float vs GFloat | float / GFloat |"<< std::endl;
        Tstring << "|:--|:--:|:--:|:--:|:--:|:--:|:--:|" << std::endl;

        GPrintLog( Tstring );

        if( m_string.is_open() )
            m_string << Tstring.str();
    }

    int32_t FindBest(float RMin, float RMax)
    {
        std::minstd_rand gen;
        std::uniform_real_distribution<> dis(RMin, RMax);
        for (int i = 0; i < N; i++) {
            fa[i] = (float)dis(gen);
            fb[i] = (float)dis(gen);
            fc[i] = 1.f;

            Ga[i] = GFloat::FromFloat(fa[i]);
            Gb[i] = GFloat::FromFloat(fb[i]);
            Gc[i] = GFloat(0);
        }
        for (int i = 0; i < N; i++) {
            fc[i] = 1.f / sqrtf(fa[i]);
            Gc[i] = GFloat::InvSqrt(Ga[i]);
        }

        float fMaxAbs = 100000000.f;
        GFloat BestStart = GFloat::Zero();
        for (GFloat GStart = GFloat(0, 8, 10); GStart < GFloat(0, 9, 10); GStart += GFloat(0, 1, 1000))
        {
            float fabs = 0;
            for (int i = 0; i < N; i++)
            {
                fc[i] = 1.f / sqrtf(fa[i]);
                Gc[i] = GFloat::InvSqrt(Ga[i]/*,GStart*/);

                if (Gc[i] != GFloat::Zero())
                {
                    fabs += abs(Gc[i].toFloat() - fc[i]);
                }
            }
            std::cout << "Current fabs " << fabs << std::endl;
            if (fMaxAbs > fabs)
            {
                BestStart = GStart;
                fMaxAbs = fabs;
            }
        }

        std::cout << "fMaxAbs   " << fMaxAbs << std::endl;
        std::cout << "Best GStart  " << BestStart.rawint32 << "  " << BestStart.toFloat() << std::endl;
        return BestStart.rawint32;
    }

    enum EGType
    {
        ERelative = 1,
        EAbsolute = 2,
        EOrignal = 4,
        EAll = 7
    };

    inline void FunError( int NCount, EGType TType, std::string name, double RMin, double RMax,
        std::function<double(double i)> fun_f,
        std::function<double(double i)> fun_G)
    {
        std::string CurrentType;
        
        if( TType == EGType::ERelative )
            CurrentType = "Relative";
        else if( TType == EGType::EAbsolute)
            CurrentType = "Absolute";
        else
            CurrentType = "Graph";

        std::ofstream fs("../GFloat_" + name + "_" + CurrentType + ".gp");

        fs << "set term svg size 640, 480" << std::endl;
        fs << "set output \"GFloat_" + name + "_" + CurrentType + ".svg\"" << std::endl;
        fs << R"gp(set format y "%g%%")gp" << std::endl;
        fs << "set title \"GFloat::" + name + "() " + CurrentType + " Error\"" << std::endl;
        fs << "unset key" << std::endl;
        fs << "plot \"-\" with points" << std::endl;

        fs << std::setprecision(std::numeric_limits<double>::digits10 + 1);

        double delta = abs( RMax - RMin ) / NCount;
        double TMin = fmin( RMin, RMax );
        double TMax = fmax( RMin, RMax);

        for (double i = TMin; i < TMax; i += delta) {
            double fy = fun_f(i);
            double Gy = fun_G(i);

            double ferror = 0;

            if (TType == EGType::ERelative)
            {
                if( abs(fy) > 0.0000001 )
                    ferror = (Gy - fy) * 100.0 / abs(fy);
            }
            else if (TType == EGType::EAbsolute)
                ferror = (Gy - fy) * 100.0;
            else
                ferror = (Gy ) * 100.0;
            
            fs << i << " " << ferror << std::endl;
        }

        fs << "EOF" << std::endl;
    }

    inline void FunGraph(std::string name, int NCount, EGType TType, float RMin, float RMax,
        std::function<double(double i)> fun_f,
        std::function<double(double i)> fun_G)
    {
        if (TType & EGType::ERelative)
        {
            FunError(NCount, EGType::ERelative, name, RMin, RMax, fun_f, fun_G );
        }
        if (TType & EGType::EAbsolute)
        {
            FunError(NCount, EGType::EAbsolute, name, RMin, RMax, fun_f, fun_G);
        }
        if (TType & EGType::EOrignal)
        {
            FunError(NCount, EGType::EOrignal, name, RMin, RMax, fun_f, fun_G);
        }
    }

    inline void FunTest(
        std::string name,
        double RMin, double RMax,
        std::function<void(int N)> fun_f,
        std::function<void(int N)> fun_d,
        std::function<void(int N)> fun_G  )
    {
        std::minstd_rand gen;
        std::uniform_real_distribution<> dis(RMin, RMax);

        int32_t nScaleTime = 5;
        int32_t Niner = N / nScaleTime;

        for( int nLog = 0; nLog < nScaleTime; nLog++ )
        {
            double dt = 1. / pow(10,nLog);

            for (int j = 0; j < Niner; j++)
            {
                int i = nLog * Niner + j;
                double fda = dis(gen) * dt;
                double fdb = dis(gen) * dt;

                Ga[i] = GFloat::FromFloat((float)fda);
                Gb[i] = GFloat::FromFloat((float)fdb);
                fa[i] = Ga[i].toFloat();
                fb[i] = Gb[i].toFloat();
                da[i] = Ga[i].toDouble();
                db[i] = Gb[i].toDouble();

                fc[i] = 2.5f;
                dc[i] = 2.5f;
                Gc[i] = GFloat(2, 1, 2);

            }
        }

        Timer.Start();
        {
            fun_f(N);
        }
        time1 = Timer.GetDeltaTimeMS();

        fun_d(N);

        Timer.Start();
        {
            fun_G(N);
        }
        time2 = Timer.GetDeltaTimeMS();

        Count(RMin, RMax,name );
    }

    void Count(double RMin, double RMax, std::string Name )
    {
        double f1 = 0;
        double f2 = 0;

        double Maxabs = 0;
        double RMaxabs = 0;
        int maxi = 0;

        int nCount = 0;
        double totalabs = 0;

        for (int i = 0; i < N; i++)
        {
            double cf1 = (fc[i]);
            double cf2 = (Gc[i].toDouble());

           // double cf2 = (fc[i]);
            if( abs(cf1) < 0.0000000000001 )
                continue;
            double cAbs = abs((cf2 - cf1) / cf1 );
            totalabs += cAbs;
            nCount++;
            if (Maxabs < cAbs)
            {
                Maxabs = cAbs;
                maxi = i;
            }

            if( RMaxabs < abs(cf2 - cf1))
            {
                RMaxabs = abs(cf2 - cf1);
            }

            f1 += abs(cf1);
            f2 += abs(cf2);
        }

        double avgerror = totalabs  / nCount;

        std::stringstream Tstring;
        std::cout.precision(3);

        double timeratio = time1 / time2;


        Tstring << "|" << std::setiosflags(std::ios::left) << std::setw(12) << Name;
        Tstring << "|[" << std::setiosflags(std::ios::right) << std::setw(9) << std::setiosflags(std::ios::fixed)<<std::setprecision(1) << RMin << "," << std::setiosflags(std::ios::right) << std::setw(9) << RMax << "]";
        Tstring << "|" << std::setiosflags(std::ios::right) << std::setw( 10) << std::setiosflags(std::ios::fixed) << std::setprecision(6) <<avgerror * 100.f << " %";
        Tstring << "|" << std::setiosflags(std::ios::right) << std::setw(14) << Maxabs * 100.f << " %";
        Tstring << "|" << std::setiosflags(std::ios::right) << std::setw(14)<< RMaxabs ;
        Tstring << "|" << std::setiosflags(std::ios::right) << std::setw( 5) <<std::setprecision(2) << time1;
        Tstring <<" vs "<< std::setiosflags(std::ios::right) << std::setw( 5) << time2 << "  (ms)|"; 

        if( timeratio > 1 )
            Tstring << "**" << timeratio << "** |"<< std::endl;
        else
            Tstring <<  timeratio << " |"<< std::endl;

        GPrintLog( Tstring );

        if( m_string.is_open() )
            m_string << Tstring.str();
    }
};
// why add 3, for Resist the c++ compiler optimizations

#define GMYFun( a, c ) \
{\
    for (int j =  0; j < N/3; j++ )\
    {\
        int i = j*3;GFloat f; \
        (c) = (a);i++;\
        (c) = (a);i++;\
        (c) = (a);\
    }\
}\

void TestGFloat::Run()
{
   // std::cout << std::hex << GFloat(3,0,2).rawint32 << std::endl;

    GFloatTest FT(1000000);

    bool bErrortest =0;
    if (bErrortest)
    {
        float fstart = 20.f;
        FT.FunGraph("Sin", 1000, GFloatTest::EGType::EAll, -fstart, fstart, [&](double i)->double {return (double)sinf( (float)i); }, [&](double i)->double {return GFloat::Sin(GFloat::FromFloat((float)i)).toDouble(); });   
        FT.FunGraph("ASin", 1000, GFloatTest::EGType::EAll, -1, 1, [&](double i)->double {return (double)asinf((float)i); }, [&](double i)->double {return GFloat::ASin(GFloat::FromFloat((float)i)).toDouble(); });
        FT.FunGraph("ACos", 1000, GFloatTest::EGType::EAll, -1, 1, [&](double i)->double {return (double)acosf((float)i); }, [&](double i)->double {return GFloat::ACos(GFloat::FromFloat((float)i)).toDouble(); });
        FT.FunGraph("Exp", 1000, GFloatTest::EGType::EAll, -fstart, fstart, [&](double i)->double {return (double)expf((float)i); }, [&](double i)->double {return GFloat::Exp(GFloat::FromFloat((float)i)).toDouble(); });
        FT.FunGraph("Pow2", 1000, GFloatTest::EGType::EAll, -fstart, fstart, [&](double i)->double {return (double)powf(2.f,(float)i); }, [&](double i)->double {return GFloat::Pow2(GFloat::FromFloat((float)i)).toDouble(); });
        FT.FunGraph("Log", 1000, GFloatTest::EGType::EAll, 0, 100000.f, [&](double i)->double {return (double)logf( (float)i); }, [&](double i)->double {return GFloat::Log(GFloat::FromFloat((float)i)).toDouble(); });  
        return;
    }

    FT.FunTest("Mul+Add", -10000.f, 10000.f, [&](int N)->void {GMYFun(FT.fa[i] * FT.fb[i] + FT.fb[i], FT.fc[i])}, [&](int N)->void {GMYFun(FT.da[i] * FT.db[i] + FT.db[i], FT.dc[i])}, [&](int N)->void {GMYFun(FT.Ga[i] * FT.Gb[i] + FT.Gb[i], FT.Gc[i]) });

    FT.FunTest("Add",       -10000.f, 10000.f, [&](int N)->void{GMYFun(FT.fa[i] + FT.fb[i], FT.fc[i])}, [&](int N)->void{GMYFun(FT.da[i] + FT.db[i], FT.dc[i])},    [&](int N)->void {GMYFun(FT.Ga[i] + FT.Gb[i], FT.Gc[i])});
    FT.FunTest("Sub",       -10000.f, 10000.f, [&](int N)->void{GMYFun(FT.fa[i] - FT.fb[i], FT.fc[i])}, [&](int N)->void{GMYFun(FT.da[i] - FT.db[i], FT.dc[i])},    [&](int N)->void {GMYFun(FT.Ga[i] - FT.Gb[i], FT.Gc[i] ) });
    FT.FunTest("Mul",       -10000.f, 10000.f, [&](int N)->void{GMYFun(FT.fa[i] * FT.fb[i], FT.fc[i])}, [&](int N)->void{GMYFun(FT.da[i] * FT.db[i], FT.dc[i])},    [&](int N)->void {GMYFun(FT.Ga[i] * FT.Gb[i], FT.Gc[i] ) });
    FT.FunTest("Div",       -10000.f, 10000.f, [&](int N)->void{GMYFun(FT.fa[i] / FT.fb[i], FT.fc[i])}, [&](int N)->void{GMYFun(FT.da[i] / FT.db[i], FT.dc[i])},    [&](int N)->void {GMYFun(FT.Ga[i] / FT.Gb[i], FT.Gc[i] ) });
    FT.FunTest("Ceil",      -10000.f, 10000.f, [&](int N)->void{GMYFun(ceilf(FT.fa[i])    , FT.fc[i])}, [&](int N)->void{GMYFun(ceil(FT.da[i]),    FT.dc[i] )},     [&](int N)->void {GMYFun(GFloat::Ceil(FT.Ga[i]), FT.Gc[i])});
    FT.FunTest("Floor",     -10000.f, 10000.f, [&](int N)->void{GMYFun(floorf(FT.fa[i])   , FT.fc[i])}, [&](int N)->void{GMYFun(floor(FT.da[i]),   FT.dc[i])},      [&](int N)->void {GMYFun(GFloat::Floor(FT.Ga[i]), FT.Gc[i])});
    FT.FunTest("Whole",     -10000.f, 10000.f, [&](int N)->void{GMYFun((float)int(FT.fa[i]),FT.fc[i])}, [&](int N)->void{GMYFun((double)int(FT.da[i]), FT.dc[i])},  [&](int N)->void {GMYFun(GFloat(FT.Ga[i].GetWhole()), FT.Gc[i] )});
    FT.FunTest("WholeFrac", -10000.f, 10000.f, [&](int N)->void{GMYFun((float)FT.fa[i]    , FT.fc[i])}, [&](int N)->void{GMYFun((double)FT.da[i],  FT.dc[i])},      [&](int N)->void {GMYFun(GFloat(FT.Ga[i].GetWhole(f)) + f, FT.Gc[i])});
    FT.FunTest("Fraction",  -10000.f, 10000.f, [&](int N)->void {GMYFun(FT.fa[i] - (float)FT.fa[i], FT.fc[i])}, [&](int N)->void {GMYFun(FT.da[i] - (double)FT.da[i], FT.dc[i])}, [&](int N)->void {GMYFun((FT.Ga[i].GetWhole(f), f), FT.Gc[i])});

    FT.FunTest("-()",       -10000.f, 10000.f, [&](int N)->void{GMYFun(-FT.fa[i], FT.fc[i])},           [&](int N)->void{GMYFun(-FT.da[i], FT.dc[i]) },             [&](int N)->void {GMYFun(-FT.Ga[i], FT.Gc[i]) });
    FT.FunTest(">()",       -10000.f, 10000.f, [&](int N)->void {GMYFun(FT.fa[i] >  FT.fb[i] ? FT.fa[i] : FT.fb[i], FT.fc[i])}, [&](int N)->void {GMYFun(FT.da[i] >  FT.db[i] ? FT.da[i] : FT.db[i], FT.dc[i])}, [&](int N)->void { GMYFun(FT.Ga[i] > FT.Gb[i] ?  FT.Ga[i] : FT.Gb[i], FT.Gc[i]) });
    FT.FunTest("<()",       -10000.f, 10000.f, [&](int N)->void {GMYFun(FT.fa[i] <  FT.fb[i] ? FT.fa[i] : FT.fb[i], FT.fc[i])}, [&](int N)->void {GMYFun(FT.da[i] <  FT.db[i] ? FT.da[i] : FT.db[i], FT.dc[i])}, [&](int N)->void { GMYFun(FT.Ga[i] < FT.Gb[i] ?  FT.Ga[i] : FT.Gb[i], FT.Gc[i]) });
    FT.FunTest(">=()",      -10000.f, 10000.f, [&](int N)->void {GMYFun(FT.fa[i] >= FT.fb[i] ? FT.fa[i] : FT.fb[i], FT.fc[i])}, [&](int N)->void {GMYFun(FT.da[i] >= FT.db[i] ? FT.da[i] : FT.db[i], FT.dc[i])}, [&](int N)->void { GMYFun(FT.Ga[i] >= FT.Gb[i] ? FT.Ga[i] : FT.Gb[i], FT.Gc[i]) });
    FT.FunTest("<=()",      -10000.f, 10000.f, [&](int N)->void {GMYFun(FT.fa[i] <= FT.fb[i] ? FT.fa[i] : FT.fb[i], FT.fc[i])}, [&](int N)->void {GMYFun(FT.da[i] <= FT.db[i] ? FT.da[i] : FT.db[i], FT.dc[i])}, [&](int N)->void { GMYFun(FT.Ga[i] <= FT.Gb[i] ? FT.Ga[i] : FT.Gb[i], FT.Gc[i]) });

    FT.FunTest("Abs",           -10000.f, 10000.f, [&](int N)->void {GMYFun(abs(FT.fa[i]), FT.fc[i])},      [&](int N)->void {GMYFun(abs(FT.da[i]), FT.dc[i])},         [&](int N)->void { GMYFun(GFloat::Abs(FT.Ga[i]), FT.Gc[i]) });
    FT.FunTest("Normalize32",   -10000.f, 10000.f, [&](int N)->void {GMYFun(FT.fa[i], FT.fc[i] )},          [&](int N)->void {GMYFun(FT.da[i], FT.dc[i])},              [&](int N)->void {GMYFun(GFloat::Normalize32(FT.Ga[i].getfraction(), FT.Ga[i].getexponent()), FT.Gc[i])});
    FT.FunTest("Normalize64",   -10000.f, 10000.f, [&](int N)->void {GMYFun(FT.fa[i], FT.fc[i])},           [&](int N)->void {GMYFun(FT.da[i], FT.dc[i])},              [&](int N)->void {GMYFun(GFloat::Normalize64((int64_t)FT.Ga[i].getfraction(), FT.Ga[i].getexponent()), FT.Gc[i])});
    FT.FunTest("FromInt",       -10000.f, 10000.f, [&](int N)->void {GMYFun((float)int(FT.fa[i]),FT.fc[i])},[&](int N)->void {GMYFun((double)int(FT.da[i]),FT.dc[i])},  [&](int N)->void {GMYFun(GFloat((int)FT.fa[i]), FT.Gc[i]) });
    FT.FunTest("Fromfloat",     -10000.f, 10000.f, [&](int N)->void {GMYFun(FT.fa[i], FT.fc[i])},           [&](int N)->void {GMYFun(FT.da[i], FT.dc[i])},              [&](int N)->void {GMYFun(FT.Ga[i], FT.Gc[i]) });
    FT.FunTest("CeilToInt",     -10000.f, 10000.f, [&](int N)->void {GMYFun(ceilf(FT.fa[i]), FT.fc[i])},    [&](int N)->void {GMYFun(ceil(FT.da[i]), FT.dc[i])},        [&](int N)->void {GMYFun(GFloat( GFloat::CeilToInt( FT.Ga[i])), FT.Gc[i]) });
    FT.FunTest("FloorToInt",    -10000.f, 10000.f, [&](int N)->void {GMYFun(floorf(FT.fa[i]), FT.fc[i])},   [&](int N)->void {GMYFun(floor(FT.da[i]), FT.dc[i])},       [&](int N)->void {GMYFun(GFloat( GFloat::FloorToInt(FT.Ga[i])), FT.Gc[i]) });

    
    // return;
    FT.FunTest("Sin",       -10000.f, 10000.f,  [&](int N)->void {GMYFun(sinf(FT.fa[i]), FT.fc[i])},    [&](int N)->void {GMYFun(sin(FT.da[i]), FT.dc[i])},         [&](int N)->void { GMYFun(GFloat::Sin(FT.Ga[i]), FT.Gc[i])});
    FT.FunTest("Cos",       -10000.f, 10000.f,  [&](int N)->void {GMYFun(cosf(FT.fa[i]), FT.fc[i])},    [&](int N)->void {GMYFun(cos(FT.da[i]), FT.dc[i])},         [&](int N)->void { GMYFun(GFloat::Cos(FT.Ga[i]), FT.Gc[i])});
    FT.FunTest("Tan",       -10000.f, 10000.f,  [&](int N)->void {GMYFun(tanf(FT.fa[i]), FT.fc[i])},    [&](int N)->void {GMYFun(tan(FT.da[i]), FT.dc[i])},         [&](int N)->void { GMYFun(GFloat::Tan(FT.Ga[i]), FT.Gc[i])});
    FT.FunTest("ASin",      -1.f, 1.f,          [&](int N)->void {GMYFun(asinf(FT.fa[i]), FT.fc[i])},   [&](int N)->void {GMYFun(asin(FT.da[i]), FT.dc[i])},        [&](int N)->void { GMYFun(GFloat::ASin(FT.Ga[i]), FT.Gc[i])});
    FT.FunTest("ACos",      -1.f, 1.f,          [&](int N)->void {GMYFun(acosf(FT.fa[i]), FT.fc[i])},   [&](int N)->void {GMYFun(acos(FT.da[i]), FT.dc[i])},        [&](int N)->void { GMYFun(GFloat::ACos(FT.Ga[i]), FT.Gc[i])});
    FT.FunTest("ATan",      -10000.f, 10000.f,  [&](int N)->void {GMYFun(atanf(FT.fa[i]), FT.fc[i])},   [&](int N)->void {GMYFun(atan(FT.da[i]), FT.dc[i])},        [&](int N)->void { GMYFun(GFloat::ATan(FT.Ga[i]), FT.Gc[i])});
   FT.FunTest("ATan(10,x)", -10000.f, 10000.f,  [&](int N)->void {GMYFun(atan2f(10.f,FT.fa[i]), FT.fc[i])}, [&](int N)->void {GMYFun(atan2(10.,FT.da[i]), FT.dc[i])}, [&](int N)->void { GMYFun(GFloat::ATan2(GFloat(10),FT.Ga[i]), FT.Gc[i])});
   FT.FunTest("ATan(x,10)", -10000.f, 10000.f,  [&](int N)->void {GMYFun(atan2f(FT.fa[i],10.f), FT.fc[i])}, [&](int N)->void {GMYFun(atan2(FT.da[i],10.), FT.dc[i])}, [&](int N)->void { GMYFun(GFloat::ATan2(FT.Ga[i],GFloat(10)), FT.Gc[i])});
  // return;
   FT.FunTest("Sqrt",      0.f, 10000.f,        [&](int N)->void{GMYFun(sqrtf(FT.fa[i]), FT.fc[i])},    [&](int N)->void{GMYFun(sqrt(FT.da[i]),  FT.dc[i])},        [&](int N)->void { GMYFun(GFloat::Sqrt(FT.Ga[i]), FT.Gc[i])});
   FT.FunTest("InvSqrt",   0.f, 10000.f,        [&](int N)->void{GMYFun(1.f/sqrtf(FT.fa[i]), FT.fc[i])},[&](int N)->void{GMYFun(1./sqrt(FT.da[i]),FT.dc[i])},       [&](int N)->void { GMYFun(GFloat::InvSqrt(FT.Ga[i]), FT.Gc[i])});
   FT.FunTest("Exp",       -20.f, 20.f,         [&](int N)->void{GMYFun(expf(FT.fa[i]), FT.fc[i])},     [&](int N)->void{GMYFun(exp(FT.da[i]),   FT.dc[i])},        [&](int N)->void { GMYFun(GFloat::Exp(FT.Ga[i]), FT.Gc[i])});
   FT.FunTest("Pow2",      -30.f, 30.f,         [&](int N)->void{GMYFun(powf(2.f, FT.fa[i]), FT.fc[i])},[&](int N)->void {GMYFun(pow(2., FT.da[i]), FT.dc[i])},     [&](int N)->void { GMYFun(GFloat::Pow2(FT.Ga[i]), FT.Gc[i])});
   FT.FunTest("Log_e",      0.f, 10000.f,       [&](int N)->void{GMYFun(logf(FT.fa[i]), FT.fc[i])},     [&](int N)->void{GMYFun(log(FT.da[i]),   FT.dc[i])},        [&](int N)->void { GMYFun(GFloat::Log(FT.Ga[i]), FT.Gc[i])});
   FT.FunTest("Log_2",      0.f, 10000.f,       [&](int N)->void{GMYFun(log2f(FT.fa[i]), FT.fc[i])},    [&](int N)->void {GMYFun(log2(FT.da[i]), FT.dc[i])},        [&](int N)->void { GMYFun(GFloat::Log2(FT.Ga[i]), FT.Gc[i])});
   FT.FunTest("Log_10",     0.f, 10000.f,       [&](int N)->void {GMYFun(log10f(FT.fa[i]), FT.fc[i])},  [&](int N)->void {GMYFun(log10(FT.da[i]), FT.dc[i])},        [&](int N)->void { GMYFun(GFloat::Log10(FT.Ga[i]), FT.Gc[i])});

   FT.FunTest("Pow(1.7,x)",  -30.f, 30.f,       [&](int N)->void{GMYFun(powf(1.7f, FT.fa[i]), FT.fc[i])},[&](int N)->void{GMYFun(pow(1.7, FT.da[i]), FT.dc[i])},    [&](int N)->void { GMYFun(GFloat::Pow(GFloat(1,7,10), FT.Ga[i]), FT.Gc[i])});
   FT.FunTest("Pow(x,1.7)",  0.55f, 20,         [&](int N)->void{GMYFun(powf(FT.fa[i], 1.7f), FT.fc[i])},[&](int N)->void{GMYFun(pow(FT.da[i], 1.7), FT.dc[i])},    [&](int N)->void { GMYFun(GFloat::Pow(FT.Ga[i], GFloat(1,7,10)), FT.Gc[i])});
   FT.FunTest("Fmod(x,1.7)", -10000.f, 10000.f, [&](int N)->void {GMYFun(fmodf(FT.fa[i], 1.7f), FT.fc[i])}, [&](int N)->void {GMYFun(fmod(FT.da[i], 1.7), FT.dc[i])}, [&](int N)->void { GMYFun(GFloat::Fmod(FT.Ga[i], GFloat(1, 7, 10)), FT.Gc[i])});
   FT.FunTest("Fmod(1.7,x)", -10000.f, 10000.f, [&](int N)->void {GMYFun(fmodf(1.7f,FT.fa[i]), FT.fc[i])},  [&](int N)->void {GMYFun(fmodf(1.7,FT.da[i]), FT.dc[i])}, [&](int N)->void { GMYFun(GFloat::Fmod(GFloat(1, 7, 10), FT.Ga[i] ), FT.Gc[i])});

}


