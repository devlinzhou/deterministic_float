# GFloat Test And BenchMark
 * Test time : Mon Sep 26 19:57:26 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000000 %|      0.000000 %| 0.59 vs  2.36  (ms)|0.25|$\checkmark$||
|Sub       |  0.000055 %|     11.111111 %| 0.55 vs  3.36  (ms)|0.16|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.57 vs  1.10  (ms)|0.52|$\checkmark$||
|Div       |  0.000011 %|      0.000046 %| 0.76 vs  2.47  (ms)|0.31|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 5.77 vs  3.81  (ms)|1.51||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.38 vs  1.02  (ms)|5.29||$\checkmark$|
|Whole     |  0.000004 %|      0.142857 %| 0.47 vs  5.95  (ms)|0.08|$\checkmark$||
|WholeFrac |  0.000004 %|      0.000012 %| 0.45 vs 13.17  (ms)|0.03|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.44 vs  1.64  (ms)|0.27|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.52 vs  1.88  (ms)|0.28|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.43 vs  0.82  (ms)|0.53|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.59 vs  8.48  (ms)|0.07|$\checkmark$||
|Abs       |  0.000004 %|      0.000012 %| 0.38 vs  3.69  (ms)|0.10|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %| 9.75 vs  4.55  (ms)|2.14||$\checkmark$|
|Cos       |  0.180190 %|  14521.000767 %| 9.60 vs  4.43  (ms)|2.17||$\checkmark$|
|SinCos    |  0.197822 %|   9571.942496 %|13.14 vs 13.72  (ms)|0.96|$\checkmark$||
|Tan       |  0.425105 %|  44469.206359 %| 9.19 vs 10.92  (ms)|0.84|$\checkmark$||
|ASin      |  0.474911 %|     14.587558 %|10.53 vs 13.35  (ms)|0.79|$\checkmark$||
|ACos      |  2.121254 %|   7499.923180 %| 9.75 vs 17.79  (ms)|0.55|$\checkmark$||
|ATan      |  2.082307 %|     10.347341 %|10.47 vs 17.08  (ms)|0.61|$\checkmark$||
|ATan(10,x)|  0.002442 %|     10.290108 %| 8.73 vs 30.13  (ms)|0.29|$\checkmark$||
|ATan(x,10)|  0.003470 %|     10.345940 %| 9.05 vs 36.74  (ms)|0.25|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 1.07 vs  9.40  (ms)|0.11|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 1.82 vs  7.83  (ms)|0.23|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 2.00 vs 29.58  (ms)|0.07|$\checkmark$||
|Log_e     |  0.000127 %|      0.154715 %| 2.62 vs  5.31  (ms)|0.49|$\checkmark$||
|Log_2     |  0.000126 %|      0.154719 %|22.14 vs  4.94  (ms)|4.48||$\checkmark$|
|Pow(2,x)  |  0.023150 %|      0.055209 %| 5.70 vs 39.18  (ms)|0.15|$\checkmark$||
|Pow(x,2)  |  0.012264 %|      0.064328 %| 6.05 vs 31.04  (ms)|0.20|$\checkmark$||
