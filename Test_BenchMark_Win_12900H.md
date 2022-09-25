# GFloat Test And BenchMark
 * Test time : Sun Sep 25 23:26:39 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000062 %|      5.882353 %| 0.45 vs  1.60  (ms)|0.28|$\checkmark$||
|Sub       |  0.000057 %|     11.111111 %| 0.43 vs  2.18  (ms)|0.20|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.44 vs  0.74  (ms)|0.60|$\checkmark$||
|Div       |  0.000011 %|      0.000046 %| 0.67 vs  2.32  (ms)|0.29|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 5.93 vs  2.82  (ms)|2.10||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.68 vs  0.90  (ms)|6.33||$\checkmark$|
|Whole     |  0.000004 %|      0.142857 %| 0.38 vs  5.38  (ms)|0.07|$\checkmark$||
|WholeFrac |  0.005677 %|    100.000000 %| 0.34 vs  7.70  (ms)|0.04|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.44 vs  0.89  (ms)|0.50|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.39 vs  1.14  (ms)|0.34|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.34 vs  0.56  (ms)|0.60|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.41 vs  8.41  (ms)|0.05|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %| 8.54 vs  3.23  (ms)|2.65||$\checkmark$|
|Cos       |  0.180190 %|  14521.000767 %| 8.40 vs  2.94  (ms)|2.86||$\checkmark$|
|SinCos    |  4.426869 %|   9571.942496 %|11.91 vs  9.23  (ms)|1.29||$\checkmark$|
|Tan       |  0.425105 %|  44469.206359 %| 8.46 vs  7.72  (ms)|1.10||$\checkmark$|
|ASin      |  0.474911 %|     14.587558 %|10.03 vs 10.58  (ms)|0.95|$\checkmark$||
|ACos      |  4.105913 %|   7499.923180 %| 9.42 vs 11.85  (ms)|0.80|$\checkmark$||
|ATan      |  2.082307 %|     10.347341 %|11.34 vs 16.06  (ms)|0.71|$\checkmark$||
|ATan(10,x)|  0.083049 %|     18.788355 %| 9.95 vs 28.01  (ms)|0.36|$\checkmark$||
|ATan(x,10)|  0.325797 %|     18.915966 %| 9.65 vs 40.18  (ms)|0.24|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 0.61 vs  6.21  (ms)|0.10|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 1.40 vs  5.05  (ms)|0.28|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 2.00 vs 24.77  (ms)|0.08|$\checkmark$||
|Log       |  0.964962 %|     63.366195 %| 2.43 vs 81.89  (ms)|0.03|$\checkmark$||
|Pow(2,x)  |  0.063863 %|      0.135178 %| 5.02 vs 49.99  (ms)|0.10|$\checkmark$||
|Pow(x,2)  | 14.645927 %|     64.879200 %| 4.92 vs 53.56  (ms)|0.09|$\checkmark$||
