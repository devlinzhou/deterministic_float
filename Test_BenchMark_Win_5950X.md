# GFloat Test And BenchMark
 * Test time : Fri Sep 23 19:51:23 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000060 %|      5.882353 %| 0.63 vs  2.63  (ms)|0.24|$\checkmark$||
|Sub       |  0.000055 %|     11.111111 %| 0.57 vs  3.10  (ms)|0.18|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.70 vs  1.14  (ms)|0.61|$\checkmark$||
|Div       |  0.000011 %|      0.000046 %| 0.80 vs  2.61  (ms)|0.31|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 5.62 vs  3.88  (ms)|1.45||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.67 vs  0.98  (ms)|5.79||$\checkmark$|
|Whole     |  0.000004 %|      0.142857 %| 0.48 vs  6.04  (ms)|0.08|$\checkmark$||
|WholeFrac |  0.000004 %|      0.000012 %| 0.40 vs 11.54  (ms)|0.03|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.39 vs  1.70  (ms)|0.23|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.55 vs  1.94  (ms)|0.28|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.46 vs  0.70  (ms)|0.65|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.65 vs  8.87  (ms)|0.07|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %|10.20 vs  4.99  (ms)|2.04||$\checkmark$|
|Cos       |  0.180190 %|  14521.000767 %|10.29 vs  4.66  (ms)|2.21||$\checkmark$|
|SinCos    |  0.197822 %|   9571.942496 %|13.20 vs 13.56  (ms)|0.97|$\checkmark$||
|Tan       |  0.425105 %|  44469.206359 %| 9.96 vs 11.43  (ms)|0.87|$\checkmark$||
|ASin      |  0.474911 %|     14.587558 %|11.03 vs 13.70  (ms)|0.81|$\checkmark$||
|ACos      |  2.121254 %|   7499.923180 %| 9.89 vs 17.74  (ms)|0.56|$\checkmark$||
|ATan      |  2.082313 %|     10.347341 %|10.90 vs 19.90  (ms)|0.55|$\checkmark$||
|ATan(10,x)|  0.002442 %|     10.290108 %| 8.87 vs 29.78  (ms)|0.30|$\checkmark$||
|ATan(x,10)|  0.003470 %|     10.345940 %| 9.32 vs 44.85  (ms)|0.21|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 1.08 vs  9.29  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 1.84 vs  7.70  (ms)|0.24|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 2.06 vs 29.81  (ms)|0.07|$\checkmark$||
|Log       |  0.082740 %|     62.666664 %| 2.76 vs 101.85  (ms)|0.03|$\checkmark$||
|Pow(2,x)  |  0.063863 %|      0.135178 %| 5.66 vs 62.37  (ms)|0.09|$\checkmark$||
|Pow(x,2)  |  1.649633 %|     19.762378 %| 5.64 vs 63.70  (ms)|0.09|$\checkmark$||
