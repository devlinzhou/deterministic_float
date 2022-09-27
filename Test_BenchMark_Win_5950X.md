# GFloat Test And BenchMark
 * Test time : Tue Sep 27 20:16:52 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000004 %|      0.000024 %| 0.52 vs  2.60  (ms)|0.20|$\checkmark$||
|Sub       |  0.000004 %|      0.000024 %| 0.51 vs  3.57  (ms)|0.14|$\checkmark$||
|Mul       |  0.000012 %|      0.000048 %| 0.66 vs  1.16  (ms)|0.57|$\checkmark$||
|Div       |  0.000008 %|      0.000024 %| 0.75 vs  2.77  (ms)|0.27|$\checkmark$||
|Ceil      |  0.000000 %|      0.000000 %| 5.50 vs  3.95  (ms)|1.39||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.59 vs  1.00  (ms)|5.57||$\checkmark$|
|Whole     |  0.000000 %|      0.000000 %| 0.48 vs  6.52  (ms)|0.07|$\checkmark$||
|WholeFrac |  0.000000 %|      0.000000 %| 0.41 vs 14.52  (ms)|0.03|$\checkmark$||
|-()       |  0.000000 %|      0.000000 %| 0.36 vs  0.76  (ms)|0.48|$\checkmark$||
|<()       |  0.000000 %|      0.000000 %| 0.51 vs  8.57  (ms)|0.06|$\checkmark$||
|Abs       |  0.000000 %|      0.000000 %| 0.50 vs  3.83  (ms)|0.13|$\checkmark$||
|Normalize |  0.000000 %|      0.000000 %| 0.40 vs  1.67  (ms)|0.24|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.46 vs  1.97  (ms)|0.24|$\checkmark$||
|Fromfloat |  0.000000 %|      0.000000 %| 0.38 vs  0.55  (ms)|0.68|$\checkmark$||
|Sin       |  0.000115 %|      4.559921 %|10.06 vs  8.69  (ms)|1.16||$\checkmark$|
|Cos       |  0.001734 %|      0.706807 %| 9.61 vs  9.44  (ms)|1.02||$\checkmark$|
|Tan       |  0.001712 %|      4.562861 %| 9.41 vs 18.85  (ms)|0.50|$\checkmark$||
|ASin      |  0.207207 %|     11.230696 %|11.23 vs 17.50  (ms)|0.64|$\checkmark$||
|ACos      |  1.108382 %|   5498.911422 %|10.13 vs 18.43  (ms)|0.55|$\checkmark$||
|ATan      |  0.000037 %|      0.021293 %| 7.25 vs 27.17  (ms)|0.27|$\checkmark$||
|ATan(10,x)|  0.010258 %|      0.021383 %| 9.03 vs 32.63  (ms)|0.28|$\checkmark$||
|ATan(x,10)|  0.000118 %|      0.021303 %| 9.23 vs 38.75  (ms)|0.24|$\checkmark$||
|Sqrt      |  0.000163 %|      0.001550 %| 1.08 vs  9.44  (ms)|0.11|$\checkmark$||
|InvSqrt   |  0.000152 %|      0.001526 %| 1.84 vs  8.16  (ms)|0.23|$\checkmark$||
|Exp       |  0.022711 %|      0.165045 %| 2.18 vs 30.80  (ms)|0.07|$\checkmark$||
|Log_e     |  0.000123 %|      0.154713 %| 2.73 vs  5.36  (ms)|0.51|$\checkmark$||
|Log_2     |  0.000122 %|      0.154716 %|22.57 vs  5.20  (ms)|4.34||$\checkmark$|
|Pow(2,x)  |  0.022471 %|      0.055202 %| 5.85 vs 39.66  (ms)|0.15|$\checkmark$||
|Pow(x,2)  |  0.011902 %|      0.064317 %| 5.79 vs 31.37  (ms)|0.18|$\checkmark$||
