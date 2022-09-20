# GFloat Test And BenchMark
 * Test time : Tue Sep 20 11:49:48 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of cmath result 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.45 vs 4.34  (ms) |0.33|$\checkmark$||
|Sub|0.000055 %|11.111112 %|1.53 vs 4.61  (ms) |0.33|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.46 vs 1.98  (ms) |0.74|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.47 vs 4.04  (ms) |0.36|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.58 vs 6.37  (ms) |1.19||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.81 vs 2.27  (ms) |3.44||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.33 vs 7.03  (ms) |0.19|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.28 vs 12.18  (ms) |0.11|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.36 vs 2.70  (ms) |0.50|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.85 vs 10.12  (ms) |0.68|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.31 vs 1.54  (ms) |0.85|$\checkmark$||
|Normalize|0.000004 %|0.000012 %|1.32 vs 2.48  (ms) |0.53|$\checkmark$||
|**Sin**|0.710684 %|28671.109375 %|11.98 vs 11.81  (ms) |1.01||$\checkmark$|
|Cos|0.685160 %|14656.369141 %|11.80 vs 11.66  (ms) |1.01||$\checkmark$|
|SinCos|0.721101 %|18304.041016 %|15.54 vs 19.57  (ms) |0.79|$\checkmark$||
|Tan|0.002301 %|48.244942 %|9.01 vs 19.80  (ms) |0.46|$\checkmark$||
|ASin|0.896484 %|18.060110 %|13.37 vs 13.53  (ms) |0.99|$\checkmark$||
|ACos|3.210415 %|9229.857422 %|12.81 vs 12.94  (ms) |0.99|$\checkmark$||
|ATan|0.000449 %|10.312484 %|9.61 vs 36.30  (ms) |0.26|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|10.84 vs 31.06  (ms) |0.35|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|11.07 vs 45.41  (ms) |0.24|$\checkmark$||
|**Sqrt**|0.000171 %|0.001550 %|1.41 vs 11.47  (ms) |0.12|$\checkmark$||
|invSqrt|0.000155 %|0.001526 %|1.85 vs 9.54  (ms) |0.19|$\checkmark$||
|**Exp**|0.018479 %|0.165236 %|3.12 vs 31.94  (ms) |0.10|$\checkmark$||
|Log|0.082660 %|62.666660 %|3.91 vs 108.80  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.058890 %|0.134814 %|7.26 vs 61.57  (ms) |0.12|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|7.38 vs 67.34  (ms) |0.11|$\checkmark$||
