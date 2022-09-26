# GFloat Test And BenchMark
 * Test time : Mon Sep 26 21:29:15 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000000 %|      0.000000 %| 0.44 vs  1.61  (ms)|0.27|$\checkmark$||
|Sub       |  0.000055 %|     11.111111 %| 0.44 vs  3.77  (ms)|0.12|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.44 vs  0.70  (ms)|0.63|$\checkmark$||
|Div       |  0.000011 %|      0.000046 %| 0.64 vs  2.03  (ms)|0.31|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 5.40 vs  2.68  (ms)|2.01||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.85 vs  0.93  (ms)|6.30||$\checkmark$|
|Whole     |  0.000004 %|      0.142857 %| 0.53 vs  5.78  (ms)|0.09|$\checkmark$||
|WholeFrac |  0.000004 %|      0.000012 %| 0.32 vs  8.28  (ms)|0.04|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.33 vs  0.83  (ms)|0.40|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.52 vs  1.25  (ms)|0.41|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.36 vs  0.54  (ms)|0.66|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.43 vs  7.46  (ms)|0.06|$\checkmark$||
|Abs       |  0.000004 %|      0.000012 %| 0.33 vs  4.24  (ms)|0.08|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %| 8.18 vs  2.96  (ms)|2.76||$\checkmark$|
|Cos       |  0.180190 %|  14521.000767 %|10.24 vs  3.23  (ms)|3.17||$\checkmark$|
|SinCos    |  0.197822 %|   9571.942496 %|13.11 vs  8.55  (ms)|1.53||$\checkmark$|
|Tan       |  0.425105 %|  44469.206359 %| 8.57 vs  8.11  (ms)|1.06||$\checkmark$|
|ASin      |  0.474911 %|     14.587558 %|10.00 vs  8.93  (ms)|1.12||$\checkmark$|
|ACos      |  2.121254 %|   7499.923180 %| 9.22 vs 11.55  (ms)|0.80|$\checkmark$||
|ATan      |  2.082307 %|     10.347341 %|11.23 vs 12.05  (ms)|0.93|$\checkmark$||
|ATan(10,x)|  0.002442 %|     10.290108 %| 9.12 vs 25.08  (ms)|0.36|$\checkmark$||
|ATan(x,10)|  0.003470 %|     10.345940 %| 9.22 vs 31.69  (ms)|0.29|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 0.65 vs  6.25  (ms)|0.10|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 1.31 vs  5.60  (ms)|0.23|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 2.60 vs 24.32  (ms)|0.11|$\checkmark$||
|Log_e     |  0.000127 %|      0.154715 %| 2.66 vs  4.13  (ms)|0.64|$\checkmark$||
|Log_2     |  0.000126 %|      0.154719 %|19.23 vs  3.48  (ms)|5.52||$\checkmark$|
|Pow(2,x)  |  0.023150 %|      0.055209 %| 4.73 vs 31.70  (ms)|0.15|$\checkmark$||
|Pow(x,2)  |  0.012264 %|      0.064328 %| 4.72 vs 25.60  (ms)|0.18|$\checkmark$||
