# GFloat Test And BenchMark
 * Test time : Wed Sep 28 12:00:43 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Mac OSX|Apple LLVM 13.1.6 (clang-1316.0.21.2.5)|Apple Arm CPU|0.024 GHz or  0.024 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.42 vs  2.63  (ms)|0.16|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.31 vs  2.59  (ms)|0.12|$\checkmark$||
|Mul       |  0.000013 %|      0.000048 %| 0.28 vs  0.81  (ms)|0.35|$\checkmark$||
|Div       |  0.000009 %|      0.000024 %| 0.33 vs  1.89  (ms)|0.18|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 0.19 vs  2.00  (ms)|0.09|$\checkmark$||
|Floor     |  0.000000 %|      0.000000 %| 0.18 vs  0.75  (ms)|0.24|$\checkmark$||
|Whole     |  0.000000 %|      0.000000 %| 0.19 vs  1.65  (ms)|0.12|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.18 vs  6.78  (ms)|0.03|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.19 vs  0.56  (ms)|0.34|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.36 vs  2.73  (ms)|0.13|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.18 vs  0.56  (ms)|0.32|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.19 vs  1.30  (ms)|0.15|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.19 vs  1.14  (ms)|0.17|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.21 vs  0.17  (ms)|1.20||$\checkmark$|
|Sin       |  0.000117 %|      4.559921 %| 2.32 vs  5.28  (ms)|0.44|$\checkmark$||
|Cos       |  0.001787 %|      0.706807 %| 2.36 vs  5.79  (ms)|0.41|$\checkmark$||
|Tan       |  0.001764 %|      4.562861 %| 8.80 vs 14.83  (ms)|0.59|$\checkmark$||
|ASin      |  0.150651 %|      3.400623 %| 6.11 vs  8.49  (ms)|0.72|$\checkmark$||
|ACos      |  0.589827 %|     98.451887 %| 7.69 vs 13.17  (ms)|0.58|$\checkmark$||
|ATan      |  0.000038 %|      0.021293 %| 2.35 vs 18.50  (ms)|0.13|$\checkmark$||
|ATan(10,x)|  0.010567 %|      0.021383 %| 5.79 vs 20.34  (ms)|0.28|$\checkmark$||
|ATan(x,10)|  0.000121 %|      0.021303 %| 6.05 vs 32.84  (ms)|0.18|$\checkmark$||
|Sqrt      |  0.000038 %|      0.000087 %| 0.67 vs  6.04  (ms)|0.11|$\checkmark$||
|InvSqrt   |  0.000026 %|      0.000062 %| 1.05 vs  4.97  (ms)|0.21|$\checkmark$||
|Exp       |  0.004577 %|      0.050696 %| 5.57 vs  6.52  (ms)|0.85|$\checkmark$||
|Pow2      |  0.004529 %|      0.050354 %| 2.00 vs  5.94  (ms)|0.34|$\checkmark$||
|Log_e     |  0.000127 %|      0.154713 %| 2.04 vs  3.63  (ms)|0.56|$\checkmark$||
|Log_2     |  0.000126 %|      0.154716 %| 1.97 vs  3.52  (ms)|0.56|$\checkmark$||
|Log_10    |  0.000125 %|      0.154691 %| 1.97 vs  3.63  (ms)|0.54|$\checkmark$||
|Pow(1.7,x)|  0.010808 %|      0.049472 %| 4.39 vs 14.05  (ms)|0.31|$\checkmark$||
|Pow(x,1.7)|  0.002379 %|      0.047431 %| 4.52 vs 14.36  (ms)|0.31|$\checkmark$||
