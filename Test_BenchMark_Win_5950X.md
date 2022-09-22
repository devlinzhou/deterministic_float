# GFloat Test And BenchMark
 * Test time : Thu Sep 22 20:33:09 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000060 %|      5.882353 %| 0.54 vs  3.48  (ms)|0.16|$\checkmark$||
|Sub       |  0.000055 %|     11.111111 %| 0.55 vs  4.48  (ms)|0.12|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.56 vs  1.27  (ms)|0.44|$\checkmark$||
|Div       |  0.000011 %|      0.000047 %| 0.77 vs  2.85  (ms)|0.27|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 5.42 vs  5.13  (ms)|1.06||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.51 vs  1.28  (ms)|4.32||$\checkmark$|
|Whole     |  0.000004 %|      0.142857 %| 0.57 vs  6.50  (ms)|0.09|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.48 vs  2.12  (ms)|0.23|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.45 vs  1.83  (ms)|0.25|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.37 vs  0.77  (ms)|0.48|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.53 vs  8.85  (ms)|0.06|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %| 9.78 vs  5.20  (ms)|1.88||$\checkmark$|
|Cos       |  0.180190 %|  14521.000767 %| 9.90 vs  4.91  (ms)|2.02||$\checkmark$|
|Tan       |  0.425105 %|  44469.206359 %| 9.39 vs 11.59  (ms)|0.81|$\checkmark$||
|ASin      |  0.474911 %|     14.587558 %|10.54 vs 13.26  (ms)|0.79|$\checkmark$||
|ACos      |  2.121254 %|   7499.923180 %| 9.72 vs 18.51  (ms)|0.53|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 1.11 vs 11.53  (ms)|0.10|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 1.86 vs  8.84  (ms)|0.21|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 2.19 vs 32.35  (ms)|0.07|$\checkmark$||
|Log       |  0.082740 %|     62.666664 %| 2.88 vs 111.17  (ms)|0.03|$\checkmark$||
