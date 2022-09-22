# GFloat Test And BenchMark
 * Test time : Thu Sep 22 23:08:03 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000060 %|      5.882353 %| 0.58 vs  2.01  (ms)|0.29|$\checkmark$||
|Sub       |  0.000055 %|     11.111111 %| 0.43 vs  2.28  (ms)|0.19|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.42 vs  0.69  (ms)|0.61|$\checkmark$||
|Div       |  0.000011 %|      0.000046 %| 0.89 vs  2.12  (ms)|0.42|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 5.56 vs  3.55  (ms)|1.57||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.55 vs  1.60  (ms)|3.47||$\checkmark$|
|Whole     |  0.000004 %|      0.142857 %| 0.42 vs  6.48  (ms)|0.06|$\checkmark$||
|WholeFrac |  0.000004 %|      0.000012 %| 0.32 vs  7.36  (ms)|0.04|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.33 vs  0.83  (ms)|0.39|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.38 vs  1.05  (ms)|0.36|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.35 vs  0.52  (ms)|0.68|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.42 vs  7.10  (ms)|0.06|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %| 8.60 vs  3.15  (ms)|2.73||$\checkmark$|
|Cos       |  0.180190 %|  14521.000767 %| 8.20 vs  2.77  (ms)|2.96||$\checkmark$|
|SinCos    |  0.197822 %|   9571.942496 %|12.54 vs  7.90  (ms)|1.59||$\checkmark$|
|Tan       |  0.425105 %|  44469.206359 %| 8.17 vs  7.43  (ms)|1.10||$\checkmark$|
|ASin      |  0.474911 %|     14.587558 %| 9.81 vs  8.68  (ms)|1.13||$\checkmark$|
|ACos      |  2.121254 %|   7499.923180 %| 9.19 vs 11.14  (ms)|0.82|$\checkmark$||
|ATan      |  2.082313 %|     10.347341 %|11.19 vs 14.65  (ms)|0.76|$\checkmark$||
|ATan(10,x)|  0.002442 %|     10.290108 %| 9.46 vs 25.14  (ms)|0.38|$\checkmark$||
|ATan(x,10)|  0.003470 %|     10.345940 %| 9.90 vs 36.21  (ms)|0.27|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 0.70 vs  6.22  (ms)|0.11|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 1.31 vs  5.21  (ms)|0.25|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 2.15 vs 24.52  (ms)|0.09|$\checkmark$||
|Log       |  0.082740 %|     62.666664 %| 2.21 vs 76.49  (ms)|0.03|$\checkmark$||
|Pow(2,x)  |  0.063863 %|      0.135178 %| 4.97 vs 46.45  (ms)|0.11|$\checkmark$||
|Pow(x,2)  |  1.649633 %|     19.762378 %| 5.15 vs 49.41  (ms)|0.10|$\checkmark$||
