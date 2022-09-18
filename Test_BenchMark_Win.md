# GFloat Test And BenchMark

|Operation System| C++ Compiler version |CPU Name | CPU Base Frequency  |
|--|--|--|--|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz (compute) 2.9 GHz (getCpuInfo)|
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of camth result 1000000 times per function

|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|1.24 - 9.82  (ms) |0.13|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.09 - 9.07  (ms) |0.12|$\checkmark$||
|Mul|0.000014 %|0.000070 %|1.52 - 1.65  (ms) |0.93|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.17 - 2.54  (ms) |0.46|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.78 - 3.56  (ms) |2.19||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.32 - 1.40  (ms) |5.22||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.03 - 6.65  (ms) |0.15|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.02 - 9.09  (ms) |0.11|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|0.92 - 1.42  (ms) |0.64|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.48 - 13.55  (ms) |0.48|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.02 - 1.03  (ms) |0.99|$\checkmark$||
|Sin|0.710684 %|28671.109375 %|10.12 - 7.35  (ms) |1.38||$\checkmark$|
|Cos|0.685160 %|14656.369141 %|9.62 - 7.69  (ms) |1.25||$\checkmark$|
|SinCos|0.721101 %|18304.041016 %|13.79 - 21.85  (ms) |0.63|$\checkmark$||
|Tan|0.002439 %|48.244942 %|8.59 - 15.37  (ms) |0.56|$\checkmark$||
|ASin|0.896484 %|18.060110 %|13.14 - 8.37  (ms) |1.57||$\checkmark$|
|ACos|3.210415 %|9229.857422 %|13.69 - 8.36  (ms) |1.64||$\checkmark$|
|ATan|0.000449 %|10.312484 %|10.75 - 26.84  (ms) |0.40|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|10.86 - 20.90  (ms) |0.52|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|10.83 - 32.88  (ms) |0.33|$\checkmark$||
|Sqrt|0.063725 %|20.955256 %|1.42 - 20.97  (ms) |0.07|$\checkmark$||
|invSqrt|0.063668 %|20.955137 %|1.32 - 19.83  (ms) |0.07|$\checkmark$||
|Exp|0.018479 %|0.165236 %|2.82 - 25.15  (ms) |0.11|$\checkmark$||
|Log|0.082660 %|62.666660 %|3.02 - 71.92  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.058783 %|0.134614 %|6.33 - 48.63  (ms) |0.13|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|6.08 - 50.40  (ms) |0.12|$\checkmark$||
