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

#include "glacier_float.h"
#include <iostream>
#include <chrono>
#include <intrin.h>
#include <vector>
#include <initializer_list>
#include <random>
#include <functional>
#include <sstream>
#include <fstream>
#include <iomanip>
#define UseProfiler_RDTSCP 1

class  MYTimer
{
public:
	MYTimer()
#if UseProfiler_RDTSCP
		: start_(0), end_(0)
#else
		: t1(res::zero()), t2(res::zero())
#endif
	{
		Start();
	}

	~MYTimer()
	{}

	void Start()
	{
#if UseProfiler_RDTSCP
		start_ = __rdtsc();
#else
		t1 = clock::now();
#endif    
	}

	void End()
	{
#if UseProfiler_RDTSCP
		end_ = __rdtsc();
#else
		t2 = clock::now();
#endif
	}


	float GetDeltaTimeMS_NoEnd()
	{
#if UseProfiler_RDTSCP
		return(float)( double(end_ - start_) * InvCPUGHZ);
#else
		return std::chrono::duration_cast<res>(t2 - t1).count() * 1e-6;
#endif
	}

	float GetDeltaTimeMS()
	{
		End();
		return GetDeltaTimeMS_NoEnd();
	}

private:
	typedef std::chrono::high_resolution_clock clock;
	typedef std::chrono::nanoseconds res;

#if UseProfiler_RDTSCP

	static double InvCPUGHZ;
	volatile unsigned __int64 start_;
	volatile unsigned __int64 end_;
#else
	clock::time_point t1;
	clock::time_point t2;
#endif

};

#if UseProfiler_RDTSCP

static double CountCpuGhz() {
	unsigned long long frequency = _Query_perf_frequency();
	unsigned int a;

	unsigned long long CounterStart = _Query_perf_counter();
	unsigned __int64 ss = __rdtscp(&a);
	int aa = 0;
	for (int i = 1; i < 1000; i++) {
		aa += i;
	}
	unsigned long long CounterEnd = _Query_perf_counter();
	unsigned __int64 ss2 = __rdtscp(&a);

	double time = double(CounterEnd - CounterStart) / frequency;
	if (aa != 0)
	{
		double CpuGhz = double(ss2 - ss) / (time * 1000000000);
		return CpuGhz;
	}

	return 0.0;
}

double MYTimer::InvCPUGHZ = 0.000001f / CountCpuGhz();
#endif

class GFloatTest
{
public:
	std::vector<float>  fa;
	std::vector<float>  fb;
	std::vector<float>  fc;
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
		N = TN;
		fa.resize(N);
		fb.resize(N);
		fc.resize(N);
		Ga.resize(N);
		Gb.resize(N);
		Gc.resize(N);

		m_string =  std::ofstream ( "../TestAndBenchMark.md" );
		m_string << "### Call Function: cmath vs GFloat math" << N << "Times " << std::endl;
		m_string << "|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|"<< std::endl;
		m_string << "|--|--|--|--|--|--|--|" << std::endl;
	}

	inline void FunTest( std::string name, float RMin, float RMax, std::function<float(int i)> fun_f,std::function<GFloat(int i)> fun_G  )
	{
		std::minstd_rand gen;
		std::uniform_real_distribution<> dis(RMin, RMax);

		for (int i = 0; i < N; i++) {
			fa[i] = (float)dis(gen);
			fb[i] = (float)dis(gen);
			fc[i] = 0;

			Ga[i] = GFloat::FromFloat(fa[i]);
			Gb[i] = GFloat::FromFloat(fb[i]);
			Gc[i] = GFloat(0);}

		Timer.Start();
		for (int i = 0; i < N; i++) {
			fc[i] = fun_f(i);
		}
		time1 = Timer.GetDeltaTimeMS();

		Timer.Start();
		for (int i = 0; i < N; i++) {
			Gc[i] = fun_G( i);
		}
		time2 = Timer.GetDeltaTimeMS();

		Count(name);
	}

	void Count(std::string Name)
	{
		float f1 = 0;
		float f2 = 0;

		float Maxabs = 0;
		int maxi = 0;

		int nCount = 0;
		float totalabs = 0;

		for (int i = 0; i < N; i++)
		{
			float cf1 = (fc[i]);

			if (abs(cf1) < 0.0001f)
				continue;

			float cf2 = (Gc[i].toFloat());
			if (isinf(cf2))
			{
				int a = 0;
			}

			float cAbs = abs((cf2 - cf1) / cf1);

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

		//float avgerror = abs(f2 - f1) * 100.f / abs(f1);
		float avgerror = totalabs  / nCount;


		std::stringstream Tstring;

		std::cout.precision(3);

		Tstring << "|" << Name << "|" << setiosflags(std::ios::fixed) << std::setprecision(6) << avgerror * 100.f << " %|" << Maxabs * 100.f << " %|";
		Tstring << std::setprecision(2) << time1 << " - " << time2 << "  (ms) |" << time1 / time2 << "|";
		Tstring << (time1 < time2 ? "$\\checkmark$" : "") << "|" <<( time1 > time2 ? "$\\checkmark$" : "" ) << "|" << std::endl;
		std::cout << Tstring.str();

		m_string << Tstring.str();
	}

};


int main()
{
	GFloatTest FT(1000000);
	
	bool bBase = false;
	bool bTrigonometric = true;
	bool bTranscendental = false;

	if( bBase )
	{
		FT.FunTest("Add", -10000.f, 10000.f, [&](int i)->float {return FT.fa[i] + FT.fb[i]; }, [&](int i)->GFloat {return FT.Ga[i] + FT.Gb[i]; });
		FT.FunTest("Sub", -10000.f, 10000.f, [&](int i)->float {return FT.fa[i] - FT.fb[i]; }, [&](int i)->GFloat {return FT.Ga[i] - FT.Gb[i]; });
		FT.FunTest("Mul", -10000.f, 10000.f, [&](int i)->float {return FT.fa[i] * FT.fb[i]; }, [&](int i)->GFloat {return FT.Ga[i] * FT.Gb[i]; });
		FT.FunTest("Div", -10000.f, 10000.f, [&](int i)->float {return FT.fa[i] / FT.fb[i]; }, [&](int i)->GFloat {return FT.Ga[i] / FT.Gb[i]; });
		FT.FunTest("Ceil", -100000.f, 100000.f, [&](int i)->float {return ceilf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Ceil(FT.Ga[i]); });
		FT.FunTest("Floor", -100000.f, 100000.f, [&](int i)->float {return floorf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Floor(FT.Ga[i]); });
		FT.FunTest("Whole", -100000.f, 100000.f, [&](int i)->float {return (float)(FT.fa[i]); }, [&](int i)->GFloat { GFloat f; return GFloat(FT.Ga[i].GetWhole(f)) + f; });
	}

	if(bTrigonometric)
	{
		FT.FunTest("Sin", 0, 3.14f, [&](int i)->float {return sinf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Sin(FT.Ga[i]); });
		/*FT.FunTest("Cos", -10000.f, 10000.f, [&](int i)->float {return cosf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Cos(FT.Ga[i]); });
		FT.FunTest("Tan", -10000.f, 10000.f, [&](int i)->float {return tanf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Tan(FT.Ga[i]); });
		FT.FunTest("ASin", -1.f, 1.f, [&](int i)->float {return asinf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::ASin(FT.Ga[i]); });
		FT.FunTest("ACos", -1.f, 1.f, [&](int i)->float {return acosf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::ACos(FT.Ga[i]); });
		FT.FunTest("ATan", -10000.f, 10000.f, [&](int i)->float {return atanf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::ATan(FT.Ga[i]); });
		FT.FunTest("ATan(10,x)", -10000.f, 10000.f, [&](int i)->float {return atan2f(10.f, FT.fa[i]); }, [&](int i)->GFloat {return GFloat::ATan2(GFloat(10), FT.Ga[i]); });
		FT.FunTest("ATan(x,10)", -10000.f, 10000.f, [&](int i)->float {return atan2f(FT.fa[i], 10.f); }, [&](int i)->GFloat {return GFloat::ATan2(FT.Ga[i], GFloat(10)); });
	*/
	}

	if( bTranscendental )
	{
		FT.FunTest("Sqrt", 0, 10000.f, [&](int i)->float {return sqrtf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Sqrt(FT.Ga[i]); });	
		FT.FunTest("invSqrt", 0, 10000.f, [&](int i)->float {return 1.f / sqrtf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::InvSqrt(FT.Ga[i]); });
		FT.FunTest("Exp", -20.f, 20.f, [&](int i)->float {return expf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Exp(FT.Ga[i]); });
		FT.FunTest("Log", 0.f, 100000.f, [&](int i)->float {return logf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Log(FT.Ga[i]); });
		FT.FunTest("Pow(2,x)", -20.f, 20.f, [&](int i)->float {return powf(2.f, FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Pow(GFloat::Two(), FT.Ga[i]); });
		FT.FunTest("Pow(x,2)", 0.55f, 20.f, [&](int i)->float {return powf(FT.fa[i], 2.f); }, [&](int i)->GFloat {return GFloat::Pow(FT.Ga[i], GFloat::Two()); });
	}


	std::cout << "Pi()      " << GFloat::Pi().toDouble() << "\n";
	std::cout << "Pi_Half() " << GFloat::Pi_Half().toDouble() << "\n";
	std::cout << "Pi_Two()  " << GFloat::Pi_Two().toDouble() << "\n";
	std::cout << "Pi_Inv()  " << GFloat::Pi_Inv().toDouble() << "\n";


	/*std::cout << "Pi()      " << std::hex << GFloat::Pi().rawint32		<<"  "<< GFloat::Pi().toFloat() <<"\n";
	std::cout << "Pi_Half() " << std::hex << GFloat::Pi_Half().rawint32 <<"  "<< GFloat::Pi_Half().toFloat() << "\n";
	std::cout << "Pi_Two()  " << std::hex << GFloat::Pi_Two().rawint32	<<"  "<< GFloat::Pi_Two().toFloat() << "\n";
	std::cout << "Pi_Inv()  " << std::hex << GFloat::Pi_Inv().rawint32 << "  " << GFloat::Pi_Inv().toFloat() << "\n";

	std::cout << "Zero()    " << std::hex << GFloat::Zero().rawint32 << "\n";
	std::cout << "One()     " << std::hex << GFloat::One().rawint32 << "\n";
	std::cout << "Half()    " << std::hex << GFloat::Half().rawint32 << "\n";
	std::cout << "Two()     " << std::hex << GFloat::Two().rawint32 << "\n";*/

}


