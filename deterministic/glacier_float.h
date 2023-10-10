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

#include <stdint.h>
#include <cmath>


/**
 * Uncomment the below when you want use GFloat in an union. 
 * Take in mind that the default value will not guaranteed to be Zero anymore!
*/
// #define GLACIER_UNION_COMPATIBLE //Fixes compilation error in an union

// #define GLACIER_MULTIPLY_NORAMLIZE_FAST


#ifndef GLACIER_MULTIPLY_NORAMLIZE_FAST
//#define GLACIER_NORMALIZE_TEST
#endif

#if  defined( GLACIER_OVERFLOW_TEST) || defined( GLACIER_NORMALIZE_TEST)
#include <iostream>
#include <iomanip>
#endif


#ifdef _MSC_VER
#include <intrin.h>
#include <immintrin.h>
#endif

class GFloat // Get Glacier first char "G" for Name
{
public:
    static inline constexpr GFloat Zero()       { return GFloat(0x000000, 0x00); };
    static inline constexpr GFloat Half()       { return GFloat(0x400000, 0x68); };
    static inline constexpr GFloat One()        { return GFloat(0x400000, 0x69); };
    static inline constexpr GFloat Two()        { return GFloat(0x400000, 0x6A); };
    static inline constexpr GFloat Three()      { return GFloat(0x600000, 0x6A); };
    static inline constexpr GFloat Four()       { return GFloat(0x400000, 0x6B); };
    static inline constexpr GFloat Pi()         { return GFloat(0x6487ef, 0x6a); };//Float(3,141592654, 1000000000); 
    static inline constexpr GFloat Pi_Half()    { return GFloat(0x6487ef, 0x69); };
    static inline constexpr GFloat Pi_Quarter() { return GFloat(0x6487ef, 0x68); };
    static inline constexpr GFloat Pi_Two()     { return GFloat(0x6487ef, 0x6b); };
    static inline constexpr GFloat Pi_Inv()     { return GFloat(0x517cc1, 0x67); };
    static inline constexpr GFloat Pi_TwoInv()  { return GFloat(0x517cc1, 0x66); };
    static inline constexpr GFloat e()          { return GFloat(0x56fc2a, 0x6a); };
    static inline constexpr GFloat e_Inv()      { return GFloat(0x5e2d58, 0x67); };
    static inline constexpr GFloat e_Div_2()    { return GFloat(0x5c551d, 0x69); };
    static inline constexpr GFloat Epsilon()    { return GFloat(0x400000, 0x57); };

    static inline constexpr GFloat Inv_10()     { return GFloat(0x666666, 0x65); };
    static inline constexpr GFloat Inv_100()    { return GFloat(0x51eb85, 0x62); };
    static inline constexpr GFloat Inv_1000()   { return GFloat(0x418937, 0x5f); };
    static inline constexpr GFloat Inv_10000()  { return GFloat(0x68db8b, 0x5b); };
    static inline constexpr GFloat Inv_100000() { return GFloat(0x53e2d6, 0x58); };
    static inline constexpr GFloat Inv_1000000(){ return GFloat(0x431bde, 0x55); };



    static inline uint32_t GBitScanReverse64( uint64_t num)
    {
#ifdef _MSC_VER
        unsigned long Index;
        _BitScanReverse64(&Index, num);
        return Index;
#elif __GNUC__
        auto nCount = __builtin_clzll(num);
        return  nCount == 64 ? 0 : 63 - nCount;
#else
        for( int32_t nIndex = 63; nIndex >= 0; nIndex-- )
        {
            if (((uint64_t)1 << nIndex) & num)
            {
                return nIndex;
            }
        }
        return 0;
#endif
    }

    static inline uint32_t GBitScanReverse32(uint32_t num)
    {
#ifdef _MSC_VER
        unsigned long Index;
        _BitScanReverse(&Index, num);
        return Index;
#elif __GNUC__
        auto nCount = __builtin_clz(num);
        return  nCount == 32 ? 0 : 31 - nCount;
#else
        for (int32_t nIndex = 31; nIndex >= 0; nIndex--)
        {
            if (((uint64_t)1 << nIndex) & num)
            {
                return nIndex;
            }
        }
        return 0;
#endif
    }

public:
    int32_t rawint32;

public:

    static void Init();

#ifdef GLACIER_UNION_COMPATIBLE
    inline GFloat()=default;
#else
    constexpr GFloat(const GFloat&) = default;

    constexpr GFloat() : rawint32(0)
    {

    }
#endif

    explicit inline GFloat( int32_t TValue)
    {
        *this= Normalize32((int32_t)TValue, 127);
    }

    constexpr GFloat(int32_t Traw32, int32_t exp ) :
        rawint32((Traw32 << 8) | int32_t(exp & 0x000000FF))
    {
#if 0

        if( exp < 0 || exp > 0x000000FF )
        {
            std::cout << __func__ << "( Traw32 : " << Traw32 <<" , exp : " << exp 
                <<" ) , exp[0,255] exp has overflow!" <<std::endl;
        }
#endif

#ifdef GLACIER_NORMALIZE_TEST

         if ((Traw32 > 0 && (Traw32 < 0x00400000 || Traw32 > 0x007FFFFF)) ||
             (Traw32 < 0 && (Traw32 < (int32_t)0xFF800000 || Traw32 > (int32_t)0xFFC00000)))
         {
             std::cout << __func__ << "( Raw : " <<std::hex << std::showbase <<std::setw(10)<< Traw32 << ", exp : " << std::dec<<exp
                 << " )  is Not Normalized!" << std::endl;
         }
#endif
    }

    explicit inline GFloat(uint32_t Traw32, uint32_t a, uint32_t b)
    {
        int64_t TValue = (int64_t)b * (int64_t)Traw32 + (int64_t)a;

        int32_t index = GBitScanReverse64( (uint64_t)std::abs(TValue));

        int32_t exp = 62 - index;

        int64_t TRawn = (TValue << exp ) / b;

        *this = Normalize64(TRawn, 127 - exp);
    }

//     explicit inline GFloat(float value ) dont use this
//     {
//         FromFloat(value);
//     }

    inline constexpr int32_t getfraction() const
    {
       return rawint32 >> 8 ;
    }
    inline constexpr int32_t getfraction_NoShift() const
    {
        return int32_t(rawint32 & 0xFFFFFF00);
    }

    inline constexpr int32_t getfraction(int32_t shift) const
    {
        return getfraction() >> ( shift);
    }

    inline constexpr int32_t getexponent() const
    {
        return (rawint32 & 0xFF);
    }

    static inline constexpr GFloat FromRaw32(int32_t Traw32)
    {
        GFloat T {0};
        T.rawint32 = Traw32;
        return T;
    }

    static inline constexpr GFloat FromFractionAndExp(int32_t Traw32, int32_t exp)
    {
        if (exp < 0)
        {
            return GFloat::Zero();
        }
        exp = exp > 255 ? 255 : exp;

        return GFloat(Traw32, exp);
    }

    static inline GFloat FromFloat(float f)
    {
        if (f == 0.f || f == -0.f)
            return Zero();

        int32_t T754Rawint32    = *(int32_t*)&f;
        int32_t TRraction       = (int32_t)(T754Rawint32 & 0x007FFFFF) + 0x00800000;
        int32_t exponent        = ((T754Rawint32 & 0x7FFFFFFF) >> 23 );

        if (T754Rawint32 < 0)
            TRraction = -TRraction;

        //return Normalize(TRraction >> 1,exponent - 22);
        return GFloat::FromFractionAndExp(TRraction >> 1,exponent - 22);
    }

    double toDouble() const
    {
        int32_t Texponent = getexponent() - 127;
        double dT = pow(2, Texponent);
        double dResult = getfraction() * dT;

        return (dResult);
    }

    float toFloat() const
    {
       return (float)toDouble();
    }

    static inline GFloat Normalize32(int32_t Trawvalue, int32_t Texponent)
    {
        if (Trawvalue == 0)
            return GFloat(0, 0);

        int32_t index = GBitScanReverse32(std::abs(Trawvalue));

        if (index <= 22)
        {
            int32_t uDelta = 22 - index;
            return GFloat::FromFractionAndExp(Trawvalue << uDelta, Texponent - uDelta);
        }
        else
        {
            int32_t uDelta = index - 22;
            return GFloat::FromFractionAndExp(Trawvalue >> uDelta, Texponent + uDelta);
        }
    }

    static inline GFloat Normalize64(int64_t Trawvalue, int32_t Texponent)
    {
        if( Trawvalue == 0 )
            return GFloat(0,0);

        int32_t index = GBitScanReverse64(std::abs(Trawvalue ));

        if ( index <= 22 )
        {
            int32_t uDelta = 22 - index;
            return GFloat::FromFractionAndExp((int32_t)(Trawvalue << uDelta), Texponent - uDelta);
        }
        else
        {
            int32_t uDelta = index - 22;
            return GFloat::FromFractionAndExp((int32_t)(Trawvalue >> uDelta), Texponent + uDelta);
        }
    }

    inline bool IsNormalize() const
    {
        int32_t absRaw = std::abs(getfraction());

        if ( absRaw !=0 && ( absRaw < 0x00400000  || absRaw > 0x007FFFFF))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    inline GFloat operator +( const GFloat b) const
    {
        int32_t a_Frac = getfraction_NoShift();
        int32_t b_Frac = b.getfraction_NoShift();
        int32_t a_e = getexponent();
        int32_t b_e = b.getexponent();

        if( a_Frac==0)
            return Normalize32(b.getfraction(), b.getexponent());
        if (b_Frac == 0)
            return Normalize32(getfraction(), getexponent());

        if (a_e >= b_e)
        {
            int32_t nShift = a_e - b_e > 23 ? 23 : a_e - b_e;
            return Normalize64((int64_t)a_Frac + ((int64_t)b_Frac >> nShift), a_e - 8);
        }
        else
        {
            int32_t nShift = b_e - a_e > 23 ? 23 : b_e - a_e;
            return Normalize64((int64_t)b_Frac + ((int64_t)a_Frac >> nShift), b_e - 8);
        }         

    }

    inline const GFloat operator +=(const GFloat b)
    {
        *this = *this + b;
        return *this;
    }

    inline constexpr bool operator ==(const GFloat b) const
    {
        return rawint32 == b.rawint32;
    }

    inline constexpr bool operator !=( const GFloat b) const
    {
        return rawint32 != b.rawint32;
    }

    inline const GFloat operator -() const
    {
        int32_t nFraction = getfraction();

        //return GFloat::FromFractionAndExp(-nFraction, getexponent());
        return GFloat::Normalize32(-nFraction, getexponent());
    }

    inline const GFloat operator -( const GFloat b) const
    {
        return *this + (-b);
    }

    inline const GFloat operator -=(GFloat b)
    {
        *this = *this - b;
        return *this;
    }


#ifdef GLACIER_MULTIPLY_NORAMLIZE_FAST

    inline const GFloat operator *(const GFloat b) const
    {
        // I assume a and b is normalized, if a or b is zero,it will get a correct result
        int64_t Trawvalue = (int64_t)getfraction() * b.getfraction_NoShift();
        int32_t Texponent = getexponent() + b.getexponent() - 103;

        return GFloat::FromFractionAndExp((int32_t)(Trawvalue >> 32), Texponent);
    }
#else 

    inline const GFloat operator *(GFloat b) const
    {
        int64_t Trawvalue = (int64_t)getfraction() * b.getfraction();
        int32_t Texponent = getexponent() + b.getexponent() - 127;
        return  GFloat::Normalize64(Trawvalue, Texponent);
    }
#endif
    inline const GFloat operator *=(GFloat b)
    {
        *this = *this * b;
        return *this;
    }

    inline const GFloat operator /(const GFloat b) const
    {
        int32_t nDivid = (int32_t)b.getfraction();
        if (nDivid == 0) // for stable
        {
            return GFloat(0);
        }

        int64_t Trawvalue = ((int64_t)getfraction() << 32) / nDivid;
        int32_t Texponent = getexponent() - b.getexponent() + 127 - 32;

        return  GFloat::Normalize64(Trawvalue, Texponent);
    }

    inline const GFloat operator /=(GFloat b)
    {
        *this = *this / b;
        return *this;
    }

    inline bool operator > (const GFloat b) const
    {
        int32_t a_fra = getfraction_NoShift();
        int32_t b_fra = b.getfraction_NoShift();

        if( a_fra == 0 || b_fra == 0)
            return a_fra > b_fra;

        int32_t a_e = getexponent();// -127;
        int32_t b_e = b.getexponent();//-127;

        if (a_e >= b_e)
        {
            int32_t nShift = a_e - b_e;
            return (int64_t)a_fra > ((int64_t)b_fra >> (nShift > 31 ? 31 : nShift));
        }
        else
        {
            int32_t nShift = b_e - a_e;
            return ((int64_t)a_fra >> (nShift > 31 ? 31 : nShift)) > (int64_t)b_fra;
        }
    }

    inline bool operator >= (const GFloat b) const
    {
        return (rawint32 == b.rawint32) || (*this > b);
    }

    inline bool operator < (const GFloat b) const
    {
        return !(*this >= b);
    }

    inline bool operator <= (const GFloat b) const
    {
        return !(*this > b);
    }

    inline int32_t GetWhole() const
    {
        int32_t exp = (getexponent() - 127);
        if (exp >= 0)
        {
            return getfraction() << exp;// exp > 8 will overflow
        }
        else if (exp > -23)
        {
            int32_t Frac = getfraction();
            if( rawint32 >= 0)
            {
                return Frac >> -exp;
            }
            else
            {
                return -((-Frac) >> -exp);
            }
        }
        else
        {
            return 0;
        }
    }

    inline int32_t GetWhole(GFloat& OutFraction) const
    {
        int32_t exp = (getexponent() - 127);
        if (exp >= 0)
        {
            OutFraction = Zero();
            return getfraction() << exp; // exp > 8 will overflow
        }
        else if (exp > -23)
        {
            int32_t fra = getfraction();
            int32_t fraMask = (1 << -exp) - 1;

            if( fra >= 0 )
            {
                int32_t TRaw = fra >> -exp;
                int32_t TRra = fra & fraMask;
                OutFraction = GFloat::Normalize32(TRra << (23 + exp), 127 - 23);
                return TRaw;
            }
            else
            {
                int32_t TRaw = -fra >> -exp;
                int32_t TRra = -fra & fraMask;
                OutFraction = GFloat::Normalize32( -TRra << (23 + exp), 127 - 23);
                return -TRaw;       
            }
        }
        else
        {
            OutFraction = *this;
            return 0;
        }    
    }

    static inline GFloat Ceil( const GFloat value)
    {
        int32_t exp = (value.getexponent() - 127);

        if (exp >= 0)
            return value;
        else if (exp > -23)// 22 or 23
        {
            GFloat TFloor = GFloat::FromFractionAndExp((value.getfraction() >> -exp) << -exp, exp + 127);
            return TFloor == value ? TFloor : TFloor + One();
        }
        else
        {
            return value.getfraction() > 0 ? One() : Zero();
        }
    
    }
    static inline GFloat Floor(const GFloat value)
    {
        int32_t exp = (value.getexponent() - 127);

        if (exp >= 0)
            return value;
        else if( exp > -23 )
        {
            return GFloat::FromFractionAndExp((value.getfraction() >> -exp) << -exp, exp + 127);
        }
        else
        {
            return value.getfraction() > 0 ? Zero() : -One();
        }
    }

    static inline int32_t FloorToInt( const GFloat value)
    {
        int32_t exp = (value.getexponent() - 127);
        int32_t fra = value.getfraction();
        if (exp >= 0)
        {
            return fra << exp;// exp > 8 will overflow
        }
        else if (exp > -23)
        {
            return fra >> -exp;
        }
        else
        {
            if (fra >= 0)
                return 0;
            else
                return -1;
        }
    }

    static inline int32_t CeilToInt(const GFloat value)
    {
        int32_t exp = (value.getexponent() - 127);
        int32_t fra = value.getfraction();
        if (exp >= 0)
        {
            return fra << exp;// exp > 8 will overflow
        }
        else if (exp > -23)
        {
            int32_t fraMask = (1 << -exp) - 1;

            if( fraMask & fra )
            {
                return (fra >> -exp ) + 1;
            }
            else
            {
                return (fra >> -exp );
            }
        }
        else
        {
            if (fra >= 0)
                return 1;
            else
                return 0;
        }
    }

    static inline GFloat Abs(const GFloat value)
    {
        return value.rawint32 >= 0 ? value : -value;
    }

    static GFloat Sin(const GFloat value);
    static GFloat Cos(const GFloat value);
    static void   SinCos(const GFloat value, GFloat& OutSin, GFloat& OutCos);
    static GFloat ASin(const GFloat value);
    static GFloat ACos(const GFloat value);
    static GFloat Tan(const GFloat value);
    static GFloat ATan(const GFloat value);
    static GFloat ATan2(const GFloat y, const GFloat x);
    static GFloat Exp(const GFloat value){return Pow2(value * e_Div_2());}
    static GFloat Log(const GFloat value);
    static GFloat Log2(const GFloat value);
    static GFloat Log10(const GFloat value);
    static GFloat Pow2(const GFloat value);
    static GFloat Pow(const GFloat base, const GFloat exponent) { if (base.rawint32 <= 0) return Zero(); return Pow2(exponent * Log2(base)); }
    static GFloat InvSqrt(const GFloat value );
    static GFloat Sqrt(const GFloat value){return value * InvSqrt(value);}
    static GFloat Fmod(const GFloat x, const GFloat y){ GFloat t = x / y; GFloat out = Zero(); int32_t n = t.GetWhole(out); return x - GFloat(n) * y;}
public:
    static constexpr int32_t ms_TriTableBit = 8;
    static constexpr int32_t ms_TriCount = 1 << ms_TriTableBit;

private:

    static int32_t  ms_SinCosTable[ms_TriCount*2];
};

