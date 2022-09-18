# GFloat Test And BenchMark
 * Test time : Sun Sep 18 22:52:56 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of camth result 

|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|1.15 - 9.03  (ms) |0.13|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.25 - 9.85  (ms) |0.13|$\checkmark$||
|Mul|0.000014 %|0.000070 %|1.23 - 1.64  (ms) |0.75|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.16 - 2.67  (ms) |0.43|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|8.01 - 3.16  (ms) |2.54||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.46 - 1.50  (ms) |4.97||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.34 - 7.01  (ms) |0.19|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.09 - 8.35  (ms) |0.13|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.24 - 1.51  (ms) |0.82|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.55 - 14.90  (ms) |0.44|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.36 - 1.06  (ms) |1.28||$\checkmark$|
|Sin|0.710684 %|28671.109375 %|10.86 - 8.11  (ms) |1.34||$\checkmark$|
|Cos|0.685160 %|14656.369141 %|10.44 - 10.63  (ms) |0.98|$\checkmark$||
|SinCos|0.721101 %|18304.041016 %|14.65 - 23.18  (ms) |0.63|$\checkmark$||
|Tan|0.002439 %|48.244942 %|8.65 - 15.19  (ms) |0.57|$\checkmark$||
|ASin|0.896484 %|18.060110 %|11.49 - 7.40  (ms) |1.55||$\checkmark$|
|ACos|3.210415 %|9229.857422 %|12.80 - 7.79  (ms) |1.64||$\checkmark$|
|ATan|0.000449 %|10.312484 %|9.83 - 24.32  (ms) |0.40|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|11.35 - 20.34  (ms) |0.56|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|10.05 - 30.48  (ms) |0.33|$\checkmark$||
|Sqrt|0.000171 %|0.001550 %|1.00 - 7.32  (ms) |0.14|$\checkmark$||
|invSqrt|0.000155 %|0.001526 %|1.47 - 7.01  (ms) |0.21|$\checkmark$||
|Exp|0.018479 %|0.165236 %|2.77 - 25.25  (ms) |0.11|$\checkmark$||
|Log|0.082660 %|62.666660 %|2.71 - 66.41  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.058783 %|0.134614 %|6.46 - 46.61  (ms) |0.14|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|6.49 - 49.65  (ms) |0.13|$\checkmark$||
