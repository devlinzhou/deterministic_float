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

	explicit inline constexpr GFixedType32(int32_t raw)
		: rawInt32(raw)
	{

	}

	explicit inline constexpr GFixedType32(uint32_t a, uint32_t b, uint32_t c) :
		rawInt32(int32_t((a << FractionNumType) | ((((uint64_t)b) << FractionNumType) / c)))
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
	inline constexpr GFixedType32 operator +=(GFixedType32 b)
	{
		*this = *this + b;
		return *this;
	}


	inline constexpr GFixedType32 operator -() const
	{
		return GFixedType32(-rawInt32);
	}

	inline constexpr GFixedType32 operator -(GFixedType32 b) const
	{
		return GFixedType32(rawInt32 - b.rawInt32);
	}

	inline constexpr GFixedType32 operator *(GFixedType32 b) const
	{
		return GFixedType32(((int64_t)rawInt32 * (int64_t)b.rawInt32) >> FractionNumType);
	}

	 static inline constexpr GFixedType32 FromGFloat( const GFloat Value)
	{
		int32_t exp = Value.getexponent() - 127 + GFixedType32<FractionNumType>::GetTypeNumber();

		if (exp >= 0)
		{
			return GFixedType32(Value.getfraction() << exp);
		}
		else
		{
			return GFixedType32(Value.getfraction() >> -exp);
		}
	}

	inline constexpr GFloat ToGFloat() const
	{
		return GFloat::Nomalize((int64_t)rawInt32, uint8_t(127 - GFixedType32<FractionNumType>::GetTypeNumber()));
	}

	int32_t rawInt32;
};

typedef GFixedType32<8>  GFixed08;
typedef GFixedType32<16> GFixed16;
typedef GFixedType32<29> GFixed29;
typedef GFixedType32<30> GFixed30;



int32_t GFloat::ms_SinCosTable[GFloat::ms_TriCount * 2];
GFloat GFloat::ms_TanTable[GFloat::ms_TriCount];

void GFloat::Init()
{
	for( int32_t i = 0; i <GFloat::ms_TriCount; ++i ) // for test
	{
		float fvalue = float(i) * 3.141592653f * 2 / GFloat::ms_TriCount;

		float fSin = sinf(fvalue);  // to do use Gfloat compute Sin
		float fCos = cosf(fvalue);
		float fTan = tanf(fvalue);
		

		GFloat GSin = GFloat::FromFloat(fSin);
		GFloat GCos = GFloat::FromFloat(fCos);

		GFixed30 SinValue = GFixed30::FromGFloat( GSin );
		GFixed30 CosValue = GFixed30::FromGFloat(GCos);

		ms_SinCosTable[i*2] = SinValue.rawInt32;
		ms_SinCosTable[i*2+1] = CosValue.rawInt32;

		ms_TanTable[i] = FromFloat( fTan ) ;
	}
}

static inline int32_t Sin_Table(const GFloat value, GFixed30& Delta)
{
	GFloat		TMod = value * GFloat::Pi_TwoInv();
	GFloat		Fraction = TMod - GFloat::Floor(TMod); // Fraction > 0
	GFixed30    F30Fraction = GFixed30::FromGFloat(Fraction);

	int32_t TWhole = F30Fraction.rawInt32 >> (30 - GFloat::ms_TriTableBit);

	GFixed30 ttTest = GFixed30(TWhole << (30 - GFloat::ms_TriTableBit));

	constexpr GFixed30 C_quaterPi(0, 785398164, 1000000000);

	Delta = C_quaterPi * GFixed30(F30Fraction.rawInt32 & ((1 << (30 - GFloat::ms_TriTableBit)) - 1));

	Delta.rawInt32 = Delta.rawInt32 << 3;

	int32_t nWhole = (TWhole) & (GFloat::ms_TriCount - 1);

	return nWhole;
}


GFloat GFloat::Sin(const GFloat value) 
{
#if 1

	GFixed30 F30Delte(0);

	int32_t nWhole = Sin_Table(value, F30Delte );

	GFixed30 TableSin = GFixed30(ms_SinCosTable[nWhole * 2]);
	GFixed30 TableCos = GFixed30(ms_SinCosTable[nWhole * 2 + 1]);

	GFixed30 FixedResult = TableSin + TableCos * F30Delte;

	//if (nItem >= 1) FixedResult += TableCos * F30Delte;
	//if (nItem >= 2) FixedResult +=-TableSin * F30Delte * F30Delte * GFixed30(0, 1, 2);
	//if (nItem >= 3) FixedResult +=-TableCos * F30Delte * F30Delte * F30Delte * GFixed30(0, 1, 6);
	//if (nItem >= 4) FixedResult += TableCos * F30Delte * F30Delte * F30Delte * F30Delte * GFixed30(0, 1, 24);
	return FixedResult.ToGFloat();

#else

	if(value < Zero() )
 	{
 		return -Sin(-value);
 	}

    GFloat TMod = value * Pi_Inv();

    GFloat Fraction = TMod - GFloat::Floor( TMod);

    if(Fraction > Half())
    {
        Fraction = One() - Fraction;
    }

	constexpr GFixed29 C_1_2(0, 1, 2);
	constexpr GFixed29 C_1(1, 0, 10000);
	constexpr GFixed29 C_quaterPi(0, 785398164, 1000000000);
	constexpr GFixed29 C_sqrt2(0, 70710678, 100000000);
	constexpr GFixed29 C_1_6(0, 1, 6);
	constexpr GFixed29 C_1_24(0, 1, 24);
	constexpr GFixed29 C_1_120(0, 1, 120);

	//constexpr GFixed30 C_quaterPi(0, 785398164, 1000000000);

	GFixed29 x1 = GFixed29::FromGFloat(Fraction*Pi()) - C_quaterPi;

	//GFixed30 SinValue = C_sqrt2 * (C_1 + x1 - C_1_2 * x2 - C_1_6 * x3 + C_1_24 * x4 + C_1_120 * x5 );

	GFixed29 SinValue = C_sqrt2 * (C_1 +  x1 *(C_1 + x1*( - C_1_2 + x1 * (- C_1_6  + x1 * (C_1_24 + C_1_120 * x1)))));

	int32_t TWhole = TMod.GetWhole();
    if( TWhole % 2 == 1 || TWhole % 2 == -1)
    {
        SinValue = -SinValue;
    }

	return SinValue.ToGFloat();

	#endif
}

GFloat GFloat::Cos(const GFloat value)
{ 
	GFixed30 F30Delte(0);

	int32_t nWhole = Sin_Table(value, F30Delte);

	GFixed30 TableSin = GFixed30(ms_SinCosTable[nWhole * 2]);
	GFixed30 TableCos = GFixed30(ms_SinCosTable[nWhole * 2 + 1]);

	GFixed30 FixedResult = TableCos - TableSin * F30Delte;
	return FixedResult.ToGFloat();
}
void GFloat::SinCos(const GFloat value, GFloat& OutSin, GFloat& OutCos)
{
	GFixed30 F30Delte(0);

	int32_t nWhole = Sin_Table(value, F30Delte);
	GFixed30 TableSin = GFixed30(ms_SinCosTable[nWhole * 2]);
	GFixed30 TableCos = GFixed30(ms_SinCosTable[nWhole * 2 + 1]);

    OutSin = (TableSin + TableCos * F30Delte).ToGFloat();
    OutCos = (TableCos - TableSin * F30Delte).ToGFloat();
}
GFloat GFloat::ASin(const GFloat value)
{
    if( (value > One()) || (value <-One()) )
    {
        return Zero();
    }
    else
    {
		GFixed29 x1 =  GFixed29::FromGFloat(value);
		GFixed29 x2 = x1 * x1;
// 		GFixed30 x3 = x2 * x1;
// 
// 		GFixed30 x4 = x3 * x1;
// 		GFixed30 x5 = x3 * x2;
// 		GFixed30 x6 = x5 * x1;
// 
// 		GFixed30 x7 = x5 * x2;

       // return (x1 + x3 * GFixed30(0, 1, 6) + x5 * GFixed30(0, 3, 40) + x7 * GFixed30(0, 5, 112)).ToGFloat();
		return (x1*(GFixed29(1, 0, 2) +x2 *(  GFixed29(0, 1, 6) + x2 * ( GFixed29(0, 3, 40) + x2 * GFixed29(0, 5, 112))))).ToGFloat();

    }
}
GFloat GFloat::ACos(const GFloat value)
{
	if ((value > One()) || (value < -One()))
	{
		return Zero();
	}
	else
	{
		GFixed29 x1 = GFixed29::FromGFloat(value);
		GFixed29 x2 = x1 * x1;

		return (GFixed29(1,5707963, 10000000) - x1 * (GFixed29(1, 0, 2) + x2 * (GFixed29(0, 1, 6) + x2 * (GFixed29(0, 3, 40) + x2 * GFixed29(0, 5, 112))))).ToGFloat();

	}
}
GFloat GFloat::Tan(const GFloat value) 
{
    GFloat TSin = Sin(value);
	GFloat TCos = Cos(value);
    SinCos(value, TSin, TCos);
    return TSin / TCos;
}
GFloat GFloat::ATan(const GFloat value)
{
	if( -One() <= value && value <= One() )
	{
		GFixed29 x1 =  GFixed29::FromGFloat(value);
		GFixed29 x2 = x1 * x1;

		return( x1 *(GFixed29(1,0,2) - x2 *( GFixed29(0,1,3) - x2 * GFixed29(0,1,5) ) )).ToGFloat();
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
		GFloat fraction;
		int32_t nWhole =  value.GetWhole(fraction);

		GFloat Result = One();
		for( int i = 0; i < (nWhole); ++i )
		{
			Result = Result * e();
		}

		//GFloat fraction = value;

		//GFixed29 x1 =      GFixed29::FromGFloat(     fraction   ) ;
		GFixed29 x1 = GFixed29::FromGFloat(fraction);


		return Result * ( GFixed29(1,0,2) + x1 *( GFixed29(1,0,2) +  x1 *( GFixed29(0,1,2) + x1 * ( GFixed29(0,1,6) + x1 * ( GFixed29(0,1,24) + x1 * GFixed29(0,1,120)) ) ))).ToGFloat();
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
	else if (value < Two())
	{
		GFixed29 x1 = GFixed29::FromGFloat(value - One());

		return ( x1 * ( GFixed29(1,0, 2) + x1 * ( -GFixed29(0,1, 2) + x1 *( GFixed29(0,1, 3) - x1 *( GFixed29(0,1, 4) - x1 * GFixed29(0,1, 5)))))).ToGFloat();
	}
	else
	{
		return One() + Log(value * e_Inv());
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

    GFloat y = (txep & 0x1) == 0 ? 
		GFloat::FromFractionAndExp(0x679851, uint8_t( 127 - txep / 2 + -23) ): 
		GFloat::FromFractionAndExp(0x265064, uint8_t( 127 - txep / 2 + -22));

    GFloat x2 = value * Half();
    y = y * (threehalfs - ((x2 * y) * y));
    y = y * (threehalfs - ((x2 * y) * y));

    return y;
}




