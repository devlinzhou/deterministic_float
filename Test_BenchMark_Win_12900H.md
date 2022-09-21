# GFloat Test And BenchMark
 * Test time : Wed Sep 21 21:11:00 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.47 vs 2.82  (ms) |0.52|$\checkmark$||
|Sub|0.000055 %|11.111111 %|1.35 vs 2.89  (ms) |0.47|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.48 vs 1.39  (ms) |1.06||$\checkmark$|
|Div|0.000011 %|0.000046 %|1.17 vs 2.80  (ms) |0.42|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.88 vs 3.51  (ms) |2.24||$\checkmark$|
|Floor|0.000000 %|0.000000 %|8.96 vs 1.51  (ms) |5.94||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.41 vs 6.97  (ms) |0.20|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.31 vs 8.99  (ms) |0.15|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.21 vs 1.41  (ms) |0.85|$\checkmark$||
|<|0.000004 %|0.000012 %|6.74 vs 9.11  (ms) |0.74|$\checkmark$||
|-()|0.000004 %|0.000012 %|1.31 vs 1.08  (ms) |1.21||$\checkmark$|
|Normalize|0.000004 %|0.000012 %|1.23 vs 1.32  (ms) |0.93|$\checkmark$||
|**Sin**|0.000906 %|128.728364 %|11.66 vs 3.82  (ms) |3.05||$\checkmark$|
|Cos|0.000816 %|83.296263 %|12.30 vs 4.09  (ms) |3.01||$\checkmark$|
|SinCos|0.197822 %|9571.942496 %|16.00 vs 8.86  (ms) |1.81||$\checkmark$|
|Tan|0.001088 %|41.104408 %|10.07 vs 8.48  (ms) |1.19||$\checkmark$|
|ASin|0.474911 %|14.587558 %|12.06 vs 8.86  (ms) |1.36||$\checkmark$|
|ACos|2.121254 %|7499.923180 %|12.29 vs 12.31  (ms) |1.00|$\checkmark$||
|ATan|0.000448 %|10.312487 %|9.63 vs 25.73  (ms) |0.37|$\checkmark$||
|ATan(10,x)|0.002442 %|10.290108 %|11.03 vs 26.51  (ms) |0.42|$\checkmark$||
|ATan(x,10)|0.003470 %|10.345940 %|10.54 vs 36.07  (ms) |0.29|$\checkmark$||
|**Sqrt**|0.000170 %|0.001553 %|1.14 vs 7.55  (ms) |0.15|$\checkmark$||
|invSqrt|0.000154 %|0.001526 %|1.24 vs 6.12  (ms) |0.20|$\checkmark$||
|**Exp**|0.023400 %|0.165236 %|3.00 vs 26.09  (ms) |0.11|$\checkmark$||
|Log|0.082740 %|62.666664 %|3.37 vs 76.14  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.063863 %|0.135178 %|6.38 vs 47.75  (ms) |0.13|$\checkmark$||
|Pow(x,2)|1.649633 %|19.762378 %|6.47 vs 52.48  (ms) |0.12|$\checkmark$||
