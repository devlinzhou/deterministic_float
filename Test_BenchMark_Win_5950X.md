# GFloat Test And BenchMark
 * Test time : Wed Sep 28 11:24:20 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.58 vs  2.53  (ms)|0.23|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.70 vs  4.14  (ms)|0.17|$\checkmark$||
|Mul       |  0.000013 %|      0.000048 %| 0.53 vs  1.15  (ms)|0.46|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.81 vs  2.64  (ms)|0.31|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.85 vs  4.59  (ms)|1.27||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.85 vs  1.10  (ms)|5.30||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.54 vs  6.21  (ms)|0.09|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.47 vs  8.50  (ms)|0.06|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.35 vs  0.79  (ms)|0.45|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.57 vs  9.41  (ms)|0.06|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.37 vs  3.76  (ms)|0.10|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.42 vs  1.77  (ms)|0.24|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.49 vs  1.94  (ms)|0.25|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.39 vs  0.62  (ms)|0.63|$\checkmark$||
|Sin       |  0.000118 %|      4.559921 %|10.11 vs  8.35  (ms)|1.21||$\checkmark$|
|Cos       |  0.001786 %|      0.706807 %| 9.79 vs  9.92  (ms)|0.99|$\checkmark$||
|Tan       |  0.001764 %|      4.562861 %| 9.61 vs 18.77  (ms)|0.51|$\checkmark$||
|ASin      |  0.150651 %|      3.400623 %|10.99 vs 17.88  (ms)|0.61|$\checkmark$||
|ACos      |  0.589827 %|     98.451887 %|10.16 vs 22.51  (ms)|0.45|$\checkmark$||
|ATan      |  0.000038 %|      0.021293 %| 7.58 vs 27.52  (ms)|0.28|$\checkmark$||
|ATan(10,x)|  0.010567 %|      0.021383 %| 9.17 vs 33.16  (ms)|0.28|$\checkmark$||
|ATan(x,10)|  0.000121 %|      0.021303 %| 9.46 vs 39.73  (ms)|0.24|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000087 %| 1.14 vs  9.75  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.92 vs  8.25  (ms)|0.23|$\checkmark$||
|Exp       |  0.004577 %|      0.050696 %| 2.10 vs 10.98  (ms)|0.19|$\checkmark$||
|Pow2      |  0.004529 %|      0.050354 %| 5.85 vs  9.78  (ms)|0.60|$\checkmark$||
|Log_e     |  0.000127 %|      0.154713 %| 2.91 vs  5.52  (ms)|0.53|$\checkmark$||
|Log_2     |  0.000126 %|      0.154716 %|23.23 vs  4.93  (ms)|4.71||$\checkmark$|
|Log_10    |  0.000125 %|      0.154691 %| 2.93 vs  5.56  (ms)|0.53|$\checkmark$||
|Pow(1.7,x)|  0.010808 %|      0.049472 %| 5.86 vs 24.16  (ms)|0.24|$\checkmark$||
|Pow(x,1.7)|  0.002379 %|      0.047431 %| 6.02 vs 19.61  (ms)|0.31|$\checkmark$||
