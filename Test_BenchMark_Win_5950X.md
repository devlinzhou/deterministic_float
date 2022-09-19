# GFloat Test And BenchMark
 * Test time : Mon Sep 19 10:05:00 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of camth result 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.47 - 4.30  (ms) |0.34|$\checkmark$||
|Sub|0.000055 %|11.111112 %|1.49 - 4.69  (ms) |0.32|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.58 - 2.00  (ms) |0.79|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.58 - 4.14  (ms) |0.38|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.69 - 6.08  (ms) |1.27||$\checkmark$|
|Floor|0.000000 %|0.000000 %|8.23 - 1.83  (ms) |4.49||$\checkmark$|
|Whole|0.000004 %|0.116550 %|2.18 - 7.97  (ms) |0.27|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.39 - 11.98  (ms) |0.12|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.39 - 2.66  (ms) |0.52|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.41 - 9.98  (ms) |0.64|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.38 - 1.56  (ms) |0.89|$\checkmark$||
|Normalize|0.000004 %|0.000012 %|1.34 - 2.44  (ms) |0.55|$\checkmark$||
|**Sin**|756.064392 %|9636070.000000 %|12.08 - 15.25  (ms) |0.79|$\checkmark$||
|Cos|0.685160 %|14656.369141 %|12.49 - 12.32  (ms) |1.01||$\checkmark$|
|SinCos|0.721101 %|18304.041016 %|17.78 - 21.05  (ms) |0.84|$\checkmark$||
|Tan|nan %|48.244942 %|27.92 - 20.04  (ms) |1.39||$\checkmark$|
|ASin|111.663696 %|42083.195312 %|13.01 - 13.01  (ms) |1.00|$\checkmark$||
|ACos|1870.734009 %|15473491.000000 %|14.60 - 13.06  (ms) |1.12||$\checkmark$|
|ATan|0.000449 %|10.312484 %|9.91 - 35.77  (ms) |0.28|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|10.91 - 31.56  (ms) |0.35|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|11.00 - 47.49  (ms) |0.23|$\checkmark$||
|**Sqrt**|0.000171 %|0.001550 %|1.54 - 11.46  (ms) |0.13|$\checkmark$||
|invSqrt|0.000155 %|0.001526 %|1.93 - 9.63  (ms) |0.20|$\checkmark$||
|Exp|nan %|16171132928.000000 %|28.81 - 32.98  (ms) |0.87|$\checkmark$||
|Log|0.082660 %|62.666660 %|4.19 - 105.43  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.058890 %|0.134814 %|7.33 - 64.06  (ms) |0.11|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|7.24 - 67.14  (ms) |0.11|$\checkmark$||
