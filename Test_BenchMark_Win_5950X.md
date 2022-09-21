# GFloat Test And BenchMark
 * Test time : Wed Sep 21 12:17:46 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.56 vs 4.36  (ms) |0.36|$\checkmark$||
|Sub|0.000055 %|11.111111 %|1.56 vs 4.57  (ms) |0.34|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.57 vs 2.19  (ms) |0.72|$\checkmark$||
|Div|0.000011 %|0.000046 %|1.62 vs 4.11  (ms) |0.39|$\checkmark$||
|Ceil|nan %|0.116550 %|7.66 vs 6.54  (ms) |1.17||$\checkmark$|
|Floor|nan %|0.000000 %|7.71 vs 1.94  (ms) |3.99||$\checkmark$|
|Whole|nan %|0.116550 %|1.36 vs 6.98  (ms) |0.20|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.32 vs 11.92  (ms) |0.11|$\checkmark$||
|FromInt|nan %|0.000000 %|1.36 vs 2.83  (ms) |0.48|$\checkmark$||
|<|0.000004 %|0.000012 %|6.31 vs 10.05  (ms) |0.63|$\checkmark$||
|-()|0.000004 %|0.000012 %|1.39 vs 1.51  (ms) |0.92|$\checkmark$||
|Normalize|0.000004 %|0.000012 %|1.33 vs 2.56  (ms) |0.52|$\checkmark$||
|**Sin**|0.000906 %|128.728364 %|12.40 vs 5.71  (ms) |2.17||$\checkmark$|
|Cos|0.000816 %|83.296263 %|11.90 vs 5.24  (ms) |2.27||$\checkmark$|
|SinCos|0.197822 %|9571.942496 %|15.15 vs 13.11  (ms) |1.16||$\checkmark$|
|Tan|0.001088 %|41.104408 %|9.17 vs 11.76  (ms) |0.78|$\checkmark$||
|ASin|0.474911 %|14.587558 %|13.16 vs 13.12  (ms) |1.00||$\checkmark$|
|ACos|2.121228 %|7499.911452 %|12.71 vs 13.93  (ms) |0.91|$\checkmark$||
|ATan|0.000448 %|10.312487 %|9.62 vs 35.54  (ms) |0.27|$\checkmark$||
|ATan(10,x)|0.002442 %|10.290108 %|10.93 vs 30.71  (ms) |0.36|$\checkmark$||
|ATan(x,10)|0.003470 %|10.345940 %|10.85 vs 46.25  (ms) |0.23|$\checkmark$||
|**Sqrt**|0.000170 %|0.001553 %|1.43 vs 11.01  (ms) |0.13|$\checkmark$||
|invSqrt|0.000154 %|0.001526 %|1.89 vs 9.32  (ms) |0.20|$\checkmark$||
|**Exp**|0.023400 %|0.165236 %|3.97 vs 36.86  (ms) |0.11|$\checkmark$||
|Log|0.082740 %|62.666664 %|4.60 vs 106.81  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.063863 %|0.135178 %|7.94 vs 65.18  (ms) |0.12|$\checkmark$||
|Pow(x,2)|1.649633 %|19.762378 %|7.04 vs 65.84  (ms) |0.11|$\checkmark$||
