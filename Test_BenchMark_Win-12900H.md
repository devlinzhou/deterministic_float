# GFloat Test And BenchMark
### Operation System  : Windows 64-bit
### CPU : 12th Gen Intel(R) Core(TM) i9-12900H
### CPU Base Frequency by Compute    : 2.92 GHz
### CPU Base Frequency by GetCPUInfo : 2.9 GHz
### The C++ compiler version is: Visual Studio 1931
### Math: float vs GFloat,  Call 1000000 times per function
### Error is the relative of camth result 1000000 times per function
|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|1.32 - 9.47  (ms) |0.14|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.15 - 9.44  (ms) |0.12|$\checkmark$||
|Mul|0.000014 %|0.000070 %|1.08 - 1.55  (ms) |0.69|$\checkmark$||
|Div|0.000011 %|0.000048 %|2.01 - 5.04  (ms) |0.40|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.79 - 3.16  (ms) |2.47||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.29 - 1.36  (ms) |5.35||$\checkmark$|
|Whole|0.000004 %|0.116550 %|0.98 - 6.93  (ms) |0.14|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.07 - 8.55  (ms) |0.13|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|0.91 - 1.42  (ms) |0.64|$\checkmark$||
|operator <|0.000004 %|0.000012 %|5.84 - 14.42  (ms) |0.41|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.02 - 1.30  (ms) |0.78|$\checkmark$||
|Sin|0.710684 %|28671.109375 %|10.64 - 8.33  (ms) |1.28||$\checkmark$|
|Cos|0.685160 %|14656.369141 %|10.41 - 8.24  (ms) |1.26||$\checkmark$|
|SinCos|0.721101 %|18304.041016 %|14.40 - 23.35  (ms) |0.62|$\checkmark$||
|Tan|3864.040283 %|47282160.000000 %|10.38 - 26.25  (ms) |0.40|$\checkmark$||
|ASin|0.896484 %|18.060110 %|11.80 - 7.95  (ms) |1.48||$\checkmark$|
|ACos|3.210415 %|9229.857422 %|12.10 - 8.25  (ms) |1.47||$\checkmark$|
|ATan|0.000449 %|10.312484 %|10.67 - 31.21  (ms) |0.34|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|15.10 - 20.81  (ms) |0.73|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|11.04 - 33.87  (ms) |0.33|$\checkmark$||
|Sqrt|0.063725 %|20.955256 %|1.03 - 21.38  (ms) |0.05|$\checkmark$||
|invSqrt|0.063668 %|20.955137 %|1.33 - 20.44  (ms) |0.07|$\checkmark$||
|Exp|0.018479 %|0.165236 %|2.78 - 25.49  (ms) |0.11|$\checkmark$||
|Log|0.082660 %|62.666660 %|3.21 - 73.42  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.058783 %|0.134614 %|6.39 - 47.30  (ms) |0.14|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|6.27 - 50.23  (ms) |0.12|$\checkmark$||
