# GFloat Test And BenchMark
 * Test time : Wed Sep 21 01:13:00 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|**Add**|0.000060 %|5.882353 %|1.38 vs 2.76  (ms) |0.50|$\checkmark$||
|Sub|0.000055 %|11.111111 %|1.43 vs 3.06  (ms) |0.47|$\checkmark$||
|**Mul**|0.000014 %|0.000070 %|1.35 vs 2.57  (ms) |0.53|$\checkmark$||
|Div|0.000011 %|0.000046 %|1.30 vs 2.54  (ms) |0.51|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|9.23 vs 3.63  (ms) |2.54||$\checkmark$|
|Floor|0.000000 %|0.000000 %|8.16 vs 1.39  (ms) |5.85||$\checkmark$|
|Whole|0.000004 %|0.116550 %|1.30 vs 7.14  (ms) |0.18|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.11 vs 9.11  (ms) |0.12|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.10 vs 1.55  (ms) |0.71|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.60 vs 8.81  (ms) |0.75|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.12 vs 1.11  (ms) |1.01||$\checkmark$|
|Normalize|0.000004 %|0.000012 %|1.10 vs 1.52  (ms) |0.73|$\checkmark$||
|**Sin**|0.257541 %|44763.586797 %|11.41 vs 8.47  (ms) |1.35||$\checkmark$|
|Cos|0.186992 %|14628.054743 %|11.36 vs 7.93  (ms) |1.43||$\checkmark$|
|SinCos|0.204831 %|10198.547922 %|15.54 vs 13.17  (ms) |1.18||$\checkmark$|
|Tan|0.002080 %|77.621651 %|8.56 vs 14.64  (ms) |0.58|$\checkmark$||
|ASin|0.474911 %|14.587558 %|13.81 vs 9.00  (ms) |1.53||$\checkmark$|
|ACos|2.121228 %|7499.911452 %|13.37 vs 9.13  (ms) |1.46||$\checkmark$|
|ATan|0.000448 %|10.312487 %|10.09 vs 26.61  (ms) |0.38|$\checkmark$||
|ATan(10,x)|0.002442 %|10.290108 %|11.00 vs 26.81  (ms) |0.41|$\checkmark$||
|ATan(x,10)|0.003470 %|10.345940 %|11.02 vs 38.14  (ms) |0.29|$\checkmark$||
|**Sqrt**|0.000170 %|0.001553 %|1.66 vs 7.77  (ms) |0.21|$\checkmark$||
|invSqrt|0.000154 %|0.001526 %|1.32 vs 6.53  (ms) |0.20|$\checkmark$||
|**Exp**|0.018340 %|0.165236 %|3.08 vs 25.26  (ms) |0.12|$\checkmark$||
|Log|0.082740 %|62.666664 %|3.37 vs 76.03  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.063778 %|0.135178 %|6.84 vs 50.88  (ms) |0.13|$\checkmark$||
|Pow(x,2)|1.649633 %|19.762378 %|6.98 vs 53.05  (ms) |0.13|$\checkmark$||
