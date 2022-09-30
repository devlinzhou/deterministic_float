# GFloat Test And BenchMark
 * Test time : Fri Sep 30 10:57:35 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.51 vs  2.67  (ms)|0.19|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.59 vs  2.92  (ms)|0.20|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.50 vs  1.16  (ms)|0.43|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.81 vs  2.87  (ms)|0.28|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.86 vs  2.68  (ms)|2.18||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.74 vs  0.99  (ms)|5.78||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.53 vs  5.20  (ms)|0.10|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.41 vs  8.71  (ms)|0.05|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.39 vs  0.94  (ms)|0.41|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.51 vs  7.12  (ms)|0.07|$\checkmark$||
|<=()      |  0.000000 %|      0.000000 %| 0.50 vs  3.79  (ms)|0.13|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.37 vs  3.82  (ms)|0.10|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.44 vs  1.80  (ms)|0.25|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.51 vs  2.07  (ms)|0.24|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.41 vs  0.63  (ms)|0.65|$\checkmark$||
|Sin       |  0.000099 %|      4.559921 %| 8.95 vs  8.75  (ms)|1.02||$\checkmark$|
|Cos       |  0.001805 %|      0.122642 %| 8.69 vs  9.71  (ms)|0.90|$\checkmark$||
|Tan       |  0.001776 %|      4.562861 %| 8.53 vs 19.69  (ms)|0.43|$\checkmark$||
|ASin      |  0.031373 %|    100.000000 %| 7.67 vs 12.12  (ms)|0.63|$\checkmark$||
|ACos      |  0.117627 %|     98.413861 %| 7.36 vs 18.06  (ms)|0.41|$\checkmark$||
|ATan      |  0.003567 %|      0.036536 %| 8.55 vs 18.46  (ms)|0.46|$\checkmark$||
|ATan(10,x)|  0.006190 %|      0.021383 %|10.90 vs 22.84  (ms)|0.48|$\checkmark$||
|ATan(x,10)|  0.007318 %|      0.230349 %|11.12 vs 22.77  (ms)|0.49|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000084 %| 1.12 vs  9.58  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.91 vs  8.02  (ms)|0.24|$\checkmark$||
|Exp       |  0.001698 %|      0.050661 %| 2.12 vs  9.83  (ms)|0.22|$\checkmark$||
|Pow2      |  0.001820 %|      0.050354 %| 6.15 vs  8.48  (ms)|0.73|$\checkmark$||
|Log_e     |  0.001206 %|     86.225453 %| 2.94 vs  5.51  (ms)|0.53|$\checkmark$||
|Log_2     |  0.001206 %|     86.225884 %|23.02 vs  5.09  (ms)|4.52||$\checkmark$|
|Log_10    |  0.001206 %|     86.224927 %| 3.13 vs  5.54  (ms)|0.57|$\checkmark$||
|Pow(1.7,x)|  0.003043 %|      0.049457 %| 6.15 vs 29.23  (ms)|0.21|$\checkmark$||
|Pow(x,1.7)|  0.006763 %|      0.055199 %| 6.52 vs 29.77  (ms)|0.22|$\checkmark$||
