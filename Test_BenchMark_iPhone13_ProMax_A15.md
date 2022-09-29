# GFloat Test And BenchMark
 * Test time : Thu Sep 29 16:48:55 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Mac OSX|Apple LLVM 13.1.6 (clang-1316.0.21.2.5)|Apple Arm CPU|0.024 GHz or  0.024 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.43 vs  1.85  (ms)|0.23|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.48 vs  1.97  (ms)|0.24|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.42 vs  0.78  (ms)|0.53|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.43 vs  1.76  (ms)|0.25|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 0.25 vs  2.05  (ms)|0.12|$\checkmark$||
|Floor     |  0.000000 %|      0.000000 %| 0.24 vs  0.73  (ms)|0.32|$\checkmark$||
|Whole     |  0.000000 %|      0.000000 %| 0.25 vs  1.60  (ms)|0.16|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.23 vs  6.48  (ms)|0.04|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.22 vs  0.50  (ms)|0.45|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.40 vs  2.31  (ms)|0.17|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.24 vs  0.51  (ms)|0.47|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.21 vs  1.18  (ms)|0.18|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.23 vs  1.12  (ms)|0.21|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.21 vs  0.28  (ms)|0.75|$\checkmark$||
|Sin       |  0.000099 %|      4.559921 %| 3.62 vs  4.94  (ms)|0.73|$\checkmark$||
|Cos       |  0.001806 %|      0.122642 %| 3.62 vs  5.44  (ms)|0.67|$\checkmark$||
|Tan       |  0.001776 %|      4.562861 %| 6.26 vs 14.15  (ms)|0.44|$\checkmark$||
|ASin      |  0.031373 %|    100.000000 %| 2.67 vs  8.68  (ms)|0.31|$\checkmark$||
|ACos      |  0.117627 %|     98.413861 %| 3.29 vs 13.70  (ms)|0.24|$\checkmark$||
|ATan      |  0.003567 %|      0.036536 %| 2.52 vs 15.83  (ms)|0.16|$\checkmark$||
|ATan(10,x)|  0.006190 %|      0.021383 %| 4.62 vs 17.62  (ms)|0.26|$\checkmark$||
|ATan(x,10)|  0.007318 %|      0.230349 %| 4.33 vs 19.42  (ms)|0.22|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000084 %| 0.83 vs  5.64  (ms)|0.15|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 0.94 vs  4.64  (ms)|0.20|$\checkmark$||
|Exp       |  0.001698 %|      0.050661 %| 5.52 vs  7.03  (ms)|0.78|$\checkmark$||
|Pow2      |  0.001820 %|      0.050354 %| 1.99 vs  5.83  (ms)|0.34|$\checkmark$||
|Log_e     |  0.001206 %|     86.225453 %| 1.92 vs  3.54  (ms)|0.54|$\checkmark$||
|Log_2     |  0.001206 %|     86.225884 %| 1.96 vs  3.24  (ms)|0.60|$\checkmark$||
|Log_10    |  0.001206 %|     86.224927 %| 1.96 vs  3.53  (ms)|0.56|$\checkmark$||
|Pow(1.7,x)|  0.003043 %|      0.049457 %| 4.69 vs 15.07  (ms)|0.31|$\checkmark$||
|Pow(x,1.7)|  0.006763 %|      0.055199 %| 4.72 vs 16.31  (ms)|0.29|$\checkmark$||