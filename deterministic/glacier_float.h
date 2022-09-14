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
#endif


class FloatIEEE_745 
{
public:
    FloatIEEE_745()
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

class GFloat final {

public:
	static inline constexpr GFloat Zero()		{ return GFloat(0,		  0xE9); };
	static inline constexpr GFloat One()		{ return GFloat(0x400000, 0x69); };
	static inline constexpr GFloat Half()		{ return GFloat(0x400000, 0x68); };
	static inline constexpr GFloat Two()		{ return GFloat(0x400000, 0x6A); };
    static inline constexpr GFloat Pi()			{ return GFloat(0x6487ef, 0x6a); };//Float(3,141592654, 1000000000); 
	static inline constexpr GFloat Pi_Half()	{ return GFloat(0x6487ef, 0x69); };
	static inline constexpr GFloat Pi_Quarter() { return GFloat(0x6487ef, 0x68); };
	static inline constexpr GFloat Pi_Two()		{ return GFloat(0x6487ef, 0x6b); };
	static inline constexpr GFloat Pi_Inv()		{ return GFloat(0x517cc1, 0x67); };

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

#endif
    }

public:
    int32_t rawint32;

public:

	constexpr GFloat(const GFloat&) = default;

	constexpr GFloat() : rawint32(0)
    {

    }

    inline GFloat( int32_t TValue)
    {
		*this= Nomalize((int64_t)TValue, 127);
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

        *this = Nomalize(TRawn, uint8_t(127 - exp));
    }

    /*inline Float32(float value )
    {
        FromFloat(value);
    }*/

    inline int32_t getfraction() const
    {
       return rawint32 >> 8 ;
    }
    inline int32_t getfraction_NoShift() const
    {
        return int32_t(rawint32 & 0xFFFFFF00);
    }

    inline int32_t getfraction(int32_t shift) const
    {
        return getfraction() >> ( shift);
    }

    inline int32_t getexponent() const
    {
        return (rawint32 & 0xFF);
    }

    static inline GFloat FromRaw32(int32_t Traw32)
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
        FloatIEEE_745 T745;
        T745.rawint32 = *(int32_t*)&f;

        int32_t TRraction = (int32_t)T745.rawfloat.fraction + 0x00800000;
        
        if( T745.rawfloat.sign != 0)
            TRraction = -TRraction;

        return GFloat::FromFractionAndExp(TRraction >> 1,uint8_t(T745.rawfloat.exponent - 22));
    }

    float toFloat() const
    {
        int32_t Texponent = getexponent() - 127;
        double dT =  pow(2, Texponent) ;
		double dResult = getfraction() * dT;

        return float(dResult);
    }

	double toDouble() const
	{
		int32_t Texponent = getexponent() - 127;
		double dT = pow(2, Texponent);
		double dResult = getfraction() * dT;

		return (dResult);
	}

    static inline GFloat Nomalize(int64_t Trawvalue, uint8_t Texponent)
    {
        uint32_t index = GBitScanReverse64(abs(Trawvalue));
        if (index <= 22)
        {
            uint32_t uDelta = 22 - index;
            return GFloat::FromFractionAndExp((int32_t)(Trawvalue << uDelta), uint8_t(Texponent - uDelta));
        }
        else
        {
            uint32_t uDelta = index - 22;
            return GFloat::FromFractionAndExp((int32_t)( Trawvalue >> uDelta), uint8_t(Texponent + uDelta));
        }
    }

    inline GFloat operator +(GFloat b) const
    {
        int32_t a_f = getfraction();
        if (a_f == 0) return b;
        int32_t b_f = b.getfraction();
        if (b_f == 0) return *this;

        int32_t a_exponent = getexponent();
        int32_t b_exponent = b.getexponent();
        int32_t deltaexp = a_exponent - b_exponent;

        if(-23 < deltaexp && deltaexp < 23)
        {
            int32_t FractionValue = 0;
            int32_t c_exponent;
            if (deltaexp >= 0)
            {
                FractionValue = a_f + (b_f >> deltaexp);
                c_exponent = a_exponent;
            }
            else
            {
                FractionValue = b_f + (a_f >> -deltaexp );
                c_exponent = b_exponent;
            }
            return Nomalize(FractionValue, (uint8_t) c_exponent);
        }
		else if( deltaexp >= 23)
		{
			return *this;
		}
		else
		{
			return b;
		}
    }

    inline const GFloat operator +=( GFloat b)
    {
        *this = *this + b;
        return *this;
    }

	inline const bool operator ==(GFloat b)
	{
		return rawint32 == b.rawint32;
	}

	inline const bool operator !=(GFloat b)
	{
		return rawint32 != b.rawint32;
	}

    inline const GFloat operator -() const
    {
        return GFloat::FromFractionAndExp(-getfraction(), (uint8_t) getexponent());
    }

    inline const GFloat operator -(GFloat b) const
    {
        return *this + (-b);
    }

    inline const GFloat operator *(GFloat b) const
    {
#if 1
        int64_t Trawvalue = (int64_t)getfraction() * b.getfraction();
        uint8_t Texponent = (uint8_t)(getexponent() + b.getexponent() - 127);
        return  GFloat::Nomalize(Trawvalue, Texponent);
#else
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

        return  GFloat::Nomalize(Trawvalue, Texponent);
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
		int32_t exp = (getexponent() - 127);

		if (exp >= 0)
		{
			return getfraction() << exp;
		}
		else if (exp > -23)// 22 or 23
		{
			int32_t fra = getfraction();

			int32_t TRaw = fra >> -exp;

			int32_t TWhole;
			if ((TRaw << -exp) == rawint32)
			{
				TWhole = TRaw;

			}
			else
			{
				if (fra >= 0)
				{
					TWhole = TRaw;
				}
				else
				{
					TWhole = TRaw + 1;
				}
			}

			return TWhole;
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

        if (exp > 0)
            return value;
        else if( exp > -23 )// 22 or 23
        {
            return GFloat::FromFractionAndExp((value.getfraction() >> -exp) << -exp, (uint8_t)(exp + 127));
        }
        else
        {
            return value.getfraction() > 0 ? Zero() : -One();
        }
    }
    static GFloat Sin(const GFloat value);
    static GFloat Cos(const GFloat value);
    static void	  SinCos(const GFloat value, GFloat& OutSin, GFloat& OutCos);
    static GFloat ASin(const GFloat value);
    static GFloat ACos(const GFloat value);
    static GFloat Tan(const GFloat value);
    static GFloat ATan(const GFloat value);
    static GFloat ATan2(const GFloat y, const GFloat x);
    static GFloat Exp(const GFloat value);
    static GFloat Log(const GFloat value);
    static GFloat Pow(const GFloat base, const GFloat exponent);
    static GFloat InvSqrt(const GFloat value);
    static GFloat Sqrt(const GFloat value){return value * InvSqrt(value);}

};

#ifdef Determinate
typedef GFloat f32;
#endif // Determinate


