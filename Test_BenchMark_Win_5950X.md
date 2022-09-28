# GFloat Test And BenchMark
 * Test time : Wed Sep 28 12:04:34 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.50 vs  2.78  (ms)|0.18|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.50 vs  3.54  (ms)|0.14|$\checkmark$||
|Mul       |  0.000013 %|      0.000048 %| 0.52 vs  1.18  (ms)|0.44|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.80 vs  2.65  (ms)|0.30|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.79 vs  4.27  (ms)|1.36||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.71 vs  1.03  (ms)|5.57||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.50 vs  6.20  (ms)|0.08|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.38 vs  8.49  (ms)|0.04|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.34 vs  0.78  (ms)|0.44|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.51 vs  8.77  (ms)|0.06|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.37 vs  4.41  (ms)|0.08|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.55 vs  1.73  (ms)|0.32|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.51 vs  1.93  (ms)|0.26|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.51 vs  0.75  (ms)|0.68|$\checkmark$||
|Sin       |  0.000118 %|      4.559921 %|10.18 vs  8.39  (ms)|1.21||$\checkmark$|
|Cos       |  0.001786 %|      0.706807 %|10.12 vs  9.96  (ms)|1.02||$\checkmark$|
|Tan       |  0.001764 %|      4.562861 %| 9.84 vs 18.93  (ms)|0.52|$\checkmark$||
|ASin      |  0.150651 %|      3.400623 %|11.14 vs 17.44  (ms)|0.64|$\checkmark$||
|ACos      |  0.589827 %|     98.451887 %|10.37 vs 22.43  (ms)|0.46|$\checkmark$||
|ATan      |  0.000038 %|      0.021293 %| 7.60 vs 27.39  (ms)|0.28|$\checkmark$||
|ATan(10,x)|  0.010567 %|      0.021383 %| 9.27 vs 32.92  (ms)|0.28|$\checkmark$||
|ATan(x,10)|  0.000121 %|      0.021303 %| 9.52 vs 39.26  (ms)|0.24|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000087 %| 1.12 vs 10.32  (ms)|0.11|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.90 vs  8.46  (ms)|0.22|$\checkmark$||
|Exp       |  0.004577 %|      0.050696 %| 2.16 vs 10.83  (ms)|0.20|$\checkmark$||
|Pow2      |  0.004529 %|      0.050354 %| 5.93 vs  9.21  (ms)|0.64|$\checkmark$||
|Log_e     |  0.000127 %|      0.154713 %| 2.83 vs  5.30  (ms)|0.53|$\checkmark$||
|Log_2     |  0.000126 %|      0.154716 %|23.56 vs  5.01  (ms)|4.70||$\checkmark$|
|Log_10    |  0.000125 %|      0.154691 %| 3.08 vs  5.44  (ms)|0.57|$\checkmark$||
|Pow(1.7,x)|  0.010808 %|      0.049472 %| 5.95 vs 30.55  (ms)|0.19|$\checkmark$||
|Pow(x,1.7)|  0.002379 %|      0.047431 %| 6.10 vs 27.26  (ms)|0.22|$\checkmark$||
