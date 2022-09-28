# GFloat Test And BenchMark
 * Test time : Wed Sep 28 14:16:55 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.54 vs  2.51  (ms)|0.21|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.58 vs  3.50  (ms)|0.17|$\checkmark$||
|Mul       |  0.000013 %|      0.000048 %| 0.48 vs  1.16  (ms)|0.42|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.79 vs  2.82  (ms)|0.28|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.72 vs  4.25  (ms)|1.35||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.56 vs  1.06  (ms)|5.23||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.52 vs  6.31  (ms)|0.08|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.37 vs  8.49  (ms)|0.04|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.36 vs  0.78  (ms)|0.46|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.53 vs  8.79  (ms)|0.06|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.35 vs  3.93  (ms)|0.09|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.38 vs  1.72  (ms)|0.22|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.50 vs  1.91  (ms)|0.26|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.39 vs  0.64  (ms)|0.61|$\checkmark$||
|Sin       |  0.000118 %|      4.559921 %|10.09 vs  8.35  (ms)|1.21||$\checkmark$|
|Cos       |  0.001786 %|      0.706807 %| 9.81 vs  9.88  (ms)|0.99|$\checkmark$||
|Tan       |  0.001764 %|      4.562861 %| 9.63 vs 18.80  (ms)|0.51|$\checkmark$||
|ASin      |  0.150651 %|      3.400623 %|11.02 vs 17.86  (ms)|0.62|$\checkmark$||
|ACos      |  0.589827 %|     98.451887 %|10.16 vs 22.48  (ms)|0.45|$\checkmark$||
|ATan      |  0.000038 %|      0.021293 %| 7.52 vs 28.86  (ms)|0.26|$\checkmark$||
|ATan(10,x)|  0.010567 %|      0.021383 %| 9.17 vs 33.58  (ms)|0.27|$\checkmark$||
|ATan(x,10)|  0.000121 %|      0.021303 %| 9.42 vs 39.99  (ms)|0.24|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000087 %| 1.12 vs  9.92  (ms)|0.11|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.90 vs  8.89  (ms)|0.21|$\checkmark$||
|Exp       |  0.004577 %|      0.050696 %| 2.10 vs 10.79  (ms)|0.19|$\checkmark$||
|Pow2      |  0.004529 %|      0.050354 %| 5.85 vs  9.14  (ms)|0.64|$\checkmark$||
|Log_e     |  0.000127 %|      0.154713 %| 2.74 vs  5.45  (ms)|0.50|$\checkmark$||
|Log_2     |  0.000126 %|      0.154716 %|23.23 vs  5.00  (ms)|4.65||$\checkmark$|
|Log_10    |  0.000125 %|      0.154691 %| 2.93 vs  5.74  (ms)|0.51|$\checkmark$||
|Pow(1.7,x)|  0.010808 %|      0.049472 %| 5.85 vs 32.84  (ms)|0.18|$\checkmark$||
|Pow(x,1.7)|  0.002379 %|      0.047431 %| 5.89 vs 27.81  (ms)|0.21|$\checkmark$||
