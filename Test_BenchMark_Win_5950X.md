# GFloat Test And BenchMark
 * Test time : Tue Sep 20 11:37:35 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of cmath result 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.41 - 4.33  (ms) |0.33|$\checkmark$||
|Sub|0.000055 %|11.111112 %|1.42 - 4.54  (ms) |0.31|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.51 - 1.97  (ms) |0.77|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.49 - 4.21  (ms) |0.35|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.49 - 6.35  (ms) |1.18||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.50 - 1.79  (ms) |4.18||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.78 - 6.88  (ms) |0.26|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.23 - 11.97  (ms) |0.10|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.30 - 2.64  (ms) |0.49|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.28 - 10.14  (ms) |0.62|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.32 - 1.62  (ms) |0.82|$\checkmark$||
|Normalize|0.000004 %|0.000012 %|1.31 - 3.53  (ms) |0.37|$\checkmark$||
|**Sin**|0.710684 %|28671.109375 %|12.77 - 13.04  (ms) |0.98|$\checkmark$||
|Cos|0.685160 %|14656.369141 %|11.90 - 11.80  (ms) |1.01||$\checkmark$|
|SinCos|0.721101 %|18304.041016 %|16.45 - 26.20  (ms) |0.63|$\checkmark$||
|Tan|0.002301 %|48.244942 %|9.00 - 20.39  (ms) |0.44|$\checkmark$||
|ASin|0.896484 %|18.060110 %|13.62 - 13.39  (ms) |1.02||$\checkmark$|
|ACos|3.210415 %|9229.857422 %|13.70 - 13.60  (ms) |1.01||$\checkmark$|
|ATan|0.000449 %|10.312484 %|9.80 - 36.74  (ms) |0.27|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|10.71 - 30.99  (ms) |0.35|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|11.09 - 47.26  (ms) |0.23|$\checkmark$||
|**Sqrt**|0.000171 %|0.001550 %|1.38 - 11.70  (ms) |0.12|$\checkmark$||
|invSqrt|0.000155 %|0.001526 %|1.85 - 9.71  (ms) |0.19|$\checkmark$||
|Exp|0.018479 %|0.165236 %|3.33 - 35.06  (ms) |0.10|$\checkmark$||
|Log|0.082660 %|62.666660 %|4.21 - 104.08  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.058890 %|0.134814 %|6.86 - 58.99  (ms) |0.12|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|7.33 - 66.53  (ms) |0.11|$\checkmark$||
