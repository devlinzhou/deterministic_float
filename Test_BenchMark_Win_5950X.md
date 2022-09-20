# GFloat Test And BenchMark
 * Test time : Tue Sep 20 15:54:07 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of cmath result 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.44 vs 5.18  (ms) |0.28|$\checkmark$||
|Sub|0.000055 %|11.111112 %|1.44 vs 4.64  (ms) |0.31|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.44 vs 1.98  (ms) |0.73|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.93 vs 4.02  (ms) |0.48|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.75 vs 6.01  (ms) |1.29||$\checkmark$|
|Floor|0.000000 %|0.000000 %|8.41 vs 2.25  (ms) |3.74||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.31 vs 6.75  (ms) |0.19|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.35 vs 12.28  (ms) |0.11|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.29 vs 2.73  (ms) |0.47|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.41 vs 10.11  (ms) |0.63|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.32 vs 1.58  (ms) |0.84|$\checkmark$||
|Normalize|0.000004 %|0.000012 %|1.30 vs 2.48  (ms) |0.53|$\checkmark$||
|**Sin**|nan %|45.228764 %|40.43 vs 11.95  (ms) |3.38||$\checkmark$|
|Cos|nan %|261.497589 %|40.62 vs 11.59  (ms) |3.50||$\checkmark$|
|SinCos|0.721101 %|18304.041016 %|15.35 vs 19.52  (ms) |0.79|$\checkmark$||
|Tan|0.002301 %|48.244942 %|8.83 vs 20.37  (ms) |0.43|$\checkmark$||
|ASin|0.474575 %|14.587557 %|13.69 vs 14.39  (ms) |0.95|$\checkmark$||
|ACos|2.119713 %|7499.911621 %|12.66 vs 14.17  (ms) |0.89|$\checkmark$||
|ATan|0.000449 %|10.312484 %|9.66 vs 35.39  (ms) |0.27|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|10.61 vs 30.90  (ms) |0.34|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|10.84 vs 45.40  (ms) |0.24|$\checkmark$||
|**Sqrt**|0.000171 %|0.001550 %|1.37 vs 10.96  (ms) |0.13|$\checkmark$||
|invSqrt|0.000155 %|0.001526 %|1.82 vs 9.40  (ms) |0.19|$\checkmark$||
|**Exp**|0.018479 %|0.165236 %|5.29 vs 34.64  (ms) |0.15|$\checkmark$||
|Log|0.082660 %|62.666660 %|3.81 vs 112.82  (ms) |0.03|$\checkmark$||
|Pow(2,x)|0.058890 %|0.134814 %|7.39 vs 63.21  (ms) |0.12|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|7.38 vs 75.25  (ms) |0.10|$\checkmark$||
