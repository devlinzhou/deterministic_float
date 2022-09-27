# GFloat Test And BenchMark
 * Test time : Wed Sep 28 00:20:46 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.43 vs  1.43  (ms)|0.30|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.50 vs  2.63  (ms)|0.19|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.44 vs  0.70  (ms)|0.62|$\checkmark$||
|Div       |  0.000008 %|      0.000024 %| 0.65 vs  2.39  (ms)|0.27|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.74 vs  2.92  (ms)|1.97||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.11 vs  0.90  (ms)|5.66||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.39 vs  5.57  (ms)|0.07|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.33 vs  7.34  (ms)|0.05|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.34 vs  0.58  (ms)|0.58|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.43 vs  7.58  (ms)|0.06|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.34 vs  4.03  (ms)|0.08|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.33 vs  0.83  (ms)|0.40|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.38 vs  1.02  (ms)|0.37|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.31 vs  0.39  (ms)|0.80|$\checkmark$||
|Sin       |  0.000115 %|      4.559921 %| 8.24 vs  6.58  (ms)|1.25||$\checkmark$|
|Cos       |  0.001734 %|      0.706807 %| 8.08 vs  8.08  (ms)|1.00|$\checkmark$||
|Tan       |  0.001712 %|      4.562861 %| 7.98 vs 13.60  (ms)|0.59|$\checkmark$||
|ASin      |  0.146195 %|      3.400623 %| 9.33 vs 10.88  (ms)|0.86|$\checkmark$||
|ACos      |  0.572682 %|     98.451887 %| 8.71 vs 13.79  (ms)|0.63|$\checkmark$||
|ATan      |  0.000037 %|      0.021293 %| 7.13 vs 19.58  (ms)|0.36|$\checkmark$||
|ATan(10,x)|  0.010258 %|      0.021383 %| 9.37 vs 25.31  (ms)|0.37|$\checkmark$||
|ATan(x,10)|  0.000118 %|      0.021303 %| 9.22 vs 33.27  (ms)|0.28|$\checkmark$||
|Sqrt      |  0.000163 %|      0.001550 %| 0.62 vs  6.00  (ms)|0.10|$\checkmark$||
|InvSqrt   |  0.000152 %|      0.001526 %| 1.17 vs  5.46  (ms)|0.21|$\checkmark$||
|Exp       |  0.004443 %|      0.050696 %| 1.96 vs 12.85  (ms)|0.15|$\checkmark$||
|Pow2      |  0.004395 %|      0.050354 %| 4.73 vs  9.89  (ms)|0.48|$\checkmark$||
|Log_e     |  0.000123 %|      0.154713 %| 2.19 vs  3.57  (ms)|0.61|$\checkmark$||
|Log_2     |  0.000122 %|      0.154716 %|18.38 vs  3.14  (ms)|5.86||$\checkmark$|
|Log_10    |  0.000122 %|      0.154691 %| 2.35 vs  3.25  (ms)|0.72|$\checkmark$||
|Pow(2,x)  |  0.031955 %|      0.109520 %| 4.79 vs 16.63  (ms)|0.29|$\checkmark$||
|Pow(x,2)  |  0.002345 %|      0.048492 %| 4.98 vs 19.25  (ms)|0.26|$\checkmark$||
