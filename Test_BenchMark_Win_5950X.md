# GFloat Test And BenchMark
 * Test time : Wed Sep 28 15:07:18 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000052 %|      1.265823 %| 0.60 vs  2.65  (ms)|0.23|$\checkmark$||
|Sub       |  0.000043 %|     11.111111 %| 0.53 vs  3.54  (ms)|0.15|$\checkmark$||
|Mul       |  0.000014 %|      0.000071 %| 0.60 vs  1.16  (ms)|0.52|$\checkmark$||
|Div       |  0.000011 %|      0.000048 %| 0.81 vs  2.66  (ms)|0.31|$\checkmark$||
|Ceil      |  0.000006 %|      1.449275 %| 5.93 vs  3.99  (ms)|1.49||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.72 vs  1.15  (ms)|4.96||$\checkmark$|
|Whole     |  0.000004 %|      1.449275 %| 0.52 vs  5.43  (ms)|0.10|$\checkmark$||
|WholeFrac |  0.000004 %|      0.000012 %| 0.41 vs  7.78  (ms)|0.05|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.37 vs  0.79  (ms)|0.47|$\checkmark$||
|<()       |  0.000004 %|      0.000012 %| 0.67 vs  8.81  (ms)|0.08|$\checkmark$||
|Abs       |  0.000004 %|      0.000012 %| 0.39 vs  3.83  (ms)|0.10|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.47 vs  1.74  (ms)|0.27|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.59 vs  2.16  (ms)|0.27|$\checkmark$||
|Fromfloat |  0.000004 %|      0.000012 %| 0.53 vs  0.64  (ms)|0.83|$\checkmark$||
|Sin       |  0.045941 %|   7286.175695 %| 9.04 vs  8.55  (ms)|1.06||$\checkmark$|
|Cos       |  0.038330 %|   4111.911957 %| 8.84 vs  9.78  (ms)|0.90|$\checkmark$||
|Tan       |  0.086157 %|   7286.384159 %| 8.76 vs 19.17  (ms)|0.46|$\checkmark$||
|ASin      |  0.031377 %|    100.000000 %| 7.65 vs 19.03  (ms)|0.40|$\checkmark$||
|ACos      |  0.117628 %|     98.413861 %| 7.32 vs 24.88  (ms)|0.29|$\checkmark$||
|ATan      |  0.003567 %|      0.036536 %| 8.39 vs 25.56  (ms)|0.33|$\checkmark$||
|ATan(10,x)|  0.006189 %|      0.021383 %|11.37 vs 33.57  (ms)|0.34|$\checkmark$||
|ATan(x,10)|  0.007318 %|      0.230349 %|11.14 vs 30.35  (ms)|0.37|$\checkmark$||
|Sqrt      |  0.000040 %|      0.000090 %| 1.17 vs  9.54  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000024 %|      0.000062 %| 1.91 vs  8.16  (ms)|0.23|$\checkmark$||
|Exp       |  0.001707 %|      0.050851 %| 2.16 vs  9.17  (ms)|0.24|$\checkmark$||
|Pow2      |  0.001830 %|      0.050472 %| 7.27 vs  7.75  (ms)|0.94|$\checkmark$||
|Log_e     |  0.001211 %|     85.576593 %| 2.92 vs  5.39  (ms)|0.54|$\checkmark$||
|Log_2     |  0.001211 %|     85.577033 %|23.11 vs  5.15  (ms)|4.49||$\checkmark$|
|Log_10    |  0.001211 %|     85.576081 %| 3.08 vs  5.57  (ms)|0.55|$\checkmark$||
|Pow(1.7,x)|  0.003045 %|      0.049469 %| 6.17 vs 29.48  (ms)|0.21|$\checkmark$||
|Pow(x,1.7)|  0.006767 %|      0.055211 %| 6.54 vs 28.04  (ms)|0.23|$\checkmark$||
