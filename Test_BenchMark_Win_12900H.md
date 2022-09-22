# GFloat Test And BenchMark
 * Test time : Thu Sep 22 23:05:21 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000060 %|      5.882353 %| 0.53 vs  2.28  (ms)|0.23|$\checkmark$||
|Sub       |  0.000055 %|     11.111111 %| 0.44 vs  2.79  (ms)|0.16|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.43 vs  0.67  (ms)|0.65|$\checkmark$||
|Div       |  0.000011 %|      0.000046 %| 0.76 vs  2.45  (ms)|0.31|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 5.82 vs  2.88  (ms)|2.02||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 6.27 vs  0.90  (ms)|6.98||$\checkmark$|
|Whole     |  0.000004 %|      0.142857 %| 0.44 vs  6.24  (ms)|0.07|$\checkmark$||
|WholeFrac |  0.000004 %|      0.000012 %| 0.39 vs  8.57  (ms)|0.05|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.35 vs  0.94  (ms)|0.37|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.44 vs  1.10  (ms)|0.40|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.37 vs  0.56  (ms)|0.66|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.46 vs  8.35  (ms)|0.06|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %| 9.47 vs  3.45  (ms)|2.75||$\checkmark$|
|Cos       |  0.180190 %|  14521.000767 %| 9.13 vs  3.39  (ms)|2.69||$\checkmark$|
|SinCos    |  0.197822 %|   9571.942496 %|11.99 vs  8.08  (ms)|1.48||$\checkmark$|
|Tan       |  0.425105 %|  44469.206359 %| 8.26 vs  7.67  (ms)|1.08||$\checkmark$|
|ASin      |  0.474911 %|     14.587558 %| 9.39 vs  8.19  (ms)|1.15||$\checkmark$|
|ACos      |  2.121254 %|   7499.923180 %| 9.71 vs 10.64  (ms)|0.91|$\checkmark$||
|ATan      |  2.082313 %|     10.347341 %|10.60 vs 14.28  (ms)|0.74|$\checkmark$||
|ATan(10,x)|  0.002442 %|     10.290108 %| 9.14 vs 24.62  (ms)|0.37|$\checkmark$||
|ATan(x,10)|  0.003470 %|     10.345940 %|10.53 vs 35.91  (ms)|0.29|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 0.61 vs  6.73  (ms)|0.09|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 1.32 vs  5.02  (ms)|0.26|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 1.97 vs 25.71  (ms)|0.08|$\checkmark$||
|Log       |  0.082740 %|     62.666664 %| 2.34 vs 69.44  (ms)|0.03|$\checkmark$||
|Pow(2,x)  |  0.063863 %|      0.135178 %| 4.83 vs 47.42  (ms)|0.10|$\checkmark$||
|Pow(x,2)  |  1.649633 %|     19.762378 %| 5.10 vs 49.89  (ms)|0.10|$\checkmark$||
