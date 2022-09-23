# GFloat Test And BenchMark
 * Test time : Fri Sep 23 20:10:13 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 1000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000062 %|      5.882353 %| 0.64 vs  2.50  (ms)|0.26|$\checkmark$||
|Sub       |  0.000057 %|     11.111111 %| 0.52 vs  3.12  (ms)|0.17|$\checkmark$||
|Mul       |  0.000014 %|      0.000070 %| 0.49 vs  1.10  (ms)|0.45|$\checkmark$||
|Div       |  0.000011 %|      0.000046 %| 0.78 vs  2.51  (ms)|0.31|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %| 5.41 vs  3.93  (ms)|1.37||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %| 5.40 vs  1.04  (ms)|5.21||$\checkmark$|
|Whole     |  0.000004 %|      0.142857 %| 0.48 vs  6.07  (ms)|0.08|$\checkmark$||
|WholeFrac |  0.005677 %|    100.000000 %| 0.43 vs 11.66  (ms)|0.04|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.65 vs  1.88  (ms)|0.34|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.56 vs  2.02  (ms)|0.28|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.59 vs  0.75  (ms)|0.79|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.73 vs  8.50  (ms)|0.09|$\checkmark$||
|Sin       |  0.254217 %|  44469.186153 %|10.29 vs  4.75  (ms)|2.16||$\checkmark$|
|Cos       |  0.180190 %|  14521.000767 %| 9.58 vs  4.49  (ms)|2.13||$\checkmark$|
|SinCos    |  4.426870 %|   9571.942496 %|13.72 vs 13.13  (ms)|1.05||$\checkmark$|
|Tan       |  0.425105 %|  44469.206359 %| 9.12 vs 10.77  (ms)|0.85|$\checkmark$||
|ASin      |  0.474911 %|     14.587558 %|10.84 vs 13.23  (ms)|0.82|$\checkmark$||
|ACos      |  4.105913 %|   7499.923180 %| 9.51 vs 17.08  (ms)|0.56|$\checkmark$||
|ATan      |  2.082313 %|     10.347341 %|10.99 vs 20.20  (ms)|0.54|$\checkmark$||
|ATan(10,x)|  0.083049 %|     18.788355 %| 8.87 vs 30.20  (ms)|0.29|$\checkmark$||
|ATan(x,10)|  0.325797 %|     18.915966 %| 8.89 vs 43.89  (ms)|0.20|$\checkmark$||
|Sqrt      |  0.000170 %|      0.001553 %| 1.07 vs  8.96  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001526 %| 1.79 vs  7.45  (ms)|0.24|$\checkmark$||
|Exp       |  0.023400 %|      0.165236 %| 2.00 vs 29.66  (ms)|0.07|$\checkmark$||
|Log       |  0.964962 %|     63.366195 %| 2.60 vs 100.33  (ms)|0.03|$\checkmark$||
|Pow(2,x)  |  0.063863 %|      0.135178 %| 5.59 vs 61.13  (ms)|0.09|$\checkmark$||
|Pow(x,2)  | 14.645987 %|     64.879200 %| 5.58 vs 66.78  (ms)|0.08|$\checkmark$||
