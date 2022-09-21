# GFloat Test And BenchMark
 * Test time : Wed Sep 21 12:20:12 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.61 vs 5.85  (ms) |0.28|$\checkmark$||
|Sub|0.000055 %|11.111111 %|1.60 vs 4.59  (ms) |0.35|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.60 vs 2.19  (ms) |0.73|$\checkmark$||
|Div|0.000011 %|0.000046 %|1.60 vs 4.34  (ms) |0.37|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|8.32 vs 6.64  (ms) |1.25||$\checkmark$|
|Floor|0.000000 %|0.000000 %|8.16 vs 2.72  (ms) |3.00||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.97 vs 7.24  (ms) |0.27|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.42 vs 13.30  (ms) |0.11|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.55 vs 4.41  (ms) |0.35|$\checkmark$||
|<|0.000004 %|0.000012 %|6.57 vs 10.32  (ms) |0.64|$\checkmark$||
|-()|0.000004 %|0.000012 %|1.39 vs 1.56  (ms) |0.90|$\checkmark$||
|Normalize|0.000004 %|0.000012 %|1.38 vs 2.62  (ms) |0.53|$\checkmark$||
|**Sin**|0.000906 %|128.728364 %|13.12 vs 6.03  (ms) |2.18||$\checkmark$|
|Cos|0.000816 %|83.296263 %|12.30 vs 6.55  (ms) |1.88||$\checkmark$|
|SinCos|0.197822 %|9571.942496 %|16.34 vs 15.10  (ms) |1.08||$\checkmark$|
|Tan|0.001088 %|41.104408 %|10.13 vs 14.55  (ms) |0.70|$\checkmark$||
|ASin|0.474911 %|14.587558 %|13.50 vs 17.63  (ms) |0.77|$\checkmark$||
|ACos|2.121228 %|7499.911452 %|13.46 vs 15.04  (ms) |0.90|$\checkmark$||
|ATan|0.000448 %|10.312487 %|10.30 vs 35.34  (ms) |0.29|$\checkmark$||
|ATan(10,x)|0.002442 %|10.290108 %|10.72 vs 30.58  (ms) |0.35|$\checkmark$||
|ATan(x,10)|0.003470 %|10.345940 %|11.01 vs 45.69  (ms) |0.24|$\checkmark$||
|**Sqrt**|0.000170 %|0.001553 %|1.44 vs 11.61  (ms) |0.12|$\checkmark$||
|invSqrt|0.000154 %|0.001526 %|1.90 vs 9.54  (ms) |0.20|$\checkmark$||
|**Exp**|0.023400 %|0.165236 %|3.21 vs 32.15  (ms) |0.10|$\checkmark$||
|Log|0.082740 %|62.666664 %|4.05 vs 101.82  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.063863 %|0.135178 %|7.22 vs 59.47  (ms) |0.12|$\checkmark$||
|Pow(x,2)|1.649633 %|19.762378 %|7.01 vs 64.58  (ms) |0.11|$\checkmark$||
