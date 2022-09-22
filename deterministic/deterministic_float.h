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

class TestGFloat
{
public:
    
    void Run();
};
#define MYOperater( a, b, c, TOperator ) \
{\
	for (int i = 0; i < N; i+=10 )\
	{\
		c[i+ 0] = b[i+0] TOperator a[i+0];\
		c[i+ 1] = b[i+1] TOperator a[i+1];\
		c[i+ 2] = b[i+2] TOperator a[i+2];\
		c[i+ 3] = b[i+3] TOperator a[i+3];\
		c[i+ 4] = b[i+4] TOperator a[i+4];\
		c[i+ 5] = b[i+5] TOperator a[i+5];\
		c[i+ 6] = b[i+6] TOperator a[i+6];\
		c[i+ 7] = b[i+7] TOperator a[i+7];\
		c[i+ 8] = b[i+8] TOperator a[i+8];\
		c[i+ 9] = b[i+9] TOperator a[i+9];\
	}\
}\

#define MYOneFun( a, c, TFun ) \
{\
	for (int i = 0; i < N; i+=10 )\
	{\
		c[i+ 0] = TFun(a[i+ 0]);\
		c[i+ 1] = TFun(a[i+ 1]);\
		c[i+ 2] = TFun(a[i+ 2]);\
		c[i+ 3] = TFun(a[i+ 3]);\
		c[i+ 4] = TFun(a[i+ 4]);\
		c[i+ 5] = TFun(a[i+ 5]);\
		c[i+ 6] = TFun(a[i+ 6]);\
		c[i+ 7] = TFun(a[i+ 7]);\
		c[i+ 8] = TFun(a[i+ 8]);\
		c[i+ 9] = TFun(a[i+ 9]);\
	}\
}\

#define MYOneGetWhole( a, c, TFun ) \
{\
	for (int i = 0; i < N; i+=10 )\
	{\
		c[i+ 0] = GFloat(a[i+ 0].TFun());\
		c[i+ 1] = GFloat(a[i+ 1].TFun());\
		c[i+ 2] = GFloat(a[i+ 2].TFun());\
		c[i+ 3] = GFloat(a[i+ 3].TFun());\
		c[i+ 4] = GFloat(a[i+ 4].TFun());\
		c[i+ 5] = GFloat(a[i+ 5].TFun());\
		c[i+ 6] = GFloat(a[i+ 6].TFun());\
		c[i+ 7] = GFloat(a[i+ 7].TFun());\
		c[i+ 8] = GFloat(a[i+ 8].TFun());\
		c[i+ 9] = GFloat(a[i+ 9].TFun());\
	}\
}\


#define MYOneNormalize( a, c ) \
{\
	for (int i = 0; i < N; i+=10 )\
	{\
        c[i+ 0] = GFloat::Normalize(a[i+ 0].getfraction(), a[i+ 0].getexponent());\
        c[i+ 1] = GFloat::Normalize(a[i+ 1].getfraction(), a[i+ 1].getexponent());\
        c[i+ 2] = GFloat::Normalize(a[i+ 2].getfraction(), a[i+ 2].getexponent());\
        c[i+ 3] = GFloat::Normalize(a[i+ 3].getfraction(), a[i+ 3].getexponent());\
        c[i+ 4] = GFloat::Normalize(a[i+ 4].getfraction(), a[i+ 4].getexponent());\
        c[i+ 5] = GFloat::Normalize(a[i+ 5].getfraction(), a[i+ 5].getexponent());\
        c[i+ 6] = GFloat::Normalize(a[i+ 6].getfraction(), a[i+ 6].getexponent());\
        c[i+ 7] = GFloat::Normalize(a[i+ 7].getfraction(), a[i+ 7].getexponent());\
        c[i+ 8] = GFloat::Normalize(a[i+ 8].getfraction(), a[i+ 8].getexponent());\
        c[i+ 9] = GFloat::Normalize(a[i+ 9].getfraction(), a[i+ 9].getexponent());\
	}\
}\

#define MYOperaterLess( a, b, c ) \
{\
	for (int i = 0; i < N; i+=10 )\
	{\
        c[i+ 0] = a[i+ 0] < b[i+ 0] ? a[i+ 0] : b[i+ 0];\
        c[i+ 1] = a[i+ 1] < b[i+ 1] ? a[i+ 1] : b[i+ 1];\
        c[i+ 2] = a[i+ 2] < b[i+ 2] ? a[i+ 2] : b[i+ 2];\
        c[i+ 3] = a[i+ 3] < b[i+ 3] ? a[i+ 3] : b[i+ 3];\
        c[i+ 4] = a[i+ 4] < b[i+ 4] ? a[i+ 4] : b[i+ 4];\
        c[i+ 5] = a[i+ 5] < b[i+ 5] ? a[i+ 5] : b[i+ 5];\
        c[i+ 6] = a[i+ 6] < b[i+ 6] ? a[i+ 6] : b[i+ 6];\
        c[i+ 7] = a[i+ 7] < b[i+ 7] ? a[i+ 7] : b[i+ 7];\
        c[i+ 8] = a[i+ 8] < b[i+ 8] ? a[i+ 8] : b[i+ 8];\
        c[i+ 9] = a[i+ 9] < b[i+ 9] ? a[i+ 9] : b[i+ 9];\
	}\
}\



