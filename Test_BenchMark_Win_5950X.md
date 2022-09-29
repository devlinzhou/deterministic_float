# GFloat Test And BenchMark
 * Test time : Thu Sep 29 11:44:17 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.58 vs  2.69  (ms)|0.21|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.53 vs  3.37  (ms)|0.16|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.61 vs  1.21  (ms)|0.51|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.81 vs  2.68  (ms)|0.30|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 6.05 vs  3.92  (ms)|1.54||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.74 vs  1.18  (ms)|4.88||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.58 vs  5.54  (ms)|0.10|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.41 vs  7.79  (ms)|0.05|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.38 vs  0.74  (ms)|0.51|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.54 vs  8.47  (ms)|0.06|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.34 vs  3.73  (ms)|0.09|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.45 vs  1.76  (ms)|0.25|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.51 vs  1.96  (ms)|0.26|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.41 vs  0.65  (ms)|0.63|$\checkmark$||
|Sin       |  0.000099 %|      4.559921 %| 9.03 vs  8.48  (ms)|1.06||$\checkmark$|
|Cos       |  0.001805 %|      0.122642 %| 8.80 vs  9.70  (ms)|0.91|$\checkmark$||
|Tan       |  0.001776 %|      4.562861 %| 8.63 vs 18.82  (ms)|0.46|$\checkmark$||
|ASin      |  0.031373 %|    100.000000 %| 7.65 vs 18.91  (ms)|0.40|$\checkmark$||
|ACos      |  0.117627 %|     98.413861 %| 7.25 vs 24.15  (ms)|0.30|$\checkmark$||
|ATan      |  0.003567 %|      0.036536 %| 8.63 vs 24.70  (ms)|0.35|$\checkmark$||
|ATan(10,x)|  0.006190 %|      0.021383 %|10.95 vs 32.07  (ms)|0.34|$\checkmark$||
|ATan(x,10)|  0.007318 %|      0.230349 %|13.34 vs 28.90  (ms)|0.46|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000084 %| 1.14 vs  9.62  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.92 vs  8.13  (ms)|0.24|$\checkmark$||
|Exp       |  0.001698 %|      0.050661 %| 2.10 vs  9.08  (ms)|0.23|$\checkmark$||
|Pow2      |  0.001820 %|      0.050354 %| 6.18 vs  7.67  (ms)|0.80|$\checkmark$||
|Log_e     |  0.001206 %|     86.225453 %| 3.00 vs  5.32  (ms)|0.56|$\checkmark$||
|Log_2     |  0.001206 %|     86.225884 %|23.01 vs  5.09  (ms)|4.52||$\checkmark$|
|Log_10    |  0.001206 %|     86.224927 %| 3.02 vs  6.35  (ms)|0.47|$\checkmark$||
|Pow(1.7,x)|  0.003043 %|      0.049457 %| 6.16 vs 29.43  (ms)|0.21|$\checkmark$||
|Pow(x,1.7)|  0.006763 %|      0.055199 %| 6.53 vs 28.05  (ms)|0.23|$\checkmark$||
