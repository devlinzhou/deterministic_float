# GFloat Test And BenchMark
 * Test time : Mon Sep 19 00:58:20 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of camth result 

|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000064 %|5.882353 %|1.25 - 9.81  (ms) |0.13|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.23 - 9.97  (ms) |0.12|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.25 - 1.54  (ms) |0.81|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.15 - 2.57  (ms) |0.45|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|8.12 - 3.56  (ms) |2.28||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.55 - 1.52  (ms) |4.96||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.32 - 7.56  (ms) |0.17|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.14 - 8.49  (ms) |0.13|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.33 - 1.57  (ms) |0.85|$\checkmark$||
|operator <|0.000004 %|0.000012 %|5.82 - 13.68  (ms) |0.43|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.43 - 1.16  (ms) |1.24||$\checkmark$|
|**Sin**|0.710684 %|28671.109375 %|10.57 - 7.68  (ms) |1.38||$\checkmark$|
|Cos|0.685160 %|14656.369141 %|10.70 - 8.34  (ms) |1.28||$\checkmark$|
|SinCos|0.721101 %|18304.041016 %|13.90 - 22.25  (ms) |0.62|$\checkmark$||
|Tan|0.002439 %|48.244942 %|8.53 - 15.43  (ms) |0.55|$\checkmark$||
|ASin|0.896484 %|18.060110 %|12.05 - 7.81  (ms) |1.54||$\checkmark$|
|ACos|3.210415 %|9229.857422 %|11.19 - 7.83  (ms) |1.43||$\checkmark$|
|ATan|0.000449 %|10.312484 %|10.04 - 24.63  (ms) |0.41|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|10.90 - 20.42  (ms) |0.53|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|10.81 - 32.05  (ms) |0.34|$\checkmark$||
|**Sqrt**|0.000171 %|0.001550 %|1.03 - 7.73  (ms) |0.13|$\checkmark$||
|invSqrt|0.000155 %|0.001526 %|1.30 - 6.74  (ms) |0.19|$\checkmark$||
|Exp|0.018479 %|0.165236 %|2.77 - 25.22  (ms) |0.11|$\checkmark$||
|Log|0.082660 %|62.666660 %|3.25 - 66.89  (ms) |0.05|$\checkmark$||
|Pow(2,x)|0.058783 %|0.134614 %|6.12 - 47.27  (ms) |0.13|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|6.46 - 50.30  (ms) |0.13|$\checkmark$||
