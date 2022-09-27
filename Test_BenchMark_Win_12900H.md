# GFloat Test And BenchMark
 * Test time : Tue Sep 27 22:23:46 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.43 vs  1.55  (ms)|0.28|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.45 vs  2.20  (ms)|0.20|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.44 vs  0.75  (ms)|0.58|$\checkmark$||
|Div       |  0.000008 %|      0.000024 %| 0.90 vs  2.38  (ms)|0.38|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.43 vs  2.93  (ms)|1.85||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.21 vs  0.96  (ms)|5.41||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.44 vs  5.78  (ms)|0.08|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.49 vs  8.36  (ms)|0.06|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.35 vs  0.66  (ms)|0.53|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.57 vs  7.63  (ms)|0.08|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.37 vs  4.19  (ms)|0.09|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.35 vs  0.89  (ms)|0.40|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.41 vs  1.17  (ms)|0.35|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.36 vs  0.46  (ms)|0.79|$\checkmark$||
|Sin       |  0.000115 %|      4.559921 %| 8.82 vs  7.24  (ms)|1.22||$\checkmark$|
|Cos       |  0.001734 %|      0.706807 %| 7.55 vs  8.35  (ms)|0.90|$\checkmark$||
|Tan       |  0.001712 %|      4.562861 %| 8.16 vs 16.47  (ms)|0.50|$\checkmark$||
|ASin      |  0.146195 %|      3.400623 %|10.31 vs 12.45  (ms)|0.83|$\checkmark$||
|ACos      |  0.572682 %|     98.451887 %|10.15 vs 15.74  (ms)|0.65|$\checkmark$||
|ATan      |  0.000037 %|      0.021293 %| 7.78 vs 19.84  (ms)|0.39|$\checkmark$||
|ATan(10,x)|  0.010258 %|      0.021383 %| 9.62 vs 25.91  (ms)|0.37|$\checkmark$||
|ATan(x,10)|  0.000118 %|      0.021303 %|13.06 vs 35.19  (ms)|0.37|$\checkmark$||
|Sqrt      |  0.000163 %|      0.001550 %| 0.64 vs  6.95  (ms)|0.09|$\checkmark$||
|InvSqrt   |  0.000152 %|      0.001526 %| 1.36 vs  5.81  (ms)|0.23|$\checkmark$||
|Exp       |  0.022711 %|      0.165045 %| 1.97 vs 24.14  (ms)|0.08|$\checkmark$||
|Log_e     |  0.000123 %|      0.154713 %| 2.25 vs  3.73  (ms)|0.60|$\checkmark$||
|Log_2     |  0.000122 %|      0.154716 %|19.79 vs  3.32  (ms)|5.96||$\checkmark$|
|Pow(2,x)  |  0.022471 %|      0.055202 %| 4.85 vs 31.68  (ms)|0.15|$\checkmark$||
|Pow(x,2)  |  0.011902 %|      0.064317 %| 5.47 vs 24.86  (ms)|0.22|$\checkmark$||
