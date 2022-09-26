# GFloat Test And BenchMark
 * Test time : Tue Sep 27 00:22:23 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1931|12th Gen Intel(R) Core(TM) i9-12900H|2.92 GHz or  2.9 GHz |
 * Performance: float vs GFloat,  Call 2000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000000 %|      0.000000 %| 0.88 vs  3.17  (ms)|0.28|$\checkmark$||
|Sub       |  0.000099 %|    100.000000 %| 0.88 vs  4.76  (ms)|0.19|$\checkmark$||
|Mul       |  0.000014 %|      0.000071 %| 0.86 vs  1.42  (ms)|0.61|$\checkmark$||
|Div       |  0.000011 %|      0.000047 %| 1.38 vs  4.62  (ms)|0.30|$\checkmark$||
|Ceil      |  0.000009 %|      0.781250 %|11.40 vs  5.27  (ms)|2.16||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %|11.15 vs  1.71  (ms)|6.51||$\checkmark$|
|Whole     |  0.000004 %|      0.338983 %| 0.79 vs 11.46  (ms)|0.07|$\checkmark$||
|WholeFrac |  0.000004 %|      0.000012 %| 0.78 vs 14.89  (ms)|0.05|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 0.70 vs  1.83  (ms)|0.38|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 0.78 vs  2.23  (ms)|0.35|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 0.86 vs  1.08  (ms)|0.80|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 0.91 vs 15.26  (ms)|0.06|$\checkmark$||
|Abs       |  0.000004 %|      0.000012 %| 0.82 vs  8.69  (ms)|0.09|$\checkmark$||
|Sin       |  0.000064 %|      2.318618 %| 4.14 vs 16.64  (ms)|0.25|$\checkmark$||
|Cos       |  0.545417 %|  45301.917045 %|16.48 vs 17.25  (ms)|0.96|$\checkmark$||
|SinCos    |  0.395063 %|  73044.076252 %|25.01 vs 34.62  (ms)|0.72|$\checkmark$||
|Tan       |  0.425419 %|  50528.119428 %|16.94 vs 14.62  (ms)|1.16||$\checkmark$|
|ASin      |  2.024203 %|      3.519171 %|18.70 vs 15.44  (ms)|1.21||$\checkmark$|
|ACos      |  0.863858 %|   6582.283104 %|18.62 vs 15.74  (ms)|1.18||$\checkmark$|
|ATan      |  0.000038 %|      0.021311 %|14.78 vs 39.42  (ms)|0.37|$\checkmark$||
|ATan(10,x)|  0.010550 %|      0.021383 %|18.77 vs 53.73  (ms)|0.35|$\checkmark$||
|ATan(x,10)|  0.000121 %|      0.021407 %|18.09 vs 68.40  (ms)|0.26|$\checkmark$||
|Sqrt      |  0.000171 %|      0.001553 %| 1.33 vs 14.43  (ms)|0.09|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001529 %| 2.43 vs 10.23  (ms)|0.24|$\checkmark$||
|Exp       |  0.023412 %|      0.165236 %| 4.78 vs 48.29  (ms)|0.10|$\checkmark$||
|Log_e     |  0.000127 %|      0.154715 %| 4.88 vs  7.17  (ms)|0.68|$\checkmark$||
|Log_2     |  0.000126 %|      0.154719 %|37.91 vs  6.64  (ms)|5.71||$\checkmark$|
|Pow(2,x)  |  0.023153 %|      0.055230 %|10.00 vs 63.20  (ms)|0.16|$\checkmark$||
|Pow(x,2)  |  0.012261 %|      0.064361 %| 9.65 vs 49.82  (ms)|0.19|$\checkmark$||
