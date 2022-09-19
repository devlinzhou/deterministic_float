# GFloat Test And BenchMark
 * Test time : Mon Sep 19 09:41:21 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of camth result 

|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000064 %|5.882353 %|1.45 - 9.81  (ms) |0.15|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.53 - 10.91  (ms) |0.14|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.46 - 2.55  (ms) |0.57|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.46 - 4.58  (ms) |0.32|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.75 - 5.72  (ms) |1.36||$\checkmark$|
|Floor|0.000000 %|0.000000 %|8.23 - 2.35  (ms) |3.50||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.61 - 8.34  (ms) |0.19|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.39 - 15.09  (ms) |0.09|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.53 - 2.86  (ms) |0.53|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.35 - 14.35  (ms) |0.44|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.53 - 1.90  (ms) |0.80|$\checkmark$||
|**Sin**|0.710684 %|28671.109375 %|12.26 - 12.78  (ms) |0.96|$\checkmark$||
|Cos|0.685160 %|14656.369141 %|12.25 - 13.39  (ms) |0.91|$\checkmark$||
|SinCos|0.721101 %|18304.041016 %|16.54 - 28.89  (ms) |0.57|$\checkmark$||
|Tan|0.002439 %|48.244942 %|9.41 - 21.28  (ms) |0.44|$\checkmark$||
|ASin|0.896484 %|18.060110 %|14.22 - 16.48  (ms) |0.86|$\checkmark$||
|ACos|3.210415 %|9229.857422 %|13.75 - 13.99  (ms) |0.98|$\checkmark$||
|ATan|0.000449 %|10.312484 %|9.88 - 34.80  (ms) |0.28|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|10.85 - 26.49  (ms) |0.41|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|10.62 - 41.34  (ms) |0.26|$\checkmark$||
|**Sqrt**|0.000171 %|0.001550 %|1.40 - 14.69  (ms) |0.10|$\checkmark$||
|invSqrt|0.000155 %|0.001526 %|1.84 - 11.47  (ms) |0.16|$\checkmark$||
|Exp|0.018479 %|0.165236 %|3.22 - 32.08  (ms) |0.10|$\checkmark$||
|Log|0.082660 %|62.666660 %|3.90 - 94.54  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.058783 %|0.134614 %|7.33 - 60.93  (ms) |0.12|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|7.23 - 63.27  (ms) |0.11|$\checkmark$||
