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

#ifdef _MSC_VER
#include <intrin.h>
#include <immintrin.h>
#define GFORCE_INLINE _forceinline
#else
#define GFORCE_INLINE inline   
#endif

class FloatIEEE_754 
{
public:
    FloatIEEE_754()
    {
        rawint32 = 0;
    }
    union
    {
        int32_t rawint32;
        struct //MyFloat32
        {
            uint32_t    fraction: 23;
            uint32_t    exponent: 8;
            int32_t     sign    : 1;
        } rawfloat;
    };
};

class GFloat
{
public:
    static inline constexpr GFloat Zero()       { return GFloat(0,          0xE9); };
    static inline constexpr GFloat One()        { return GFloat(0x400000,   0x69); };
    static inline constexpr GFloat Half()       { return GFloat(0x400000,   0x68); };
    static inline constexpr GFloat Two()        { return GFloat(0x400000,   0x6A); };
    static inline constexpr GFloat Pi()         { return GFloat(0x6487ef,   0x6a); };//Float(3,141592654, 1000000000); 
    static inline constexpr GFloat Pi_Half()    { return GFloat(0x6487ef,   0x69); };
    static inline constexpr GFloat Pi_Quarter() { return GFloat(0x6487ef,   0x68); };
    static inline constexpr GFloat Pi_Two()     { return GFloat(0x6487ef,   0x6b); };
    static inline constexpr GFloat Pi_Inv()     { return GFloat(0x517cc1,   0x67); };
    static inline constexpr GFloat Pi_TwoInv()  { return GFloat(0x517cc1,   0x66); };
    static inline constexpr GFloat e()          { return GFloat(0x56fc2a,   0x6a); };
    static inline constexpr GFloat e_Inv()      { return GFloat(0x5e2d58,   0x67); };

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

public:
    int32_t rawint32;

public:

    static void Init();

    constexpr GFloat(const GFloat&) = default;

    constexpr GFloat() : rawint32(0)
    {

    }

    explicit inline GFloat( int32_t TValue)
    {
        *this= Normalize((int64_t)TValue, 127);
        //*this = FromFractionAndExp(TValue, 127);
    }

    constexpr GFloat(int32_t Traw32, uint8_t exp ) :
        rawint32((Traw32 << 8) | int32_t(exp))
    {
    }

    explicit inline GFloat(int32_t Traw32, uint32_t a, uint32_t b)
    {
        int64_t TValue = (int64_t)b * (int64_t)Traw32 + (int64_t)a;

        uint32_t index = GBitScanReverse64( (uint64_t)abs(TValue));

        uint8_t exp = uint8_t(62 - index);

        int64_t TRawn = (TValue << exp ) / b;

        *this = Normalize(TRawn, uint8_t(127 - exp));
    }

    /*inline Float32(float value )
    {
        FromFloat(value);
    }*/

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
        GFloat T;
        T.rawint32 = Traw32;
        return T;
    }

    static inline constexpr GFloat FromFractionAndExp(int32_t Traw32, uint8_t exp)
    {
        return GFloat(Traw32, exp);
    }

    static inline GFloat FromFloat(float f)
    {
        if (f == 0.f || f == -0.f)
            return Zero();

        FloatIEEE_754 TFloat754;
        TFloat754.rawint32 = *(int32_t*)&f;

        int32_t TRraction = (int32_t)TFloat754.rawfloat.fraction + 0x00800000;
        
        if( TFloat754.rawfloat.sign != 0)
            TRraction = -TRraction;

        return GFloat::FromFractionAndExp(TRraction >> 1,uint8_t(TFloat754.rawfloat.exponent - 22));
    }

    float toFloat() const
    {
        int32_t Texponent = getexponent() - 127;
        if( -62 < Texponent &&  Texponent< 62 )
        {
            double dResult = Texponent >= 0 ?
                ((double)getfraction()) * double(((uint64_t)1) << Texponent):
                ((double)getfraction()) / double(((uint64_t)1) << -Texponent);
            return float(dResult); 
        }
        else
        {
            double dT = pow(2, Texponent);
            double dResult = getfraction() * dT;
            return float(dResult);
        }
    }

    double toDouble() const
    {
        int32_t    Texponent    =    getexponent() - 127;
        double dT = pow(2, Texponent);
        double dResult = getfraction() * dT;

        return (dResult);
    }

    static inline GFloat Normalize(int64_t Trawvalue, uint8_t Texponent)
    {
        uint32_t index = GBitScanReverse64(abs(Trawvalue ));

#if 0

        uint32_t uDelta = index - 22;
        return GFloat::FromFractionAndExp((int32_t)( _rotr64(Trawvalue, uDelta)), uint8_t(Texponent + uDelta));


#else
        if ( index <= 22 )
        {
            uint32_t uDelta = 22 - index;
            return GFloat::FromFractionAndExp((int32_t)(Trawvalue << uDelta), uint8_t(Texponent - uDelta));
        }
        else
        {
            uint32_t uDelta = index - 22;
            return GFloat::FromFractionAndExp((int32_t)(Trawvalue >> uDelta), uint8_t(Texponent + uDelta));
        }

#endif
    }



//     inline bool CanToInt64() const
//     {
//         return 
//     }

    inline GFloat Add( const GFloat b ) const
    {
        int32_t a_f = getfraction();
        if (a_f == 0) return b;
        int32_t b_f = b.getfraction();
        if (b_f == 0) return *this;

        int32_t a_exp = getexponent();
        int32_t b_exp = b.getexponent();

        int32_t deltaexp = a_exp - b_exp;

        if (-23 < deltaexp && deltaexp < 23)
        {
            int32_t FractionValue = 0;
            int32_t c_exponent;
            if (deltaexp >= 0)
            {
                FractionValue = a_f + (b_f >> deltaexp);
                c_exponent = a_exp;
            }
            else
            {
                FractionValue = b_f + (a_f >> -deltaexp);
                c_exponent = b_exp;
            }
            return Normalize(FractionValue, (uint8_t)c_exponent);
        }
        else if (deltaexp >= 23)
        {
            return *this;
        }
        else
        {
            return b;
        }
    }

    inline constexpr int64_t ToInt64() const
    {
        return ((int64_t)getfraction_NoShift()) << (32 - 8 + getexponent() - 127); // -40 < exp < 40
    }

    GFORCE_INLINE GFloat operator +( const GFloat b) const
    {
        int32_t a_e = getexponent();// -127;
        int32_t b_e = b.getexponent();//-127;

        if (( (-32 +127) < a_e && a_e < (8 +127 )) && ((-32 +127) < b_e && b_e < (8 +127 )))
        {
            int64_t a64 = ToInt64();
            int64_t b64 = b.ToInt64();
            int64_t Result = a64 + b64;
            return Normalize(Result, (uint8_t)(127 - 32));
        }
        else
        {
            return Add(b);
        }
    }

    inline const GFloat operator +=( GFloat b)
    {
        *this = *this + b;
        return *this;
    }

    inline constexpr bool operator ==(GFloat b)
    {
        return rawint32 == b.rawint32;
    }

    inline constexpr bool operator !=(GFloat b)
    {
        return rawint32 != b.rawint32;
    }

    inline constexpr GFloat operator -() const
    {
        int32_t nFraction = getfraction();

        if( nFraction ==  0xff800000 )
        {
            nFraction = nFraction +1;
        }

        return GFloat::FromFractionAndExp(-nFraction, (uint8_t) getexponent());
    }

    inline const GFloat operator -(GFloat b) const
    {
        return *this + (-b);
    }

    inline constexpr GFloat operator *(GFloat b) const
    {
#if 0
        int64_t Trawvalue = (int64_t)getfraction() * b.getfraction();
        uint8_t Texponent = (uint8_t)(getexponent() + b.getexponent() - 127);
        return  GFloat::Nomalize(Trawvalue, Texponent);
#else 
        // I assume a and b is normalized, if a or b is zero,it will get a correct result
        int64_t Trawvalue = (int64_t)getfraction_NoShift() * b.getfraction_NoShift();
        uint8_t Texponent = (uint8_t)(getexponent() + b.getexponent() - 104);

        return GFloat::FromFractionAndExp((int32_t)(Trawvalue >> 39), Texponent );
#endif
    }

    inline const GFloat operator /(GFloat b) const
    {
        int32_t nDivid = (int32_t)b.getfraction();
        if (nDivid == 0) // for stable
        {
            return GFloat(0);
        }

        int64_t Trawvalue = ((int64_t)getfraction() << 32) / nDivid;
        uint8_t Texponent = (uint8_t)(getexponent() - b.getexponent() + 127 - 32);

        return  GFloat::Normalize(Trawvalue, Texponent);
    }

    inline bool operator > (GFloat b) const
    {
        GFloat TDelta = *this - b;
        return TDelta.rawint32 > 0;
    }

    inline bool operator >= (GFloat b) const
    {
        GFloat TDelta = *this - b;
        return TDelta.rawint32 >= 0;
    }

    inline bool operator < (GFloat b) const
    {
        GFloat TDelta = *this - b;
        return TDelta.rawint32 < 0;
    }

    inline bool operator <= (GFloat b) const
    {
        GFloat TDelta = *this - b;
        return TDelta.rawint32 <= 0;
    }

    inline int32_t GetWhole() const
    {
        int32_t Frac = getfraction();
        if ( Frac == 0)
            return 0;

        int32_t exp = (getexponent() - 127);
        if (exp > 8)
        {
            return Frac << 8; // overflow
        }
        if (exp >= 0)
        {
            return Frac << exp;
        }
        else if (exp > -23)
        {
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
            return getfraction() << exp;
        }
        else if (exp > -23)// 22 or 23
        {
            int32_t fra = getfraction();

            int32_t TRaw = fra >> -exp;

            int32_t TWhole;
            if( (TRaw << -exp ) == rawint32 )
            {
                TWhole = TRaw;
                OutFraction = Zero();
            }
            else
            {
                if( fra >=0 )
                {
                    TWhole = TRaw;
                }
                else
                {
                    TWhole = TRaw + 1;
                }

                OutFraction =  *this - GFloat(TWhole); // to do
            }

            return TWhole;
        }
        else
        {
            OutFraction = *this;
            return 0;
        }    
    }

    static GFloat Ceil( const GFloat value)
    {
        int32_t exp = (value.getexponent() - 127);

        if (exp >= 0)
            return value;
        else if (exp > -23)// 22 or 23
        {
            GFloat TFloor = GFloat::FromFractionAndExp((value.getfraction() >> -exp) << -exp, (uint8_t)( exp + 127));

            return TFloor == value ? TFloor : TFloor + One();
        }
        else
        {
            return value.getfraction() > 0 ? One() : Zero();
        }
    
    }
    static GFloat Floor(const GFloat value)
    {
        int32_t exp = (value.getexponent() - 127);

        if (exp >= 0)
            return value;
        else if( exp > -23 )
        {
            return GFloat::FromFractionAndExp((value.getfraction() >> -exp) << -exp, (uint8_t)(exp + 127));
        }
        else
        {
            return value.getfraction() > 0 ? Zero() : -One();
        }
    }

    static GFloat Abs(const GFloat value)
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
    static GFloat Exp(const GFloat value);
    static GFloat Log(const GFloat value);
    static GFloat Pow(const GFloat base, const GFloat exponent);
    static GFloat InvSqrt(const GFloat value );
    static GFloat Sqrt(const GFloat value){return value * InvSqrt(value);}


public:
    static constexpr int32_t ms_TriTableBit = 8;
    static constexpr int32_t ms_TriCount = 1 << ms_TriTableBit;

private:

    static int32_t  ms_SinCosTable[ms_TriCount*2];
    static GFloat   ms_TanTable[ms_TriCount];
};

#ifdef Determinate
typedef GFloat f32;
#endif // Determinate


