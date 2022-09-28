# GFloat Test And BenchMark
 * Test time : Wed Sep 28 13:25:50 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.56 vs  2.50  (ms)|0.23|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.61 vs  3.51  (ms)|0.17|$\checkmark$||
|Mul       |  0.000013 %|      0.000048 %| 0.51 vs  1.12  (ms)|0.46|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.80 vs  2.62  (ms)|0.31|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.65 vs  4.53  (ms)|1.25||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.78 vs  1.09  (ms)|5.30||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.56 vs  6.18  (ms)|0.09|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.40 vs  8.65  (ms)|0.05|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.42 vs  0.78  (ms)|0.53|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.70 vs  8.72  (ms)|0.08|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.34 vs  3.78  (ms)|0.09|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.40 vs  1.73  (ms)|0.23|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.58 vs  1.92  (ms)|0.30|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.39 vs  0.62  (ms)|0.63|$\checkmark$||
|Sin       |  0.000118 %|      4.559921 %|10.08 vs  8.34  (ms)|1.21||$\checkmark$|
|Cos       |  0.001786 %|      0.706807 %| 9.78 vs  9.88  (ms)|0.99|$\checkmark$||
|Tan       |  0.001764 %|      4.562861 %| 9.61 vs 18.78  (ms)|0.51|$\checkmark$||
|ASin      |  0.150651 %|      3.400623 %|11.00 vs 17.88  (ms)|0.62|$\checkmark$||
|ACos      |  0.589827 %|     98.451887 %|10.13 vs 22.47  (ms)|0.45|$\checkmark$||
|ATan      |  0.000038 %|      0.021293 %| 7.52 vs 28.04  (ms)|0.27|$\checkmark$||
|ATan(10,x)|  0.010567 %|      0.021383 %| 9.18 vs 33.52  (ms)|0.27|$\checkmark$||
|ATan(x,10)|  0.000121 %|      0.021303 %| 9.49 vs 42.50  (ms)|0.22|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000087 %| 1.13 vs  9.92  (ms)|0.11|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.92 vs  8.91  (ms)|0.22|$\checkmark$||
|Exp       |  0.004577 %|      0.050696 %| 2.14 vs 10.81  (ms)|0.20|$\checkmark$||
|Pow2      |  0.004529 %|      0.050354 %| 5.86 vs  9.14  (ms)|0.64|$\checkmark$||
|Log_e     |  0.000127 %|      0.154713 %| 2.83 vs  5.39  (ms)|0.52|$\checkmark$||
|Log_2     |  0.000126 %|      0.154716 %|23.35 vs  5.01  (ms)|4.66||$\checkmark$|
|Log_10    |  0.000125 %|      0.154691 %| 2.92 vs  5.45  (ms)|0.54|$\checkmark$||
|Pow(1.7,x)|  0.010808 %|      0.049472 %| 5.86 vs 30.70  (ms)|0.19|$\checkmark$||
|Pow(x,1.7)|  0.002379 %|      0.047431 %| 5.89 vs 28.00  (ms)|0.21|$\checkmark$||
