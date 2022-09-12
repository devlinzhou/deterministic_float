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

GFloat GFloat::Sin(const GFloat value) 
{
    static const GFloat TPi = Pi();
    static const GFloat TOne = One();
    static const GFloat Thalf = Half();
    static const GFloat inv_Pi = TOne / Pi();
    static const GFloat inv_T6 = TOne / GFloat(6);
    static const GFloat inv_T120 = TOne / GFloat(120);
    static const GFloat inv_T5040 = TOne / GFloat(5040);

    GFloat TMod = value * inv_Pi;

    GFloat Fraction;

    int32_t TWhole = TMod.GetWhole(Fraction);

    if( Fraction > Thalf)
    {
        Fraction = TOne - Fraction;
    }
    else if(Fraction < -Thalf)
    {
        Fraction = -TOne - Fraction;
    }

    GFloat T = Fraction * TPi;
    GFloat T2 = T * T;
    GFloat T3 = T2 * T;
    GFloat T5 = T3.getexponent() < 67 ? Zero() : T2 * T3;
    GFloat T7 = T5.getexponent() < 40 ? Zero() : T5 * T2;

    GFloat OutValue = T - T3 * inv_T6 + T5 * inv_T120 - T7 * inv_T5040;

    if( TWhole % 2 == 1 || TWhole % 2 == -1)
    {
        OutValue = OutValue;
    }

	float f1 = value.toFloat();
	float f3 = sinf(f1);


	float f2 = OutValue.toFloat();

	return OutValue;

	return GFloat::FromFloat(f3);// OutValue;
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
    static const GFloat SC_Three = GFloat(3);
    static const GFloat inv_6 = One() / GFloat(6);
    static const GFloat SC_3_40 = SC_Three / GFloat(40);

    if( (value > One()) || (value <-One()) )
    {
        return Zero();
    }
    else
    {
        return value + (value * value * value) * inv_6 + (value * value * value * value * value) * SC_3_40;
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
        return GFloat(0);

    static const GFloat fone = One();
    static const GFloat fhalf = Half();
    static const GFloat threehalfs(1, 1, 2);

    int32_t txep = value.getexponent() - 127 + 22;

    GFloat y = (txep & 0x1) == 0 ? GFloat::FromFractionAndExp(0x679851, 127 - txep / 2 + -23) : GFloat::FromFractionAndExp(0x265064, 127 - txep / 2 + -22);

    GFloat x2 = value * fhalf;
    y = y * (threehalfs - ((x2 * y) * y));
    y = y * (threehalfs - ((x2 * y) * y));

    return y;
}




