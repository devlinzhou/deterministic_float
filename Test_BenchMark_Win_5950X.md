# GFloat Test And BenchMark
 * Test time : Fri Sep 23 19:57:11 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000060 %|      5.882353 %| 0.58 vs  2.42  (ms)|0.24|$\checkmark$||
|Sub       |  0.000055 %|     11.111111 %| 0.48 vs  3.08  (ms)|0.15|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.59 vs  1.14  (ms)|0.51|$\checkmark$||
|Div       |  0.000011 %|      0.000046 %| 0.75 vs  2.53  (ms)|0.30|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 5.47 vs  4.00  (ms)|1.37||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.52 vs  1.08  (ms)|5.14||$\checkmark$|
|Whole     |  0.000004 %|      0.142857 %| 0.48 vs  5.98  (ms)|0.08|$\checkmark$||
|WholeFrac |  0.000004 %|      0.000012 %| 0.39 vs 11.58  (ms)|0.03|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.39 vs  1.68  (ms)|0.23|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.45 vs  1.79  (ms)|0.25|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.33 vs  0.65  (ms)|0.50|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.47 vs  7.88  (ms)|0.06|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %| 9.44 vs  4.42  (ms)|2.14||$\checkmark$|
|Cos       |  0.180190 %|  14521.000767 %| 9.28 vs  4.36  (ms)|2.13||$\checkmark$|
|SinCos    |  0.197822 %|   9571.942496 %|12.89 vs 13.09  (ms)|0.98|$\checkmark$||
|Tan       |  0.425105 %|  44469.206359 %| 9.15 vs 10.52  (ms)|0.87|$\checkmark$||
|ASin      |  0.474911 %|     14.587558 %|10.39 vs 12.74  (ms)|0.82|$\checkmark$||
|ACos      |  2.121254 %|   7499.923180 %| 9.74 vs 17.19  (ms)|0.57|$\checkmark$||
|ATan      |  2.082313 %|     10.347341 %|10.61 vs 19.99  (ms)|0.53|$\checkmark$||
|ATan(10,x)|  0.002442 %|     10.290108 %| 8.57 vs 29.67  (ms)|0.29|$\checkmark$||
|ATan(x,10)|  0.003470 %|     10.345940 %| 8.96 vs 43.30  (ms)|0.21|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 1.07 vs  9.13  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 1.90 vs  8.00  (ms)|0.24|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 3.47 vs 33.88  (ms)|0.10|$\checkmark$||
|Log       |  0.082740 %|     62.666664 %| 3.30 vs 106.24  (ms)|0.03|$\checkmark$||
|Pow(2,x)  |  0.063863 %|      0.135178 %| 5.59 vs 61.84  (ms)|0.09|$\checkmark$||
|Pow(x,2)  |  1.649633 %|     19.762378 %| 5.68 vs 67.22  (ms)|0.08|$\checkmark$||
