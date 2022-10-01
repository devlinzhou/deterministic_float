# GFloat Test And BenchMark
 * Test time : Sat Oct  1 11:02:31 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add         |  0.000004 %|      0.000024 %| 0.50 vs  5.38  (ms)|0.09|$\checkmark$||
|Sub         |  0.000004 %|      0.000024 %| 0.46 vs  5.12  (ms)|0.09|$\checkmark$||
|Mul         |  0.000012 %|      0.000048 %| 0.49 vs  0.74  (ms)|0.66|$\checkmark$||
|Div         |  0.000009 %|      0.000024 %| 0.67 vs  2.13  (ms)|0.31|$\checkmark$||
|Ceil        |  0.000000 %|      0.000000 %| 6.20 vs  2.18  (ms)|2.84||$\checkmark$|
|Floor       |  0.000000 %|      0.000000 %| 5.64 vs  0.99  (ms)|5.72||$\checkmark$|
|Whole       |  0.000000 %|      0.000000 %| 0.45 vs  4.28  (ms)|0.11|$\checkmark$||
|WholeFrac   |  0.000000 %|      0.000000 %| 0.37 vs  6.84  (ms)|0.05|$\checkmark$||
|-()         |  0.000000 %|      0.000000 %| 0.36 vs  0.52  (ms)|0.69|$\checkmark$||
|<()         |  0.000000 %|      0.000000 %| 0.46 vs  7.17  (ms)|0.06|$\checkmark$||
|<=()        |  0.000000 %|      0.000000 %| 0.43 vs  4.01  (ms)|0.11|$\checkmark$||
|Abs         |  0.000000 %|      0.000000 %| 0.36 vs  4.23  (ms)|0.09|$\checkmark$||
|Normalize32 |  0.000000 %|      0.000000 %| 0.34 vs  1.39  (ms)|0.25|$\checkmark$||
|Normalize64 |  0.000000 %|      0.000000 %| 0.43 vs  1.16  (ms)|0.37|$\checkmark$||
|FromInt     |  0.000000 %|      0.000000 %| 0.53 vs  1.81  (ms)|0.29|$\checkmark$||
|Fromfloat   |  0.000000 %|      0.000000 %| 0.36 vs  0.43  (ms)|0.84|$\checkmark$||
|Sin         |  0.000099 %|      4.559921 %| 7.44 vs  6.67  (ms)|1.12||$\checkmark$|
|Cos         |  0.001805 %|      0.122642 %| 7.46 vs  9.00  (ms)|0.83|$\checkmark$||
|Tan         |  0.001776 %|      4.562861 %| 7.88 vs 14.52  (ms)|0.54|$\checkmark$||
|ASin        |  0.031373 %|    100.000000 %| 7.36 vs  9.67  (ms)|0.76|$\checkmark$||
|ACos        |  0.117627 %|     98.413861 %| 7.79 vs 13.37  (ms)|0.58|$\checkmark$||
|ATan        |  0.003567 %|      0.036536 %| 9.56 vs 16.40  (ms)|0.58|$\checkmark$||
|ATan(10,x)  |  0.006190 %|      0.021383 %|10.93 vs 17.70  (ms)|0.62|$\checkmark$||
|ATan(x,10)  |  0.007318 %|      0.230349 %|12.62 vs 18.83  (ms)|0.67|$\checkmark$||
|Sqrt        |  0.000038 %|      0.000084 %| 0.66 vs  6.74  (ms)|0.10|$\checkmark$||
|InvSqrt     |  0.000026 %|      0.000062 %| 1.26 vs  6.55  (ms)|0.19|$\checkmark$||
|Exp         |  0.001698 %|      0.050661 %| 3.56 vs  7.68  (ms)|0.46|$\checkmark$||
|Pow2        |  0.001820 %|      0.050354 %| 5.38 vs  7.06  (ms)|0.76|$\checkmark$||
|Log_e       |  0.001206 %|     86.225453 %| 2.81 vs  4.12  (ms)|0.68|$\checkmark$||
|Log_2       |  0.001206 %|     86.225884 %|19.99 vs  3.70  (ms)|5.40||$\checkmark$|
|Log_10      |  0.001206 %|     86.224927 %| 2.44 vs  3.83  (ms)|0.64|$\checkmark$||
|Pow(1.7,x)  |  0.003043 %|      0.049457 %| 5.12 vs 17.89  (ms)|0.29|$\checkmark$||
|Pow(x,1.7)  |  0.006763 %|      0.055199 %| 6.27 vs 18.77  (ms)|0.33|$\checkmark$||
|Fmod(x,1.7) |  0.230497 %|  99374.274554 %| 9.39 vs 11.70  (ms)|0.80|$\checkmark$||
|Fmod(1.7,x) |  0.000587 %|     46.261928 %| 3.71 vs  7.08  (ms)|0.52|$\checkmark$||
