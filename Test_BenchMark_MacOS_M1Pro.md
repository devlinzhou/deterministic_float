# GFloat Test And BenchMark
 * Test time : Thu Sep 22 20:38:29 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Mac OSX|Apple LLVM 13.1.6 (clang-1316.0.21.2.5)|Apple Arm CPU|0.024 GHz or  0.024 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000060 %|      5.882353 %| 0.34 vs  2.24  (ms)|0.15|$\checkmark$||
|Sub       |  0.000055 %|     11.111111 %| 0.33 vs  2.42  (ms)|0.14|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.34 vs  0.93  (ms)|0.37|$\checkmark$||
|Div       |  0.000011 %|      0.000047 %| 0.36 vs  2.18  (ms)|0.17|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 0.22 vs  2.26  (ms)|0.10|$\checkmark$||
|Floor     |  0.000000 %|      0.000000 %| 0.22 vs  0.70  (ms)|0.31|$\checkmark$||
|Whole     |  0.000004 %|      0.142857 %| 0.23 vs  4.16  (ms)|0.06|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.21 vs  1.00  (ms)|0.21|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.23 vs  1.37  (ms)|0.17|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.22 vs  0.56  (ms)|0.39|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.36 vs  2.44  (ms)|0.15|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %| 2.29 vs  3.68  (ms)|0.62|$\checkmark$||
|Cos       |  0.180190 %|  14521.000767 %| 2.28 vs  3.70  (ms)|0.62|$\checkmark$||
|Tan       |  0.425105 %|  44469.206359 %| 8.96 vs 10.40  (ms)|0.86|$\checkmark$||
|ASin      |  0.474911 %|     14.587558 %| 6.23 vs  6.77  (ms)|0.92|$\checkmark$||
|ACos      |  2.121254 %|   7499.923180 %| 7.93 vs 10.80  (ms)|0.73|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 0.64 vs  8.33  (ms)|0.08|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 0.97 vs  7.15  (ms)|0.14|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 5.75 vs 21.46  (ms)|0.27|$\checkmark$||
|Log       |  0.082740 %|     62.666664 %| 2.00 vs 73.76  (ms)|0.03|$\checkmark$||