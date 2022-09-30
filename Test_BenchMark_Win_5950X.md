# GFloat Test And BenchMark
 * Test time : Fri Sep 30 11:55:07 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add         |  0.000004 %|      0.000024 %| 0.53 vs  5.67  (ms)|0.09|$\checkmark$||
|Sub         |  0.000004 %|      0.000024 %| 0.65 vs  6.06  (ms)|0.11|$\checkmark$||
|Mul         |  0.000012 %|      0.000048 %| 0.54 vs  1.16  (ms)|0.46|$\checkmark$||
|Div         |  0.000009 %|      0.000024 %| 0.79 vs  2.77  (ms)|0.28|$\checkmark$||
|Ceil        |  0.000000 %|      0.000000 %| 5.85 vs  2.79  (ms)|2.09||$\checkmark$|
|Floor       |  0.000000 %|      0.000000 %| 5.76 vs  1.07  (ms)|5.38||$\checkmark$|
|Whole       |  0.000000 %|      0.000000 %| 0.50 vs  4.95  (ms)|0.10|$\checkmark$||
|WholeFrac   |  0.000000 %|      0.000000 %| 0.41 vs  8.62  (ms)|0.05|$\checkmark$||
|-()         |  0.000000 %|      0.000000 %| 0.36 vs  0.69  (ms)|0.52|$\checkmark$||
|<()         |  0.000000 %|      0.000000 %| 0.58 vs  7.13  (ms)|0.08|$\checkmark$||
|<=()        |  0.000000 %|      0.000000 %| 0.56 vs  3.83  (ms)|0.15|$\checkmark$||
|Abs         |  0.000000 %|      0.000000 %| 0.38 vs  3.71  (ms)|0.10|$\checkmark$||
|Normalize32 |  0.000000 %|      0.000000 %| 0.46 vs  1.95  (ms)|0.23|$\checkmark$||
|Normalize64 |  0.000000 %|      0.000000 %| 0.42 vs  2.98  (ms)|0.14|$\checkmark$||
|FromInt     |  0.000000 %|      0.000000 %| 0.49 vs  1.80  (ms)|0.27|$\checkmark$||
|Fromfloat   |  0.000000 %|      0.000000 %| 0.40 vs  0.64  (ms)|0.62|$\checkmark$||
|Sin         |  0.000099 %|      4.559921 %| 8.91 vs  8.66  (ms)|1.03||$\checkmark$|
|Cos         |  0.001805 %|      0.122642 %| 8.63 vs  9.64  (ms)|0.90|$\checkmark$||
|Tan         |  0.001776 %|      4.562861 %| 8.52 vs 19.07  (ms)|0.45|$\checkmark$||
|ASin        |  0.031373 %|    100.000000 %| 7.69 vs 11.67  (ms)|0.66|$\checkmark$||
|ACos        |  0.117627 %|     98.413861 %| 7.44 vs 16.95  (ms)|0.44|$\checkmark$||
|ATan        |  0.003567 %|      0.036536 %| 9.22 vs 17.32  (ms)|0.53|$\checkmark$||
|ATan(10,x)  |  0.006190 %|      0.021383 %|10.96 vs 22.48  (ms)|0.49|$\checkmark$||
|ATan(x,10)  |  0.007318 %|      0.230349 %|11.12 vs 21.84  (ms)|0.51|$\checkmark$||
|Sqrt        |  0.000038 %|      0.000084 %| 1.14 vs  9.59  (ms)|0.12|$\checkmark$||
|InvSqrt     |  0.000026 %|      0.000062 %| 1.90 vs  7.96  (ms)|0.24|$\checkmark$||
|Exp         |  0.001698 %|      0.050661 %| 2.10 vs  9.66  (ms)|0.22|$\checkmark$||
|Pow2        |  0.001820 %|      0.050354 %| 6.16 vs  8.22  (ms)|0.75|$\checkmark$||
|Log_e       |  0.001206 %|     86.225453 %| 2.93 vs  5.43  (ms)|0.54|$\checkmark$||
|Log_2       |  0.001206 %|     86.225884 %|23.05 vs  5.06  (ms)|4.55||$\checkmark$|
|Log_10      |  0.001206 %|     86.224927 %| 3.03 vs  5.55  (ms)|0.55|$\checkmark$||
|Pow(1.7,x)  |  0.003043 %|      0.049457 %| 6.19 vs 28.97  (ms)|0.21|$\checkmark$||
|Pow(x,1.7)  |  0.006763 %|      0.055199 %| 6.57 vs 29.11  (ms)|0.23|$\checkmark$||
