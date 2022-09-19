# GFloat Test And BenchMark
 * Test time : 
|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|--|--|--|--|
|Mac OSX|Apple LLVM 13.1.6 (clang-1316.0.21.2.5)|Apple Arm CPU|0.024 GHz or  0.024 GHz |
 * Math: float vs GFloat,  Call 1000000 times
 * Error is the relative of camth result 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.41 - 2.38  (ms) |0.59|$\checkmark$||
|Sub|0.000055 %|11.111112 %|1.51 - 2.75  (ms) |0.55|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.51 - 1.56  (ms) |0.97|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.51 - 2.50  (ms) |0.61|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|1.20 - 2.58  (ms) |0.46|$\checkmark$||
|Floor|0.000000 %|0.000000 %|1.15 - 1.38  (ms) |0.83|$\checkmark$||
|Whole|0.000004 %|0.116550 %|1.15 - 6.50  (ms) |0.18|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.14 - 7.73  (ms) |0.15|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.30 - 1.65  (ms) |0.79|$\checkmark$||
|operator <|0.000004 %|0.000012 %|1.47 - 2.96  (ms) |0.49|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.18 - 1.32  (ms) |0.90|$\checkmark$||
|Normalize|0.000004 %|0.000012 %|1.22 - 1.50  (ms) |0.81|$\checkmark$||
|**Sin**|0.710684 %|28671.109375 %|2.89 - 7.65  (ms) |0.38|$\checkmark$||
|Cos|0.685160 %|14656.369141 %|2.91 - 7.60  (ms) |0.38|$\checkmark$||
|SinCos|0.721101 %|18304.041016 %|20.32 - 13.83  (ms) |1.47||$\checkmark$|
|Tan|0.002301 %|48.244942 %|8.11 - 15.37  (ms) |0.53|$\checkmark$||
|ASin|0.896484 %|18.060116 %|8.20 - 6.33  (ms) |1.30||$\checkmark$|
|ACos|3.210415 %|9229.857422 %|10.46 - 6.76  (ms) |1.55||$\checkmark$|
|ATan|0.000449 %|10.312484 %|2.98 - 25.00  (ms) |0.12|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|7.76 - 21.83  (ms) |0.36|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345935 %|8.08 - 35.76  (ms) |0.23|$\checkmark$||
|**Sqrt**|0.000171 %|0.001550 %|1.20 - 8.91  (ms) |0.13|$\checkmark$||
|invSqrt|0.000155 %|0.001526 %|1.24 - 7.34  (ms) |0.17|$\checkmark$||
|Exp|0.018479 %|0.165236 %|7.84 - 22.01  (ms) |0.36|$\checkmark$||
|Log|0.082660 %|62.666660 %|2.56 - 73.85  (ms) |0.03|$\checkmark$||
|Pow(2,x)|0.058890 %|0.134814 %|2.65 - 47.71  (ms) |0.06|$\checkmark$||
|Pow(x,2)|1.646183 %|19.762375 %|1.14 - 49.50  (ms) |0.02|$\checkmark$||
Program ended with exit code: 0