# GFloat Test And BenchMark
 * Test time : Wed Sep 21 15:16:22 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.82 vs 4.36  (ms) |0.42|$\checkmark$||
|Sub|0.000055 %|11.111111 %|1.84 vs 4.50  (ms) |0.41|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.91 vs 1.99  (ms) |0.96|$\checkmark$||
|Div|0.000011 %|0.000046 %|1.90 vs 4.10  (ms) |0.46|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|8.46 vs 6.32  (ms) |1.34||$\checkmark$|
|Floor|0.000000 %|0.000000 %|8.36 vs 1.78  (ms) |4.69||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.61 vs 6.84  (ms) |0.24|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.60 vs 11.83  (ms) |0.14|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.57 vs 2.62  (ms) |0.60|$\checkmark$||
|<|0.000004 %|0.000012 %|7.15 vs 10.05  (ms) |0.71|$\checkmark$||
|-()|0.000004 %|0.000012 %|1.70 vs 1.50  (ms) |1.13||$\checkmark$|
|Normalize|0.000004 %|0.000012 %|1.64 vs 2.45  (ms) |0.67|$\checkmark$||
|**Sin**|0.000906 %|128.728364 %|12.97 vs 5.13  (ms) |2.53||$\checkmark$|
|Cos|0.000816 %|83.296263 %|12.59 vs 5.31  (ms) |2.37||$\checkmark$|
|SinCos|0.197822 %|9571.942496 %|16.31 vs 13.15  (ms) |1.24||$\checkmark$|
|Tan|0.001088 %|41.104408 %|9.79 vs 12.30  (ms) |0.80|$\checkmark$||
|ASin|16.197711 %|619481.438329 %|14.01 vs 26.88  (ms) |0.52|$\checkmark$||
|ACos|1.134938 %|704.893861 %|13.40 vs 33.52  (ms) |0.40|$\checkmark$||
|ATan|0.000448 %|10.312487 %|10.45 vs 34.75  (ms) |0.30|$\checkmark$||
|ATan(10,x)|0.002442 %|10.290108 %|11.20 vs 30.37  (ms) |0.37|$\checkmark$||
|ATan(x,10)|0.003470 %|10.345940 %|11.66 vs 47.75  (ms) |0.24|$\checkmark$||
|**Sqrt**|0.000170 %|0.001553 %|1.87 vs 11.65  (ms) |0.16|$\checkmark$||
|invSqrt|0.000154 %|0.001526 %|2.18 vs 9.87  (ms) |0.22|$\checkmark$||
|**Exp**|0.023400 %|0.165236 %|4.36 vs 35.37  (ms) |0.12|$\checkmark$||
|Log|0.082740 %|62.666664 %|4.53 vs 102.26  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.063863 %|0.135178 %|7.51 vs 62.87  (ms) |0.12|$\checkmark$||
|Pow(x,2)|1.649633 %|19.762378 %|7.64 vs 67.58  (ms) |0.11|$\checkmark$||
