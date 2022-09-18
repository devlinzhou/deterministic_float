# GFloat Test And BenchMark
 * Test time : Sun Sep 18 22:11:47 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of camth result 

|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|1.07 - 9.37  (ms) |0.11|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.15 - 9.60  (ms) |0.12|$\checkmark$||
|Mul|0.000014 %|0.000070 %|1.18 - 1.63  (ms) |0.72|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.24 - 2.72  (ms) |0.46|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.13 - 2.93  (ms) |2.43||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.38 - 1.46  (ms) |5.07||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.22 - 7.68  (ms) |0.16|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.11 - 9.01  (ms) |0.12|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.29 - 1.42  (ms) |0.91|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.24 - 13.63  (ms) |0.46|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.55 - 1.08  (ms) |1.44||$\checkmark$|
|Sin|0.710684 %|28671.109375 %|11.39 - 8.52  (ms) |1.34||$\checkmark$|
|Cos|0.685160 %|14656.369141 %|10.51 - 7.72  (ms) |1.36||$\checkmark$|
|SinCos|0.721101 %|18304.041016 %|14.57 - 22.63  (ms) |0.64|$\checkmark$||
|Tan|0.002439 %|48.244942 %|8.68 - 16.18  (ms) |0.54|$\checkmark$||
|ASin|0.896484 %|18.060110 %|11.93 - 8.05  (ms) |1.48||$\checkmark$|
|ACos|3.210415 %|9229.857422 %|11.98 - 7.94  (ms) |1.51||$\checkmark$|
|ATan|0.000449 %|10.312484 %|9.79 - 24.47  (ms) |0.40|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|10.90 - 20.48  (ms) |0.53|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|10.53 - 34.43  (ms) |0.31|$\checkmark$||
|Sqrt|0.000029 %|0.000135 %|1.09 - 13.55  (ms) |0.08|$\checkmark$||
|invSqrt|0.000013 %|0.000101 %|1.46 - 11.35  (ms) |0.13|$\checkmark$||
|Exp|0.018479 %|0.165236 %|3.03 - 25.03  (ms) |0.12|$\checkmark$||
|Log|0.082660 %|62.666660 %|2.92 - 69.25  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.058783 %|0.134614 %|6.35 - 45.92  (ms) |0.14|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|6.49 - 48.33  (ms) |0.13|$\checkmark$||
