# GFloat Test And BenchMark
 * Test time : Tue Sep 27 23:44:57 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.46 vs  1.66  (ms)|0.28|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.44 vs  2.21  (ms)|0.20|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.43 vs  0.73  (ms)|0.59|$\checkmark$||
|Div       |  0.000008 %|      0.000024 %| 0.60 vs  1.96  (ms)|0.31|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.40 vs  2.61  (ms)|2.07||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.80 vs  1.00  (ms)|5.81||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.45 vs  6.52  (ms)|0.07|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.37 vs  7.90  (ms)|0.05|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.35 vs  0.67  (ms)|0.52|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.52 vs  7.45  (ms)|0.07|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.36 vs  4.27  (ms)|0.08|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.34 vs  0.83  (ms)|0.41|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.38 vs  1.01  (ms)|0.37|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.38 vs  0.44  (ms)|0.86|$\checkmark$||
|Sin       |  0.000115 %|      4.559921 %| 8.86 vs  6.85  (ms)|1.29||$\checkmark$|
|Cos       |  0.001734 %|      0.706807 %| 8.55 vs  8.38  (ms)|1.02||$\checkmark$|
|Tan       |  0.001712 %|      4.562861 %| 8.79 vs 15.63  (ms)|0.56|$\checkmark$||
|ASin      |  0.146195 %|      3.400623 %|10.17 vs 11.76  (ms)|0.87|$\checkmark$||
|ACos      |  0.572682 %|     98.451887 %| 8.95 vs 17.08  (ms)|0.52|$\checkmark$||
|ATan      |  0.000037 %|      0.021293 %| 7.06 vs 19.53  (ms)|0.36|$\checkmark$||
|ATan(10,x)|  0.010258 %|      0.021383 %| 9.80 vs 26.38  (ms)|0.37|$\checkmark$||
|ATan(x,10)|  0.000118 %|      0.021303 %| 9.18 vs 31.76  (ms)|0.29|$\checkmark$||
|Sqrt      |  0.000163 %|      0.001550 %| 0.59 vs  6.32  (ms)|0.09|$\checkmark$||
|InvSqrt   |  0.000152 %|      0.001526 %| 1.27 vs  5.25  (ms)|0.24|$\checkmark$||
|Exp       |  0.004443 %|      0.050696 %| 2.28 vs 14.12  (ms)|0.16|$\checkmark$||
|Pow2      |  0.004395 %|      0.050354 %| 5.05 vs  9.80  (ms)|0.52|$\checkmark$||
|Log_e     |  0.000123 %|      0.154713 %| 2.50 vs  3.65  (ms)|0.69|$\checkmark$||
|Log_2     |  0.000122 %|      0.154716 %|19.70 vs  3.46  (ms)|5.70||$\checkmark$|
|Pow(2,x)  |  0.031955 %|      0.109520 %| 4.71 vs 17.41  (ms)|0.27|$\checkmark$||
|Pow(x,2)  |  0.002345 %|      0.048492 %| 4.89 vs 18.67  (ms)|0.26|$\checkmark$||
