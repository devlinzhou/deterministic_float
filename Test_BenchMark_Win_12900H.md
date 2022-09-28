# GFloat Test And BenchMark
 * Test time : Wed Sep 28 23:57:55 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.55 vs  1.79  (ms)|0.31|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.42 vs  2.18  (ms)|0.19|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.41 vs  0.69  (ms)|0.60|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.67 vs  2.22  (ms)|0.30|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.49 vs  2.47  (ms)|2.23||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 6.09 vs  0.96  (ms)|6.37||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.41 vs  4.59  (ms)|0.09|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.32 vs  5.96  (ms)|0.05|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.34 vs  0.54  (ms)|0.62|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.42 vs  8.03  (ms)|0.05|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.36 vs  3.99  (ms)|0.09|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.32 vs  0.85  (ms)|0.38|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.40 vs  1.12  (ms)|0.36|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.32 vs  0.42  (ms)|0.77|$\checkmark$||
|Sin       |  0.000099 %|      4.559921 %| 7.39 vs  6.44  (ms)|1.15||$\checkmark$|
|Cos       |  0.001805 %|      0.122642 %| 7.74 vs  8.43  (ms)|0.92|$\checkmark$||
|Tan       |  0.001776 %|      4.562861 %| 7.03 vs 13.88  (ms)|0.51|$\checkmark$||
|ASin      |  0.031373 %|    100.000000 %| 7.16 vs 12.46  (ms)|0.57|$\checkmark$||
|ACos      |  0.117627 %|     98.413861 %| 7.24 vs 16.61  (ms)|0.44|$\checkmark$||
|ATan      |  0.003567 %|      0.036536 %| 8.09 vs 18.15  (ms)|0.45|$\checkmark$||
|ATan(10,x)|  0.006190 %|      0.021383 %|11.15 vs 24.22  (ms)|0.46|$\checkmark$||
|ATan(x,10)|  0.007318 %|      0.230349 %|10.74 vs 22.79  (ms)|0.47|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000084 %| 0.61 vs  6.92  (ms)|0.09|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.23 vs  6.20  (ms)|0.20|$\checkmark$||
|Exp       |  0.001698 %|      0.050661 %| 2.02 vs  7.27  (ms)|0.28|$\checkmark$||
|Pow2      |  0.001820 %|      0.050354 %| 5.25 vs  6.00  (ms)|0.87|$\checkmark$||
|Log_e     |  0.001206 %|     86.225453 %| 2.53 vs  4.10  (ms)|0.62|$\checkmark$||
|Log_2     |  0.001206 %|     86.225884 %|20.12 vs  3.65  (ms)|5.51||$\checkmark$|
|Log_10    |  0.001206 %|     86.224927 %| 2.36 vs  3.57  (ms)|0.66|$\checkmark$||
|Pow(1.7,x)|  0.003043 %|      0.049457 %| 5.29 vs 16.74  (ms)|0.32|$\checkmark$||
|Pow(x,1.7)|  0.006763 %|      0.055199 %| 5.28 vs 16.79  (ms)|0.31|$\checkmark$||
