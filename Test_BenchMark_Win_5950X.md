# GFloat Test And BenchMark
 * Test time : Thu Sep 29 11:25:05 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.59 vs  3.90  (ms)|0.15|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.58 vs  3.36  (ms)|0.17|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.56 vs  1.16  (ms)|0.49|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.86 vs  2.63  (ms)|0.33|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.76 vs  4.02  (ms)|1.43||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.72 vs  1.17  (ms)|4.91||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.60 vs  5.47  (ms)|0.11|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.40 vs  7.65  (ms)|0.05|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.33 vs  0.69  (ms)|0.47|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.53 vs  8.96  (ms)|0.06|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.38 vs  3.75  (ms)|0.10|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.37 vs  1.73  (ms)|0.21|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.55 vs  1.96  (ms)|0.28|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.39 vs  0.68  (ms)|0.58|$\checkmark$||
|Sin       |  0.000099 %|      4.559921 %| 8.94 vs  8.70  (ms)|1.03||$\checkmark$|
|Cos       |  0.001805 %|      0.122642 %| 8.62 vs  9.84  (ms)|0.88|$\checkmark$||
|Tan       |  0.001776 %|      4.562861 %| 8.54 vs 18.75  (ms)|0.46|$\checkmark$||
|ASin      |  0.031373 %|    100.000000 %| 7.65 vs 18.90  (ms)|0.40|$\checkmark$||
|ACos      |  0.117627 %|     98.413861 %| 7.23 vs 23.80  (ms)|0.30|$\checkmark$||
|ATan      |  0.003567 %|      0.036536 %| 9.45 vs 24.98  (ms)|0.38|$\checkmark$||
|ATan(10,x)|  0.006190 %|      0.021383 %|10.98 vs 31.94  (ms)|0.34|$\checkmark$||
|ATan(x,10)|  0.007318 %|      0.230349 %|11.12 vs 28.83  (ms)|0.39|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000084 %| 1.13 vs  9.52  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.91 vs  8.04  (ms)|0.24|$\checkmark$||
|Exp       |  0.001698 %|      0.050661 %| 2.10 vs  9.19  (ms)|0.23|$\checkmark$||
|Pow2      |  0.001820 %|      0.050354 %| 6.17 vs  7.79  (ms)|0.79|$\checkmark$||
|Log_e     |  0.001206 %|     86.225453 %| 2.90 vs  5.42  (ms)|0.54|$\checkmark$||
|Log_2     |  0.001206 %|     86.225884 %|23.06 vs  5.00  (ms)|4.61||$\checkmark$|
|Log_10    |  0.001206 %|     86.224927 %| 3.03 vs  5.79  (ms)|0.52|$\checkmark$||
|Pow(1.7,x)|  0.003043 %|      0.049457 %| 6.14 vs 28.92  (ms)|0.21|$\checkmark$||
|Pow(x,1.7)|  0.006763 %|      0.055199 %| 6.54 vs 28.51  (ms)|0.23|$\checkmark$||
