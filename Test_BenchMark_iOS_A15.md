# GFloat Test And BenchMark
 * Test time :  
 
|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Mac OSX|Apple LLVM 13.1.6 (clang-1316.0.21.2.5)|Apple A15 CPU|0.024 GHz or  0.024 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of camth result 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.36 - 2.14  (ms) |0.64|$\checkmark$||
|Sub|0.000055 %|11.111112 %|1.36 - 2.25  (ms) |0.60|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.42 - 1.38  (ms) |1.03||$\checkmark$|
|Div|0.000011 %|0.000048 %|1.36 - 2.13  (ms) |0.64|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|1.08 - 2.31  (ms) |0.47|$\checkmark$||
|Floor|0.000000 %|0.000000 %|1.08 - 1.54  (ms) |0.70|$\checkmark$||
|Whole|0.000004 %|0.116550 %|1.14 - 6.22  (ms) |0.18|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.08 - 7.09  (ms) |0.15|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.11 - 1.56  (ms) |0.71|$\checkmark$||
|operator <|0.000004 %|0.000012 %|1.43 - 2.57  (ms) |0.56|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.16 - 1.25  (ms) |0.92|$\checkmark$||
|Normalize|0.000004 %|0.000012 %|1.08 - 1.55  (ms) |0.70|$\checkmark$||
|**Sin**|0.710684 %|28671.109375 %|2.84 - 6.65  (ms) |0.43|$\checkmark$||
|Cos|0.685160 %|14656.369141 %|2.89 - 6.63  (ms) |0.44|$\checkmark$||
|SinCos|0.721101 %|18304.041016 %|19.19 - 13.15  (ms) |1.46||$\checkmark$|
|Tan|0.002301 %|48.244942 %|7.59 - 14.33  (ms) |0.53|$\checkmark$||
|ASin|0.896484 %|18.060116 %|7.48 - 5.50  (ms) |1.36||$\checkmark$|
|ACos|3.210415 %|9229.857422 %|9.30 - 5.68  (ms) |1.64||$\checkmark$|
|ATan|0.000449 %|10.312484 %|2.81 - 22.53  (ms) |0.12|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|7.02 - 19.86  (ms) |0.35|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345935 %|7.15 - 33.17  (ms) |0.22|$\checkmark$||
|**Sqrt**|0.000171 %|0.001550 %|1.14 - 7.75  (ms) |0.15|$\checkmark$||
|invSqrt|0.000155 %|0.001526 %|1.18 - 6.41  (ms) |0.18|$\checkmark$||
|Exp|0.018479 %|0.165236 %|7.24 - 19.70  (ms) |0.37|$\checkmark$||
|Log|0.082660 %|62.666660 %|2.49 - 71.07  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.058890 %|0.134814 %|2.54 - 44.99  (ms) |0.06|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|1.15 - 47.28  (ms) |0.02|$\checkmark$||