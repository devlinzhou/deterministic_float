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
	int32_t exp = value.getexponent() - 127;

	if (-64 >= exp || exp >= 64)
	{
		Delta = GFixed30(0,0,1);
		return 0;
	}

	int64_t TRaw = value.getfraction() * (int64_t)GFixed30(0, 159154943, 1000000000).rawInt32;

	int64_t NewRaw = exp >= 0 ? TRaw << exp : TRaw >> -exp;

	GFixed30   F30Fraction = GFixed30((NewRaw) & 0x3FFFFFFF);

	int32_t TWhole = F30Fraction.rawInt32 >> (30 - GFloat::ms_TriTableBit);

	GFixed30 ttTest = GFixed30(TWhole << (30 - GFloat::ms_TriTableBit));

	constexpr GFixed30 C_quaterPi(0, 785398164, 1000000000);

	GFixed30 delta_1 =  GFixed30(F30Fraction.rawInt32 & ((1 << (30 - GFloat::ms_TriTableBit)) - 1));

	//GFixed30 F30Fraction_Test = ttTest + delta_1;

	Delta = C_quaterPi * delta_1;
	Delta.rawInt32 = Delta.rawInt32 << 3;

	int32_t nWhole = (TWhole) & (GFloat::ms_TriCount - 1);

	return nWhole;
}

GFloat GFloat::Sin(const GFloat value) 
{
	GFixed30 F30Delte(0);

	int32_t nWhole = Sin_Table(value, F30Delte );

	GFixed30 TableSin = GFixed30(ms_SinCosTable[nWhole * 2]);
	GFixed30 TableCos = GFixed30(ms_SinCosTable[nWhole * 2 + 1]);

	GFixed30 FixedResult = TableSin + F30Delte * ( TableCos - TableSin * GFixed30(F30Delte.rawInt32 >> 1));

	return FixedResult.ToGFloat();
}

GFloat GFloat::Cos(const GFloat value)
{ 
	GFixed30 F30Delte(0);

	int32_t nWhole = Sin_Table(value, F30Delte);

	GFixed30 TableSin = GFixed30(ms_SinCosTable[nWhole * 2]);
	GFixed30 TableCos = GFixed30(ms_SinCosTable[nWhole * 2 + 1]);

	GFixed30 FixedResult = TableCos - F30Delte * (TableSin + TableCos * GFixed30(F30Delte.rawInt32 >> 1));
	return FixedResult.ToGFloat();
}
void GFloat::SinCos(const GFloat value, GFloat& OutSin, GFloat& OutCos)
{
	GFixed30 F30Delte(0);

	int32_t nWhole = Sin_Table(value, F30Delte);
	GFixed30 TableSin = GFixed30(ms_SinCosTable[nWhole * 2]);
	GFixed30 TableCos = GFixed30(ms_SinCosTable[nWhole * 2 + 1]);

    OutSin = (TableSin + F30Delte * ( TableCos - TableSin * GFixed30(F30Delte.rawInt32 >> 1))).ToGFloat();
    OutCos = (TableCos - F30Delte * ( TableSin + TableCos * GFixed30(F30Delte.rawInt32 >> 1))).ToGFloat();
}
GFloat GFloat::ASin(const GFloat value)
{
	constexpr GFloat TOne =  GFloat::FromRaw32( One().rawint32 - 0x1000  );
    if( value > TOne) 
	{
		return Pi_Half();
	}
	else if (value <-TOne )
    {
        return -Pi_Half();
    }
    else
    {
		GFixed29 x1 =  GFixed29::FromGFloat(value);
		GFixed29 x2 = x1 * x1;

		return (x1 * (GFixed29(1, 0, 2)   +
				x2 * (GFixed29(0, 1, 6)   + 
				x2 * (GFixed29(0, 3, 40)  + 
				x2 * (GFixed29(0, 5, 112) +
				x2 * (GFixed29(0, 35, 1152)+
				x2 * (GFixed29(0, 63, 2816)))))))).ToGFloat();
    }
}
GFloat GFloat::ACos(const GFloat value)
{
	constexpr GFloat TOne =  GFloat::FromRaw32( One().rawint32 - 0x1000  );
	if( value >= TOne )
	{
		return Zero();
	}
	else if ( value <= -TOne)
	{
		return Pi();
	}
	else
	{
		GFixed29 x1 = GFixed29::FromGFloat(value);
		GFixed29 x2 = x1 * x1;

		GFixed29 TResult = GFixed29(1, 5707964, 10000000) - 
			x1 * (GFixed29(1, 0, 2) + 
			x2 * (GFixed29(0, 1, 6) + 
			x2 * (GFixed29(0, 3, 40) + 
			x2 * (GFixed29(0, 5, 112) +
			x2 * (GFixed29(0, 35, 1152) +
			x2 * (GFixed29(0, 63, 2816)))))));

		return TResult.ToGFloat();
	}
}
GFloat GFloat::Tan(const GFloat value) 
{
	GFloat TSin;
	GFloat TCos; 
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



template<int64_t FractionNumType>
class GFixedType64
{
public:

	explicit inline constexpr GFixedType64(int64_t raw)
		: rawInt64(raw)
	{

	}

	explicit inline constexpr GFixedType64(uint32_t a, uint32_t b, uint32_t c) :
		rawInt64(int64_t((a << FractionNumType) | ((((uint64_t)b) << FractionNumType) / c)))
	{

	}

	static inline constexpr int64_t GetTypeNumber()
	{
		return FractionNumType;
	}

	inline constexpr GFixedType64 operator +(GFixedType64 b) const
	{
		return GFixedType64(rawInt64 + b.rawInt64);
	}
	inline constexpr GFixedType64 operator +=(GFixedType64 b)
	{
		*this = *this + b;
		return *this;
	}


	inline constexpr GFixedType64 operator -() const
	{
		return GFixedType64(-rawInt64);
	}

	inline constexpr GFixedType64 operator -(GFixedType64 b) const
	{
		return GFixedType64(rawInt64 - b.rawInt64);
	}

	inline constexpr GFixedType64 operator *(GFixedType64 b) const
	{
		return GFixedType64(((int64_t)rawInt64 * (int64_t)b.rawInt64) >> FractionNumType);
	}

	static inline constexpr GFixedType64 FromGFloat(const GFloat Value)
	{
		int32_t exp = Value.getexponent() - 127 + GFixedType64<FractionNumType>::GetTypeNumber();

		if (exp >= 0)
		{
			return GFixedType64( ((int64_t)Value.getfraction()) << exp);
		}
		else
		{
			return GFixedType64(( (int64_t)Value.getfraction() )>> -exp);
		}
	}

	inline constexpr GFloat ToGFloat() const
	{
		return GFloat::Nomalize((int64_t)rawInt64, uint8_t(127 - GFixedType64<FractionNumType>::GetTypeNumber()));
	}

	int64_t rawInt64;
};

GFloat GFloat::InvSqrt(const GFloat value )
{
    if (value.rawint32 <= 0)
        return Zero();

	GFixed30 Fixed30(value.getfraction_NoShift() );

	int32_t exp = value.getexponent() - 127 + 22;
	GFixed30  Start(0);
	if(exp & 0x1)
	{
		Fixed30.rawInt32 >>= 1;
		exp += 1;
		Start =  GFixed30(1, 171, 1000);
	}
	else
	{
		
		Start = GFixed30(0, 822, 1000); //GFixed30::FromGFloat(start);
	}

	Fixed30.rawInt32 >>= 1;

	constexpr GFixed30 F1_5(1, 1, 2);

	Start = Start * (F1_5 - (Fixed30 * Start) * Start);
	Start = Start * (F1_5 - (Fixed30 * Start) * Start);
	Start = Start * (F1_5 - (Fixed30 * Start) * Start);

	GFloat TResult = GFloat::Nomalize(Start.rawInt32, uint8_t(127 - GFixed30::GetTypeNumber() - (exp >> 1)));

	return TResult;
}




