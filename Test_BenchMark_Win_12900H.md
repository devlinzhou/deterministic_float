# GFloat Test And BenchMark
 * Test time : Sun Sep 25 23:43:48 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000062 %|      5.882353 %| 0.55 vs  1.71  (ms)|0.32|$\checkmark$||
|Sub       |  0.000057 %|     11.111111 %| 0.50 vs  2.53  (ms)|0.20|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.47 vs  0.70  (ms)|0.67|$\checkmark$||
|Div       |  0.000011 %|      0.000046 %| 0.76 vs  2.37  (ms)|0.32|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 6.13 vs  2.68  (ms)|2.29||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.27 vs  0.87  (ms)|6.06||$\checkmark$|
|Whole     |  0.000004 %|      0.142857 %| 0.48 vs  6.03  (ms)|0.08|$\checkmark$||
|WholeFrac |  0.005677 %|    100.000000 %| 0.37 vs  8.65  (ms)|0.04|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.38 vs  0.91  (ms)|0.42|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.43 vs  1.12  (ms)|0.38|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.40 vs  0.63  (ms)|0.65|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.45 vs  8.40  (ms)|0.05|$\checkmark$||
|Abs       |  0.000004 %|      0.000012 %| 0.38 vs  4.77  (ms)|0.08|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %| 9.00 vs  3.23  (ms)|2.78||$\checkmark$|
|Cos       |  0.180190 %|  14521.000767 %| 9.30 vs  3.20  (ms)|2.91||$\checkmark$|
|SinCos    |  4.426869 %|   9571.942496 %|13.94 vs  9.18  (ms)|1.52||$\checkmark$|
|Tan       |  0.425105 %|  44469.206359 %| 9.35 vs  8.51  (ms)|1.10||$\checkmark$|
|ASin      |  0.474911 %|     14.587558 %|10.59 vs  9.04  (ms)|1.17||$\checkmark$|
|ACos      |  4.105913 %|   7499.923180 %|10.73 vs 12.93  (ms)|0.83|$\checkmark$||
|ATan      |  2.082307 %|     10.347341 %|12.05 vs 16.55  (ms)|0.73|$\checkmark$||
|ATan(10,x)|  0.083049 %|     18.788355 %|10.16 vs 28.53  (ms)|0.36|$\checkmark$||
|ATan(x,10)|  0.325797 %|     18.915966 %| 9.51 vs 41.87  (ms)|0.23|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 0.71 vs  7.29  (ms)|0.10|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 1.32 vs  5.50  (ms)|0.24|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 2.14 vs 27.27  (ms)|0.08|$\checkmark$||
|Log       |  0.964962 %|     63.366195 %| 2.53 vs 88.34  (ms)|0.03|$\checkmark$||
|Pow(2,x)  |  0.063863 %|      0.135178 %| 5.61 vs 51.40  (ms)|0.11|$\checkmark$||
|Pow(x,2)  | 14.645927 %|     64.879200 %| 5.50 vs 60.37  (ms)|0.09|$\checkmark$||
