# GFloat Test And BenchMark
 * Test time : Thu Sep 29 16:39:25 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.55 vs  2.55  (ms)|0.22|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.53 vs  3.35  (ms)|0.16|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.54 vs  1.16  (ms)|0.46|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.84 vs  2.78  (ms)|0.30|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.71 vs  4.04  (ms)|1.42||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.74 vs  1.10  (ms)|5.23||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.50 vs  5.46  (ms)|0.09|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.40 vs  9.70  (ms)|0.04|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.47 vs  0.75  (ms)|0.63|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.55 vs  8.61  (ms)|0.06|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.38 vs  3.92  (ms)|0.10|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.46 vs  1.83  (ms)|0.25|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.49 vs  1.96  (ms)|0.25|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.41 vs  0.70  (ms)|0.59|$\checkmark$||
|Sin       |  0.000099 %|      4.559921 %| 8.91 vs  8.52  (ms)|1.05||$\checkmark$|
|Cos       |  0.001805 %|      0.122642 %| 8.78 vs 10.38  (ms)|0.85|$\checkmark$||
|Tan       |  0.001776 %|      4.562861 %| 8.61 vs 19.25  (ms)|0.45|$\checkmark$||
|ASin      |  0.031373 %|    100.000000 %| 7.66 vs 18.94  (ms)|0.40|$\checkmark$||
|ACos      |  0.117627 %|     98.413861 %| 7.28 vs 23.97  (ms)|0.30|$\checkmark$||
|ATan      |  0.003567 %|      0.036536 %| 8.34 vs 24.88  (ms)|0.34|$\checkmark$||
|ATan(10,x)|  0.006190 %|      0.021383 %|10.99 vs 31.81  (ms)|0.35|$\checkmark$||
|ATan(x,10)|  0.007318 %|      0.230349 %|11.16 vs 28.56  (ms)|0.39|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000084 %| 1.12 vs  9.65  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.90 vs  8.10  (ms)|0.23|$\checkmark$||
|Exp       |  0.001698 %|      0.050661 %| 2.15 vs 10.14  (ms)|0.21|$\checkmark$||
|Pow2      |  0.001820 %|      0.050354 %| 6.18 vs  8.49  (ms)|0.73|$\checkmark$||
|Log_e     |  0.001206 %|     86.225453 %| 2.88 vs  5.38  (ms)|0.54|$\checkmark$||
|Log_2     |  0.001206 %|     86.225884 %|23.06 vs  4.99  (ms)|4.62||$\checkmark$|
|Log_10    |  0.001206 %|     86.224927 %| 3.01 vs  5.34  (ms)|0.56|$\checkmark$||
|Pow(1.7,x)|  0.003043 %|      0.049457 %| 6.16 vs 30.04  (ms)|0.21|$\checkmark$||
|Pow(x,1.7)|  0.006763 %|      0.055199 %| 6.55 vs 27.59  (ms)|0.24|$\checkmark$||
