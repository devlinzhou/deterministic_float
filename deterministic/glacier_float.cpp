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

template<int32_t FractionNumType>
class GFixedType32
{
public:

	explicit inline constexpr GFixedType32( int32_t raw ) 
		: rawInt32(raw)
	{

	}

	explicit inline constexpr GFixedType32( uint32_t a, uint32_t b, uint32_t c ) :
		rawInt32( (a <<FractionNumType ) | ((((uint64_t)b) << FractionNumType) / c))
	{
	
	}

	static inline constexpr int32_t GetTypeNumber()
	{
		return FractionNumType;
	}
		
	inline constexpr GFixedType32 operator +(GFixedType32 b) const
	{
		return GFixedType32(rawInt32 + b.rawInt32);
	}

	inline constexpr GFixedType32 operator -() const
	{
		return GFixedType32(-rawInt32 );
	}

	inline constexpr GFixedType32 operator -(GFixedType32 b) const
	{
		return GFixedType32(rawInt32 - b.rawInt32);
	}

	inline constexpr GFixedType32 operator *(GFixedType32 b) const
	{
		return GFixedType32( ((int64_t)rawInt32 * (int64_t)b.rawInt32) >>FractionNumType ) ;
	}

	static inline constexpr GFixedType32 FromGFloat( GFloat Value)
	{
		int32_t exp = Value.getexponent() - 127 +  GFixedType32<FractionNumType>::GetTypeNumber();

		if(exp >= 0)
		{
			return GFixedType32(Value.getfraction() << exp );
		}
		else
		{
			return GFixedType32(Value.getfraction() >> exp );
		}
	}

	inline constexpr GFloat ToGFloat() const
	{
		return GFloat::Nomalize((int64_t)rawInt32, uint8_t( 127 - GFixedType32<FractionNumType>::GetTypeNumber()) );
	}

	int32_t rawInt32;
};

typedef GFixedType32<30> GFixed30;

GFloat GFloat::Sin(const GFloat value) 
{
	/*if(value < Zero() )
 	{
 		return -Sin(-value);
 	}

    GFloat TMod = value * Pi_Inv();

    GFloat Fraction = TMod - GFloat::Floor( TMod);

    int32_t TWhole = TMod.GetWhole();*/

	GFloat Fraction = value;
    if(value > Pi_Half())
    {
        Fraction = Pi() - Fraction;
    }

	constexpr GFixed30 C_1(1, 0, 1);
	constexpr GFixed30 C_1_2(0, 1, 2);	
	constexpr GFixed30 C_1_6(0, 1, 6);
	constexpr GFixed30 C_1_24(0, 1, 24);
	constexpr GFixed30 C_1_120(0, 1, 120);

	constexpr GFixed30 C_sqrt2(0, 707107, 1000000);
	constexpr GFixed30 C_quaterPi(0, 785398164, 1000000000);

	GFixed30 x1 = GFixed30::FromGFloat(Fraction) - C_quaterPi;
	GFixed30 x2 = x1 * x1;
	GFixed30 x3 = x2 * x1;
	GFixed30 x4 = x3 * x1;
	GFixed30 x5 = x4 * x1;

	//GFixed30 SinValue = C_sqrt2 * (C_1 + x1 - C_1_2 * x2 - C_1_6 * x3 + C_1_24 * x4 + C_1_120 * x5 );

	GFixed30 SinValue = C_sqrt2 * (C_1 +  x1 *(C_1 - C_1_2 * x1 - C_1_6 * x2 + C_1_24 * x3 + C_1_120 * x4) );

	//GFixed30 SinValue = C_sqrt2 * (C_1 + x1 * (C_1 - x1 * ( C_1_2 * x1 - C_1_6 * x2 + C_1_24 * x3 + C_1_120 * x4));


  //  if( TWhole % 2 == 1 || TWhole % 2 == -1)
    {
       // OutValue = -OutValue;
    }

	return SinValue.ToGFloat();
}
GFloat GFloat::Cos(const GFloat value)
{ 
    return Sin(value + Pi_Half());
}
void GFloat::SinCos(const GFloat value, GFloat& OutSin, GFloat& OutCos)
{
    OutSin = Sin(value);
    OutCos = Cos(value);

}
GFloat GFloat::ASin(const GFloat value)
{
    if( (value > One()) || (value <-One()) )
    {
        return Zero();
    }
    else
    {
		GFixed30 x1 =  GFixed30::FromGFloat(value);
		GFixed30 x2 = x1 * x1;
		GFixed30 x3 = x2 * x1;
		GFixed30 x5 = x3 * x2;
		GFixed30 x7 = x5 * x2;

        return (x1 + x3 * GFixed30(0, 1, 6) + x5 * GFixed30(0, 3, 40) + x7 * GFixed30(0, 5, 112)).ToGFloat();
    }
}
GFloat GFloat::ACos(const GFloat value)
{
    return Pi_Half() - ASin(value);
}
GFloat GFloat::Tan(const GFloat value) 
{
    GFloat TSin, TCos;
    SinCos(value, TSin, TCos);
    return TSin / TCos;
}
GFloat GFloat::ATan(const GFloat value)
{
	if( -One() <= value && value <= One() )
	{
		GFloat x1 = value;
		GFloat x2 = x1 * x1;
		GFloat x3 = x2 * x1;
		GFloat x5 = x2 * x3;

		return x1 - x3 / GFloat(3) + x5 / GFloat(5);
	}
	else if(value > One() )
	{
		return Pi_Half() - ATan(One() / value);
	}
	else
	{
		return  - ATan(One() / value) - Pi_Half();
	}

}
GFloat GFloat::ATan2(const GFloat y, const GFloat x)
{
	if( x > Zero() )
	{
		GFloat value = y / x;
		return ATan(value);
	}
	else if( x < Zero() )
	{
		if( y > Zero() )
		{
			return Pi() + ATan(y / x);
		}
		else
		{
			return ATan(y / x) - Pi();
		}
	}
	else
	{
		return Zero();
	} 
}  
GFloat GFloat::Exp(const GFloat value)
{ 
	if(value >= Zero())
	{
		static const GFloat e = GFloat(2, 71828, 100000);

		GFloat t = value ;
		GFloat fraction;
		int32_t nWhole = t.GetWhole(fraction);

		GFloat Result = One();
		for( int i = 0; i < (nWhole); ++i )
		{
			Result = Result * e;
		}

		GFloat x1 = fraction;
		GFloat x2 = x1 * x1;
		GFloat x3 = x2 * x1;
		GFloat x4 = x3 * x1;
		GFloat x5 = x2 * x3;

		return Result * ( One() + x1 + x2 / GFloat(2) + x3 / GFloat(6) + x4 / GFloat(24) + x5 / GFloat(120) );
	}
	else
	{
		return One() / Exp(-value);
	}
}
GFloat GFloat::Log(const GFloat value)
{ 
	if( value <= Zero() )
	{
		return Zero();
	}
	else if (value < GFloat(2))
	{
		GFloat x1 = value - One();
		GFloat x2 = x1 * x1;
		GFloat x3 = x2 * x1;
		GFloat x4 = x3 * x1;
		GFloat x5 = x2 * x3;

		return x1 - x2 / GFloat(2) + x3 / GFloat(3) - x4 / GFloat(4) + x5 / GFloat(5);
	}
	else
	{
		return One() + Log(value / GFloat(2, 71828, 100000));
	}
}
GFloat GFloat::Pow(const GFloat x, const GFloat y)
{
	if (x <= Zero())
		return Zero();

    return Exp(y * Log(x));
}

GFloat GFloat::InvSqrt(const GFloat value)
{
    if (value.rawint32 <= 0)
        return Zero();

    static const GFloat threehalfs(1, 1, 2);

    int32_t txep = value.getexponent() - 127 + 22;

    GFloat y = (txep & 0x1) == 0 ? GFloat::FromFractionAndExp(0x679851, 127 - txep / 2 + -23) : GFloat::FromFractionAndExp(0x265064, 127 - txep / 2 + -22);

   // GFloat x2 = value * Half();
   // y = y * (threehalfs - ((x2 * y) * y));
   // y = y * (threehalfs - ((x2 * y) * y));

    return y;
}




