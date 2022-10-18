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
#pragma once

#include <cstdlib>
#include <string>
#include <chrono>
#include <iostream>
#include <sstream>
#include <fstream>
#include <array>
#include <vector>

#ifdef _MSC_VER
#include <intrin.h>
#endif

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#ifdef __ANDROID__
#include <android/log.h>
#endif

#if defined(_MSC_VER) || (defined(__GNUC__))
#define UseProfiler_RDTSCP 1
#endif


#define __PRINT_MARCO(x) #x
#define PRINT_MARCO(x) #x"=" __PRINT_MARCO(x)

#pragma message(PRINT_MARCO(UseProfiler_RDTSCP))
#pragma message(PRINT_MARCO(__ARM_ARCH))


std::string getOSName()
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
#elif __ANDROID__
    return "Android";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#elif __unix || __unix__
    return "Unix";
#else
    return "Other";
#endif
}


std::string GetCompileName()
{
#if defined(_MSC_VER)
    return "Visual Studio :" + std::to_string(_MSC_VER);
#elif __GNUC__
    return __VERSION__;
#else
    return "Unkown Compile";
#endif
}

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

typedef std::chrono::high_resolution_clock Myclock;
typedef std::chrono::nanoseconds Myres;

class  GTimer
{
public:
    GTimer()
#if UseProfiler_RDTSCP
        : start_(0), end_(0)
#else
        : t1(Myres::zero()), t2(Myres::zero())
#endif
    {
        Start();
    }

    ~GTimer()
    {}

    static inline uint64_t get_CPUCycles()
    {
#ifdef _MSC_VER
        return __rdtsc();
#elif __GNUC__    

#if defined(__x86_64__)

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
        return float(double(end_ - start_) * InvCPUGHZ);
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

#if defined(__GNUC__) && defined(__x86_64__) && !defined(__aarch64__)
#include <cpuid.h>
#endif

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

#if defined(__x86_64__) && !defined(__aarch64__)

        __cpuid(0, cpuInfo[0], cpuInfo[1], cpuInfo[2], cpuInfo[3]);

        if (cpuInfo[0] >= 0x16) {
            __cpuid(0x16, cpuInfo[0], cpuInfo[1], cpuInfo[2], cpuInfo[3]);
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

void GPrintLog( const std::stringstream& STR )
{
#if __ANDROID__

    __android_log_print(ANDROID_LOG_INFO, "GFloat", "%s", STR.str().c_str());

#else

    std::cout << STR.str();

#endif
}



