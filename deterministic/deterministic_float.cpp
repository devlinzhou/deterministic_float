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
	#endif

#else
		
#endif

		return 0;
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
		char str[26];
		ctime_s(str, sizeof str, &TNow);
		
		Tstring << "# GFloat Test And BenchMark" << std::endl;
		Tstring << " * Test time : "<< str  << std::endl;


		Tstring << "|Operation System| C++ Compiler version |CPU  | Base Frequency  |" <<std::endl;
		Tstring << "|--|--|--|--|" << std::endl;
		Tstring << "|" << 
			getOsName() << "|" <<
			GetCompileName() << std::setprecision(3) << "|" <<
			GetCpuName() << "|" <<
			MYTimer::GetCpuFrequency_Compute() / 1000000.f << " GHz or " <<" " <<
			MYTimer::GetCpuFrequency_CpuInfo() / 1000.f <<" GHz " << "|"<< std::endl;
		
		
		Tstring << " * Math: float vs GFloat,  Call " << N << " times" << std::endl;
		Tstring << " * Error is the relative of camth result " << std::endl << std::endl;

		Tstring << "|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|"<< std::endl;
		Tstring << "|--|--|--|--|--|--|--|" << std::endl;

		std::cout << Tstring.str();

		m_string << Tstring.str();
	}

	inline void FunTest( std::string name, float RMin, float RMax, std::function<float(int i)> fun_f,std::function<GFloat(int i)> fun_G, bool bRelative = true )
	{
		std::minstd_rand gen;
		std::uniform_real_distribution<> dis(RMin, RMax);

		for (int i = 0; i < N; i++) {
			fa[i] = (float)dis(gen);
			fb[i] = (float)dis(gen);
			fc[i] = 1.f;

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

		Count(name, bRelative);
	}

	void Count(std::string Name, bool bRelative)
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

			if (abs(cf1) < 0.00001f)
				continue;

			float cf2 = (Gc[i].toFloat());
			if (isinf(cf2) || isnan(cf2))
			{
				std::cout << "isinf(cf2) || isnan(cf2)   " << i << std::endl;
			}

			float cAbs = abs((cf2 - cf1) / (bRelative ? cf1 : 1.f) );

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

		float avgerror = totalabs  / nCount;

		std::stringstream Tstring;
		std::cout.precision(3);

		Tstring << "|" << Name << "|" << std::setiosflags(std::ios::fixed) << std::setprecision(6) << avgerror * 100.f << " %|" << Maxabs * 100.f << " %|";
		Tstring << std::setprecision(2) << time1 << " - " << time2 << "  (ms) |" << time1 / time2 << "|";
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
	
	bool bBase = 1;
	bool bTrigonometric = 1;
	bool bTranscendental = 1;


	//FT.FindBest(0.f, 10000.f);

	if( bBase )
	{
		FT.FunTest("Add",		-10000.f,  10000.f,  [&](int i)->float {return FT.fa[i] + FT.fb[i]; }, [&](int i)->GFloat {return FT.Ga[i] + FT.Gb[i]; });
		FT.FunTest("Sub",		-10000.f,  10000.f,  [&](int i)->float {return FT.fa[i] - FT.fb[i]; }, [&](int i)->GFloat {return FT.Ga[i] - FT.Gb[i]; });
		FT.FunTest("Mul",		-10000.f,  10000.f,  [&](int i)->float {return FT.fa[i] * FT.fb[i]; }, [&](int i)->GFloat {return FT.Ga[i] * FT.Gb[i]; });
		FT.FunTest("Div",		-10000.f,  10000.f,  [&](int i)->float {return FT.fa[i] / FT.fb[i]; }, [&](int i)->GFloat {return FT.Ga[i] / FT.Gb[i]; });
		FT.FunTest("Ceil",		-100000.f, 100000.f, [&](int i)->float {return ceilf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Ceil(FT.Ga[i]); });
		FT.FunTest("Floor",		-100000.f, 100000.f, [&](int i)->float {return floorf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Floor(FT.Ga[i]); });
		FT.FunTest("Whole",		-100000.f, 100000.f, [&](int i)->float {return (float)((int)(FT.fa[i])); }, [&](int i)->GFloat { return GFloat(FT.Ga[i].GetWhole()); });
		FT.FunTest("WholeFrac", -100000.f, 100000.f, [&](int i)->float {return (float)(FT.fa[i]); }, [&](int i)->GFloat { GFloat f; return GFloat(FT.Ga[i].GetWhole(f)) + f; });
		FT.FunTest("FromInt",	-100000.f, 100000.f, [&](int i)->float {return (float)((int)(FT.fa[i])); }, [&](int i)->GFloat { return GFloat((int)(FT.fa[i])); });
		FT.FunTest("operator <", -10000.f, 10000.f, [&](int i)->float {return FT.fa[i] < FT.fb[i] ? FT.fa[i] : FT.fb[i]; }, [&](int i)->GFloat {return FT.Ga[i] < FT.Gb[i] ? FT.Ga[i] : FT.Gb[i]; });
		FT.FunTest("operator -", -10000.f, 10000.f, [&](int i)->float {return -FT.fa[i]; }, [&](int i)->GFloat {return -FT.Ga[i]; });
	}

	if(bTrigonometric)
	{
		 FT.FunTest("Sin", -10000.f, 10000.f, [&](int i)->float {return sinf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Sin(FT.Ga[i]); });
		 FT.FunTest("Cos", -10000.f, 10000.f, [&](int i)->float {return cosf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Cos(FT.Ga[i]); });
		 FT.FunTest("SinCos", -10000.f, 10000.f, [&](int i)->float {return sinf(FT.fa[i]) + cosf(FT.fa[i]); }, [&](int i)->GFloat {GFloat fs, fc;  GFloat::SinCos(FT.Ga[i], fs, fc); return fs + fc; });
		 FT.FunTest("Tan", -1.57f, 1.57, [&](int i)->float {return tanf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Tan(FT.Ga[i]); });
		 FT.FunTest("ASin", -1.f, 1.f, [&](int i)->float {return asinf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::ASin(FT.Ga[i]); });
		FT.FunTest("ACos", -1.f, 1.f, [&](int i)->float {return acosf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::ACos(FT.Ga[i]); });
		 FT.FunTest("ATan", -10000.f, 10000.f, [&](int i)->float {return atanf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::ATan(FT.Ga[i]); });
		 FT.FunTest("ATan(10,x)", -10000.f, 10000.f, [&](int i)->float {return atan2f(10.f, FT.fa[i]); }, [&](int i)->GFloat {return GFloat::ATan2(GFloat(10), FT.Ga[i]); });
		 FT.FunTest("ATan(x,10)", -10000.f, 10000.f, [&](int i)->float {return atan2f(FT.fa[i], 10.f); }, [&](int i)->GFloat {return GFloat::ATan2(FT.Ga[i], GFloat(10)); });
	}

	if( bTranscendental )
	{
		FT.FunTest("Sqrt", 0, 10000.f, [&](int i)->float {return sqrtf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Sqrt(FT.Ga[i]); });	
		FT.FunTest("invSqrt", 0, 10000.f, [&](int i)->float {return 1.f / sqrtf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::InvSqrt(FT.Ga[i]); });
		FT.FunTest("Exp", -20.f, 20.f, [&](int i)->float {return expf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Exp(FT.Ga[i]); });
		FT.FunTest("Log", 0.f, 10000.f, [&](int i)->float {return logf(FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Log(FT.Ga[i]); });
		FT.FunTest("Pow(2,x)", -20.f, 20.f, [&](int i)->float {return powf(2.f, FT.fa[i]); }, [&](int i)->GFloat {return GFloat::Pow(GFloat::Two(), FT.Ga[i]); });
		FT.FunTest("Pow(x,2)", 0.55f, 20.f, [&](int i)->float {return powf(FT.fa[i], 2.f); }, [&](int i)->GFloat {return GFloat::Pow(FT.Ga[i], GFloat::Two()); });
	}
	//	std::cout << "Pi_TwoInv()  " << std::hex << GFloat::Pi_TwoInv().rawint32 << "  " << GFloat::Pi_TwoInv().toFloat() << "\n";
}


