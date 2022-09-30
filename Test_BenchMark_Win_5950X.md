# GFloat Test And BenchMark
 * Test time : Fri Sep 30 11:49:50 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.57 vs  6.29  (ms)|0.09|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.49 vs  6.56  (ms)|0.07|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.68 vs  1.42  (ms)|0.48|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.79 vs  3.11  (ms)|0.25|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.71 vs  2.75  (ms)|2.07||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.70 vs  1.05  (ms)|5.41||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.50 vs  4.93  (ms)|0.10|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.39 vs  8.62  (ms)|0.04|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.33 vs  0.68  (ms)|0.49|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.52 vs  7.74  (ms)|0.07|$\checkmark$||
|<=()      |  0.000000 %|      0.000000 %| 0.47 vs  4.42  (ms)|0.11|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.35 vs  3.70  (ms)|0.09|$\checkmark$||
|Normalize32|  0.000000 %|      0.000000 %| 0.39 vs  1.79  (ms)|0.22|$\checkmark$||
|Normalize64|  0.000000 %|      0.000000 %| 0.44 vs  1.88  (ms)|0.23|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.55 vs  1.84  (ms)|0.30|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.37 vs  0.62  (ms)|0.59|$\checkmark$||
|Sin       |  0.000099 %|      4.559921 %| 8.97 vs  8.52  (ms)|1.05||$\checkmark$|
|Cos       |  0.001805 %|      0.122642 %| 8.87 vs 10.24  (ms)|0.87|$\checkmark$||
|Tan       |  0.001776 %|      4.562861 %| 8.70 vs 19.02  (ms)|0.46|$\checkmark$||
|ASin      |  0.031373 %|    100.000000 %| 7.64 vs 12.95  (ms)|0.59|$\checkmark$||
|ACos      |  0.117627 %|     98.413861 %| 7.48 vs 17.42  (ms)|0.43|$\checkmark$||
|ATan      |  0.003567 %|      0.036536 %| 8.52 vs 17.30  (ms)|0.49|$\checkmark$||
|ATan(10,x)|  0.006190 %|      0.021383 %|10.96 vs 22.61  (ms)|0.48|$\checkmark$||
|ATan(x,10)|  0.007318 %|      0.230349 %|11.11 vs 21.62  (ms)|0.51|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000084 %| 1.14 vs  9.63  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.90 vs  7.94  (ms)|0.24|$\checkmark$||
|Exp       |  0.001698 %|      0.050661 %| 2.11 vs  9.74  (ms)|0.22|$\checkmark$||
|Pow2      |  0.001820 %|      0.050354 %| 6.17 vs  8.22  (ms)|0.75|$\checkmark$||
|Log_e     |  0.001206 %|     86.225453 %| 2.92 vs  5.51  (ms)|0.53|$\checkmark$||
|Log_2     |  0.001206 %|     86.225884 %|23.07 vs  5.13  (ms)|4.50||$\checkmark$|
|Log_10    |  0.001206 %|     86.224927 %| 3.06 vs  5.67  (ms)|0.54|$\checkmark$||
|Pow(1.7,x)|  0.003043 %|      0.049457 %| 6.16 vs 28.84  (ms)|0.21|$\checkmark$||
|Pow(x,1.7)|  0.006763 %|      0.055199 %| 6.56 vs 27.83  (ms)|0.24|$\checkmark$||
