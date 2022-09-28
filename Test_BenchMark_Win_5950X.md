# GFloat Test And BenchMark
 * Test time : Wed Sep 28 11:27:46 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.58 vs  3.03  (ms)|0.19|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.66 vs  3.89  (ms)|0.17|$\checkmark$||
|Mul       |  0.000013 %|      0.000048 %| 0.57 vs  1.34  (ms)|0.43|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.81 vs  3.00  (ms)|0.27|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.68 vs  4.34  (ms)|1.31||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.70 vs  1.09  (ms)|5.25||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.49 vs  6.26  (ms)|0.08|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.38 vs  8.69  (ms)|0.04|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.51 vs  1.13  (ms)|0.45|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.62 vs  9.52  (ms)|0.06|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.35 vs  4.08  (ms)|0.09|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.42 vs  1.75  (ms)|0.24|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.49 vs  1.95  (ms)|0.25|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.39 vs  0.70  (ms)|0.56|$\checkmark$||
|Sin       |  0.000118 %|      4.559921 %|10.14 vs  8.27  (ms)|1.23||$\checkmark$|
|Cos       |  0.001786 %|      0.706807 %| 9.95 vs  9.75  (ms)|1.02||$\checkmark$|
|Tan       |  0.001764 %|      4.562861 %| 9.68 vs 18.95  (ms)|0.51|$\checkmark$||
|ASin      |  0.150651 %|      3.400623 %|11.06 vs 17.69  (ms)|0.63|$\checkmark$||
|ACos      |  0.589827 %|     98.451887 %|10.32 vs 22.93  (ms)|0.45|$\checkmark$||
|ATan      |  0.000038 %|      0.021293 %| 7.31 vs 30.68  (ms)|0.24|$\checkmark$||
|ATan(10,x)|  0.010567 %|      0.021383 %| 9.19 vs 32.76  (ms)|0.28|$\checkmark$||
|ATan(x,10)|  0.000121 %|      0.021303 %| 9.45 vs 39.01  (ms)|0.24|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000087 %| 1.12 vs  9.80  (ms)|0.11|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.92 vs  8.37  (ms)|0.23|$\checkmark$||
|Exp       |  0.004577 %|      0.050696 %| 2.09 vs 10.99  (ms)|0.19|$\checkmark$||
|Pow2      |  0.004529 %|      0.050354 %| 5.87 vs  9.22  (ms)|0.64|$\checkmark$||
|Log_e     |  0.000127 %|      0.154713 %| 2.77 vs  5.38  (ms)|0.52|$\checkmark$||
|Log_2     |  0.000126 %|      0.154716 %|23.27 vs  5.07  (ms)|4.59||$\checkmark$|
|Log_10    |  0.000125 %|      0.154691 %| 2.86 vs  5.46  (ms)|0.52|$\checkmark$||
|Pow(1.7,x)|  0.010808 %|      0.049472 %| 5.87 vs 24.18  (ms)|0.24|$\checkmark$||
|Pow(x,1.7)|  0.002379 %|      0.047431 %| 5.94 vs 19.71  (ms)|0.30|$\checkmark$||
