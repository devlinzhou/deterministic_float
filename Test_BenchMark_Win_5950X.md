# GFloat Test And BenchMark
 * Test time : Tue Sep 27 17:54:17 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.48 vs  2.99  (ms)|0.16|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.56 vs  3.98  (ms)|0.14|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.51 vs  1.45  (ms)|0.35|$\checkmark$||
|Div       |  0.000008 %|      0.000024 %| 0.76 vs  3.22  (ms)|0.24|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 6.64 vs  4.00  (ms)|1.66||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.77 vs  1.21  (ms)|4.79||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.57 vs  6.20  (ms)|0.09|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.38 vs 12.96  (ms)|0.03|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.37 vs  0.85  (ms)|0.43|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.51 vs  9.11  (ms)|0.06|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.39 vs  3.88  (ms)|0.10|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.34 vs  1.68  (ms)|0.20|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.49 vs  1.96  (ms)|0.25|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.35 vs  0.62  (ms)|0.56|$\checkmark$||
|Sin       |  0.000115 %|      4.559921 %| 9.95 vs  8.31  (ms)|1.20||$\checkmark$|
|Cos       |  0.001734 %|      0.706807 %| 9.63 vs  9.51  (ms)|1.01||$\checkmark$|
|Tan       |  0.001712 %|      4.562861 %| 9.55 vs 18.52  (ms)|0.52|$\checkmark$||
|ASin      |  1.965014 %|      3.286537 %|11.26 vs 11.48  (ms)|0.98|$\checkmark$||
|ACos      |  0.823199 %|   3974.888581 %|10.45 vs 11.24  (ms)|0.93|$\checkmark$||
|ATan      |  0.000037 %|      0.021293 %| 7.27 vs 27.19  (ms)|0.27|$\checkmark$||
|ATan(10,x)|  0.010258 %|      0.021383 %| 9.03 vs 32.49  (ms)|0.28|$\checkmark$||
|ATan(x,10)|  0.000118 %|      0.021303 %|11.36 vs 38.85  (ms)|0.29|$\checkmark$||
|Sqrt      |  0.000163 %|      0.001550 %| 1.09 vs  9.64  (ms)|0.11|$\checkmark$||
|InvSqrt   |  0.000152 %|      0.001526 %| 1.85 vs  8.15  (ms)|0.23|$\checkmark$||
|Exp       |  0.022711 %|      0.165045 %| 2.18 vs 30.61  (ms)|0.07|$\checkmark$||
|Log_e     |  0.000123 %|      0.154713 %| 2.75 vs  5.33  (ms)|0.52|$\checkmark$||
|Log_2     |  0.000122 %|      0.154716 %|22.57 vs  5.20  (ms)|4.34||$\checkmark$|
|Pow(2,x)  |  0.022471 %|      0.055202 %| 5.85 vs 39.65  (ms)|0.15|$\checkmark$||
|Pow(x,2)  |  0.011902 %|      0.064317 %| 5.80 vs 31.37  (ms)|0.18|$\checkmark$||
