# GFloat Test And BenchMark
 * Test time : Mon Sep 19 22:38:33 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of cmath result 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.20 - 2.79  (ms) |0.43|$\checkmark$||
|Sub|0.000055 %|11.111112 %|1.26 - 3.61  (ms) |0.35|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.24 - 1.46  (ms) |0.84|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.43 - 2.61  (ms) |0.55|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|8.35 - 3.66  (ms) |2.28||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.96 - 1.37  (ms) |5.80||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.19 - 7.19  (ms) |0.17|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.16 - 9.86  (ms) |0.12|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.20 - 1.67  (ms) |0.72|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.73 - 9.97  (ms) |0.67|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.16 - 1.39  (ms) |0.84|$\checkmark$||
|Normalize|0.000004 %|0.000012 %|1.18 - 1.53  (ms) |0.77|$\checkmark$||
|**Sin**|0.710684 %|28671.109375 %|11.44 - 11.10  (ms) |1.03||$\checkmark$|
|Cos|0.685160 %|14656.369141 %|11.57 - 8.81  (ms) |1.31||$\checkmark$|
|SinCos|0.721101 %|18304.041016 %|17.59 - 15.18  (ms) |1.16||$\checkmark$|
|Tan|0.002301 %|48.244942 %|9.04 - 17.30  (ms) |0.52|$\checkmark$||
|ASin|0.896484 %|18.060110 %|13.26 - 8.73  (ms) |1.52||$\checkmark$|
|ACos|3.210415 %|9229.857422 %|14.76 - 8.51  (ms) |1.73||$\checkmark$|
|ATan|0.000449 %|10.312484 %|10.55 - 27.76  (ms) |0.38|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|14.61 - 27.96  (ms) |0.52|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|10.73 - 44.15  (ms) |0.24|$\checkmark$||
|**Sqrt**|0.000171 %|0.001550 %|1.19 - 8.44  (ms) |0.14|$\checkmark$||
|invSqrt|0.000155 %|0.001526 %|1.45 - 7.36  (ms) |0.20|$\checkmark$||
|Exp|0.018479 %|0.165236 %|3.06 - 28.20  (ms) |0.11|$\checkmark$||
|Log|0.082660 %|62.666660 %|3.11 - 79.35  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.058890 %|0.134814 %|6.71 - 59.47  (ms) |0.11|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|6.78 - 55.25  (ms) |0.12|$\checkmark$||
