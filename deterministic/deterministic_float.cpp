/* 
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
#include <iostream>
#include <chrono>
#include <vector>
#include <initializer_list>
#include <random>
#include <functional>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <array>
#include <thread>
#include <cstdlib>

#ifdef _MSC_VER
#include <intrin.h>
#endif

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#define __PRINT_MARCO(x) #x
#define PRINT_MARCO(x) #x"=" __PRINT_MARCO(x)

#if defined(_MSC_VER) || (defined(__GNUC__))
#define UseProfiler_RDTSCP 1
#endif

#pragma message(PRINT_MARCO(UseProfiler_RDTSCP))
#pragma message(PRINT_MARCO(__ARM_ARCH))


std::string getOsName()
{
#if defined(_WIN32) && !defined(_WIN64)
	return "Windows 32-bit";
#elif _WIN64
	return "Windows 64-bit";
#elif __APPLE__ || __MACH__
	#if TARGET_OS_MAC
		return "Mac OSX";
	#elif TARGET_OS_IPHONE
		return "iOS";
	#elif TARGET_IPHONE_SIMULATOR
		return "iOS Simulator";
	#else
		return "Unkown Apple device";
	#endif
#elif __linux__
	return "Linux";
#elif __FreeBSD__
	return "FreeBSD";
#elif __unix || __unix__
	return "Unix";
#elif __ANDROID__
	return "Android";
#else
	return "Other";
#endif
}

typedef std::chrono::high_resolution_clock Myclock;
typedef std::chrono::nanoseconds Myres;

class  MYTimer
{
public:
	MYTimer()
#if UseProfiler_RDTSCP
		: start_(0), end_(0)
#else
		: t1(Myres::zero()), t2(Myres::zero())
#endif
	{
		Start();
	}

	~MYTimer()
	{}

	static inline uint64_t get_CPUCycles()
	{
#ifdef _MSC_VER
		return __rdtsc();
#elif __GNUC__	

	#ifdef defined(__x86_64__)
		unsigned int lo, hi;
		__asm__ __volatile__("rdtsc" : "=a" (lo), "=d" (hi));
		return ((uint64_t)hi << 32) | lo;
	#elif defined(__aarch64__)

		uint64_t virtual_timer_value;
		asm volatile("mrs %0, cntvct_el0" : "=r"(virtual_timer_value));
		return virtual_timer_value;

	#else
		return 0;
	#endif

#else
		return 0;
#endif
	}

	void Start()
	{
#if UseProfiler_RDTSCP
		start_ = get_CPUCycles();
#else
		t1 = Myclock::now();
#endif    
	}

	void End()
	{
#if UseProfiler_RDTSCP
		end_ = get_CPUCycles();
#else
		t2 = Myclock::now();
#endif
	}


	float GetDeltaTimeMS_NoEnd()
	{
#if UseProfiler_RDTSCP
		return float( double(end_ - start_) * InvCPUGHZ);
#else
		return float(std::chrono::duration_cast<Myres>(t2 - t1).count() * 1e-6);
#endif
	}

	float GetDeltaTimeMS()
	{
		End();
		return GetDeltaTimeMS_NoEnd();
	}

	static double GetCpuFrequency_Compute()
	{
#if UseProfiler_RDTSCP
		return 1 / InvCPUGHZ;
#else
		return 0;
#endif
	}

	static int GetCpuFrequency_CpuInfo()
	{
		int cpuInfo[4] = { 0, 0, 0, 0 };
#ifdef _MSC_VER
		__cpuid(cpuInfo, 0);
		if (cpuInfo[0] >= 0x16) {
			__cpuid(cpuInfo, 0x16);
			return cpuInfo[0];
		}
#elif __GNUC__

	#ifdef defined(__x86_64__) && !defined(__aarch64__)

		__get_cpuid(0, cpuInfo + 0, cpuInfo + 1, cpuInfo + 2, cpuInfo + 3);

		if (cpuInfo[0] >= 0x16) {
			__get_cpuid(0x16, cpuInfo + 0, cpuInfo + 1, cpuInfo + 2, cpuInfo + 3);
			return cpuInfo[0];
		}
	#elif defined(__ARM_ARCH)

        uint64_t freq;
        asm volatile("mrs %0, cntfrq_el0" : "=r" (freq));
        return (int)(freq / 1000000);

	#endif

#else
		
#endif

		return 0;
	}

private:


#if UseProfiler_RDTSCP

	static double InvCPUGHZ;
	volatile uint64_t start_;
	volatile uint64_t end_;
#else
	Myclock::time_point t1;
	Myclock::time_point t2;
#endif

};

#if UseProfiler_RDTSCP

static double CountCpuGhz() {

	Myclock::time_point tStart = Myclock::now();;
	uint64_t uStart = MYTimer::get_CPUCycles();
		
	std::this_thread::sleep_for(std::chrono::milliseconds(10));

	uint64_t uEnd = MYTimer::get_CPUCycles();
	Myclock::time_point tEnd = Myclock::now();

	double time = double(std::chrono::duration_cast<Myres>(tEnd - tStart).count() * 1e-9);

	double CpuGhz = double(uEnd - uStart) / (time * 1000000000);
	return CpuGhz;

}

double MYTimer::InvCPUGHZ = 0.000001f / CountCpuGhz();
#endif




std::string GetCpuName()
{
#if defined(_MSC_VER)
	std::array<int, 4> cpui;
	std::vector<std::array<int, 4>> extdata_;
	__cpuid(cpui.data(), 0x80000000);
	int nExIds_ = cpui[0];

	char brand[0x40];
	memset(brand, 0, sizeof(brand));

	for (int i = 0x80000000; i <= nExIds_; ++i)
	{
		__cpuidex(cpui.data(), i, 0);
		extdata_.push_back(cpui);
	}

	std::string brand_;

	// Interpret CPU brand string if reported
	if (nExIds_ >= 0x80000004)
	{
		memcpy(brand, extdata_[2].data(), sizeof(cpui));
		memcpy(brand + 16, extdata_[3].data(), sizeof(cpui));
		memcpy(brand + 32, extdata_[4].data(), sizeof(cpui));
		brand_ = brand;
	}

	return brand_;
#elif __APPLE__


#if __ARM_ARCH
	return "Apple Arm CPU";
#elif __x86_64__
	return "Apple Intel CPU";
#else
	return "Unkown Apple CPU";
#endif


#else
	return "Unkown CPU";
#endif
}

std::string GetCompileName()
{
#if defined(_MSC_VER)
	return "Visual Studio " + std::to_string(_MSC_VER);
#elif __GNUC__
	return __VERSION__;
#else
	return "Unkown Compile";
#endif
}



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
	MYTimer Timer;
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
		FileName = "../Test_BenchMark_Win";
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
#elif __OSX__ 
		FileName = "../Test_BenchMark_OSX.md";
#endif	
		m_string =  std::ofstream (FileName);

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
			getOsName() << "|" <<
			GetCompileName()  << std::setprecision(3) << "|" <<
			GetCpuName() << "|" <<
			MYTimer::GetCpuFrequency_Compute() / 1000000.f << " GHz or " <<" " <<
			MYTimer::GetCpuFrequency_CpuInfo() / 1000.f <<" GHz " << "|"<< std::endl;
		
		
		Tstring << " * Performance: float vs GFloat,  Call " << N << " times" << std::endl;
		Tstring << " * Error : the relative error between cmath (double) and GFloat Math " << std::endl << std::endl;

		Tstring << "|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|"<< std::endl;
		Tstring << "|--|--|--|--|--|--|--|" << std::endl;

		std::cout << Tstring.str();

		m_string << Tstring.str();
	}

inline void FunError( int NCount, bool bRelative, std::string name, float RMin, float RMax,
	std::function<double(int i)> fun_f,
	std::function<GFloat(int i)> fun_G)
{
	std::string CurrentType = bRelative ? "Relative" : "Absolute";

	std::ofstream fs("../GFloat_" + name + "_" + CurrentType + ".gp");

	fs << "set term svg size 640, 480" << std::endl;
	fs << "set output \"GFloat_" + name + "_" + CurrentType + ".svg\"" << std::endl;
	fs << R"gp(set format y "%g%%")gp" << std::endl;
	fs << "set title \"GFloat::" + name + "() " + CurrentType + " Error\"" << std::endl;
	fs << "unset key" << std::endl;
	fs << "plot \"-\" with points" << std::endl;

	fs << std::setprecision(std::numeric_limits<double>::digits10 + 1);

	std::minstd_rand gen;
	std::uniform_real_distribution<> dis(RMin, RMax);

	int TN = NCount <= N ? NCount : N;

	if (0)
	{
		TN = GFloat::ms_TriCount;
		for (int i = 0; i < TN; i++) {
			fa[i] = float(i) * 3.141592653f * 2 / GFloat::ms_TriCount;
			Ga[i] = GFloat::FromFloat(fa[i]);

			float fy = fa[i];
			GFloat Gy = Ga[i];
			float ferror = (Gy.toFloat() - fy) / abs(fy);
			fs << fa[i] << " " << ferror * 100.0 << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < TN; i++) {
			da[i] = dis(gen);
			Ga[i] = GFloat::FromFloat((float)da[i]);
		}

		for (int i = 0; i < TN; i++) {
			double fy = fun_f(i);

			//if (abs(fy) < 0.00000001f)
			//	continue;
			GFloat Gy = fun_G(i);

			double ferror = ( (Gy.toDouble() - fy )/( bRelative ? abs(fy): 1.) );

			fs << da[i] << " " << ferror * 100.0 << std::endl;

			//fs << da[i] << " " << fy  << std::endl;
			//fs << da[i] << " " << Gy.toDouble() << std::endl;
		}
	}

	fs << "EOF" << std::endl;
}

	inline void FunTest(
		std::string name,
		float RMin, float RMax,
		std::function<void(int N)> fun_f,
		std::function<void(int N)> fun_d,
		std::function<void(int N)> fun_G  )
	{
		std::minstd_rand gen;
		std::uniform_real_distribution<> dis(RMin, RMax);

		for (int i = 0; i < N; i++) {
			fa[i] = (float)dis(gen);
			fb[i] = (float)dis(gen);
			fc[i] = 1.f;
			da[i] = (double)fa[i];
			db[i] = (double)fb[i];
			dc[i] = 1.f;
			Ga[i] = GFloat::FromFloat(fa[i]);
			Gb[i] = GFloat::FromFloat(fb[i]);
			Gc[i] = GFloat(1);}

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


		Count(name );
	}

	void Count(std::string Name )
	{
		double f1 = 0;
		double f2 = 0;

		double Maxabs = 0;
		int maxi = 0;

		int nCount = 0;
		double totalabs = 0;

		for (int i = 0; i < N; i++)
		{
			double cf1 = (dc[i]);
			double cf2 = (Gc[i].toDouble());

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

			f1 += abs(cf1);
			f2 += abs(cf2);
		}

		double avgerror = totalabs  / nCount;

		std::stringstream Tstring;
		std::cout.precision(3);

        Tstring << "|" << std::setiosflags(std::ios::left)<< std::setw(10);
        Tstring << Name;
        Tstring << "|" << std::setiosflags(std::ios::right) << std::setw( 10) << std::setiosflags(std::ios::fixed) << std::setprecision(6) <<avgerror * 100.f << " %";
        Tstring << "|" << std::setiosflags(std::ios::right) << std::setw( 14) << Maxabs * 100.f << " %";
        Tstring << "|" << std::setiosflags(std::ios::right) << std::setw( 5) <<std::setprecision(2) << time1;
        Tstring <<" vs "<< std::setiosflags(std::ios::right) << std::setw( 5) << time2 << "  (ms)|" << time1 / time2 << "|";
		Tstring << (time1 < time2 ? "$\\checkmark$" : "") << "|" <<( time1 > time2 ? "$\\checkmark$" : "" ) << "|" << std::endl;
		std::cout << Tstring.str();

		m_string << Tstring.str();
	}

	int32_t FindBest( float RMin, float RMax)
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
		for( GFloat GStart = GFloat(0,8,10); GStart < GFloat(0,9,10); GStart += GFloat(0,1,1000))
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
			if( fMaxAbs > fabs)
			{
				BestStart = GStart;
				fMaxAbs = fabs;
			}
		}

		std::cout << "fMaxAbs   "  << fMaxAbs<< std::endl;
		std::cout << "Best GStart  " << BestStart.rawint32 << "  " << BestStart.toFloat() << std::endl;
		return BestStart.rawint32 ;
	}

};

void TestGFloat::Run()
{
	GFloatTest FT(1000000);

    bool bErrortest = 0;
    if (bErrortest)
    {
        float fstart = 1.580f;
        FT.FunError(1000, false, "ACos", -0.f, 0.95f, [&](int i)->double {return acos(FT.da[i]); }, [&](int i)->GFloat {return GFloat::ACos(FT.Ga[i]); });
        FT.FunError(1000, false, "ASin", -1.f, 1.f, [&](int i)->double {return asin(FT.da[i]); }, [&](int i)->GFloat {return GFloat::ASin(FT.Ga[i]); });
        //FT.FunError(1256, "Sin", -fstart, fstart, [&](int i)->float {return sinf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Sin(FT.Ga[i]); });
        return;
    }


	FT.FunTest("Add",	    -10000.f, 10000.f, [&](int N)->void { MYOperater(FT.fa, FT.fb, FT.fc, +)},  [&](int N)->void {MYOperater(FT.da, FT.db, FT.dc, +) }, [&](int N)-> void { MYOperater(FT.Ga, FT.Gb, FT.Gc, +) });
	FT.FunTest("Sub",	    -10000.f, 10000.f, [&](int N)->void { MYOperater(FT.fa, FT.fb, FT.fc, -)},  [&](int N)->void {MYOperater(FT.da, FT.db, FT.dc, -) }, [&](int N)-> void { MYOperater(FT.Ga, FT.Gb, FT.Gc, -) });
	FT.FunTest("Mul",	    -10000.f, 10000.f, [&](int N)->void { MYOperater(FT.fa, FT.fb, FT.fc, *)},  [&](int N)->void {MYOperater(FT.da, FT.db, FT.dc, *) }, [&](int N)-> void { MYOperater(FT.Ga, FT.Gb, FT.Gc, *) });
	FT.FunTest("Div",	    -10000.f, 10000.f, [&](int N)->void { MYOperater(FT.fa, FT.fb, FT.fc, /)},  [&](int N)->void {MYOperater(FT.da, FT.db, FT.dc, /) }, [&](int N)-> void { MYOperater(FT.Ga, FT.Gb, FT.Gc, /) });
	FT.FunTest("Ceil",		-10000.f, 10000.f, [&](int N)->void { MYOneFun(FT.fa, FT.fc, ceilf)},       [&](int N)->void {MYOneFun(FT.da, FT.dc, ceil) },       [&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::Ceil) });
	FT.FunTest("Floor",		-10000.f, 10000.f, [&](int N)->void { MYOneFun(FT.fa, FT.fc, floorf)},      [&](int N)->void {MYOneFun(FT.da, FT.dc, floor) },      [&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::Floor) });
	FT.FunTest("Whole",		-10000.f, 10000.f, [&](int N)->void { MYOneFun(FT.fa, FT.fc, (float)int)},  [&](int N)->void {MYOneFun(FT.da, FT.dc,(double)int ) },[&](int N)-> void { MYOneGetWhole(FT.Ga, FT.Gc, GetWhole) });
   // FT.FunTest("WholeFrac", -10000.f, 10000.f, [&](int N)->void { MYOneFun(FT.fa, FT.fc, (float))},     [&](int N)->void {MYOneFun(FT.da, FT.dc, (double)) },   [&](int N)-> void { MYOneFun((GFloat f, GFloat(FT.Ga[i].GetWhole(f)) + f), FT.Gc ) });
    FT.FunTest("Normalize", -10000.f, 10000.f, [&](int N)->void { MYOneFun(FT.fa, FT.fc, )},            [&](int N)->void {MYOneFun(FT.da, FT.dc, ) },           [&](int N)-> void { MYOneNormalize(FT.Ga, FT.Gc) });
    FT.FunTest("FromInt",   -10000.f, 10000.f, [&](int N)->void { MYOneFun(FT.fa, FT.fc, (float)int )}, [&](int N)->void {MYOneFun(FT.da, FT.dc,(double)int) }, [&](int N)-> void { MYOneFun((int)FT.fa, FT.Gc, GFloat) });
    FT.FunTest("-()",       -10000.f, 10000.f, [&](int N)->void { MYOneFun(FT.fa, FT.fc, -)},           [&](int N)->void {MYOneFun(FT.da, FT.dc, - ) },         [&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, -) });
    FT.FunTest("<",         -10000.f, 10000.f, [&](int N)->void { MYOperaterLess(FT.fa, FT.fb,FT.fc)},  [&](int N)->void {MYOperaterLess(FT.da, FT.db, FT.dc) },[&](int N)-> void { MYOperaterLess(FT.Ga, FT.Gb,FT.Gc) });



	FT.FunTest("Sin",	-10000.f, 10000.f,  [&](int N)->void { MYOneFun(FT.fa, FT.fc, sinf)},       [&](int N)->void {MYOneFun(FT.da, FT.dc, sin) },    [&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::Sin) });
	FT.FunTest("Cos",	-10000.f, 10000.f,  [&](int N)->void { MYOneFun(FT.fa, FT.fc, cosf)},       [&](int N)->void {MYOneFun(FT.da, FT.dc, cos) },    [&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::Cos) });
	FT.FunTest("Tan",	-10000.f, 10000.f,  [&](int N)->void { MYOneFun(FT.fa, FT.fc, tanf)},       [&](int N)->void {MYOneFun(FT.da, FT.dc, tan) },    [&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::Tan) });
	FT.FunTest("ASin",	-1.f, 1.f,          [&](int N)->void { MYOneFun(FT.fa, FT.fc, asinf)},      [&](int N)->void {MYOneFun(FT.da, FT.dc, asin) },   [&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::ASin) });
	FT.FunTest("ACos",	-1.f, 1.f,          [&](int N)->void { MYOneFun(FT.fa, FT.fc, acosf)},      [&](int N)->void {MYOneFun(FT.da, FT.dc, acos) },   [&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::ACos) });

	FT.FunTest("Sqrt",		0.f, 10000.f,	[&](int N)->void { MYOneFun(FT.fa, FT.fc, sqrtf)},		[&](int N)->void {MYOneFun(FT.da, FT.dc, sqrt) },	[&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::Sqrt) });
	FT.FunTest("InvSqrt",	0.f, 10000.f,	[&](int N)->void { MYOneFun(FT.fa, FT.fc,1.f/sqrtf)},	[&](int N)->void {MYOneFun(FT.da, FT.dc,1./sqrt) }, [&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::InvSqrt) });
	FT.FunTest("Exp",		-20.f, 20.f,	[&](int N)->void { MYOneFun(FT.fa, FT.fc, expf)},		[&](int N)->void {MYOneFun(FT.da, FT.dc, exp) },	[&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::Exp) });
	FT.FunTest("Log",		0.f, 10000.f,	[&](int N)->void { MYOneFun(FT.fa, FT.fc, logf)},		[&](int N)->void {MYOneFun(FT.da, FT.dc, log) },	[&](int N)-> void { MYOneFun(FT.Ga, FT.Gc, GFloat::Log) });
}


