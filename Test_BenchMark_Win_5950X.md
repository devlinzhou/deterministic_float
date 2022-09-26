# GFloat Test And BenchMark
 * Test time : Mon Sep 26 12:24:27 2022

|Operation System| C++ Compiler version |CPU  | Base Frequency  |
|:--:|:--:|:--:|:--:|
|Windows 64-bit|Visual Studio 1932|AMD Ryzen 9 5950X 16-Core Processor            |3.39 GHz or  0 GHz |
 * Performance: float vs GFloat,  Call 10000000 times
 * Error : the relative error between cmath (double) and GFloat Math 

|Function| avg error|max error| float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add       |  0.000080 %|    100.000000 %| 5.91 vs 25.15  (ms)|0.23|$\checkmark$||
|Sub       |  0.000071 %|    100.000000 %| 5.10 vs 33.47  (ms)|0.15|$\checkmark$||
|Mul       |  0.000014 %|      0.000071 %| 4.96 vs 10.58  (ms)|0.47|$\checkmark$||
|Div       |  0.000011 %|      0.000047 %| 7.94 vs 26.63  (ms)|0.30|$\checkmark$||
|Ceil      |  0.000009 %|      2.439024 %|52.91 vs 38.96  (ms)|1.36||$\checkmark$|
|Floor     |  0.000000 %|      0.000000 %|53.96 vs 10.76  (ms)|5.02||$\checkmark$|
|Whole     |  0.000004 %|      0.478469 %| 4.61 vs 60.13  (ms)|0.08|$\checkmark$||
|WholeFrac |  0.005600 %|    100.000000 %| 3.86 vs 114.74  (ms)|0.03|$\checkmark$||
|Normalize |  0.000004 %|      0.000012 %| 3.94 vs 16.16  (ms)|0.24|$\checkmark$||
|FromInt   |  0.000000 %|      0.000000 %| 5.05 vs 18.54  (ms)|0.27|$\checkmark$||
|-()       |  0.000004 %|      0.000012 %| 4.10 vs  7.34  (ms)|0.56|$\checkmark$||
|<         |  0.000004 %|      0.000012 %| 4.92 vs 82.80  (ms)|0.06|$\checkmark$||
|Abs       |  0.000004 %|      0.000012 %| 3.68 vs 36.24  (ms)|0.10|$\checkmark$||
|Sin       |  0.260215 %|  59821.586166 %|95.57 vs 44.35  (ms)|2.15||$\checkmark$|
|Cos       |  0.216922 %|  43022.149136 %|92.15 vs 43.05  (ms)|2.14||$\checkmark$|
|SinCos    |  4.468659 %|  89368.214121 %|129.06 vs 130.60  (ms)|0.99|$\checkmark$||
|Tan       |  0.519819 %| 159408.985436 %|90.88 vs 106.71  (ms)|0.85|$\checkmark$||
|ASin      |  0.476074 %|     14.600747 %|103.44 vs 128.57  (ms)|0.80|$\checkmark$||
|ACos      |  4.129791 %|   8161.920041 %|97.00 vs 172.95  (ms)|0.56|$\checkmark$||
|ATan      |  2.081510 %|     10.347402 %|103.48 vs 168.80  (ms)|0.61|$\checkmark$||
|ATan(10,x)|  0.083215 %|     18.925117 %|85.99 vs 298.36  (ms)|0.29|$\checkmark$||
|ATan(x,10)|  0.324061 %|     18.926010 %|89.13 vs 358.35  (ms)|0.25|$\checkmark$||
|Sqrt      |  0.000171 %|      0.001553 %|10.40 vs 89.36  (ms)|0.12|$\checkmark$||
|InvSqrt   |  0.000154 %|      0.001532 %|17.59 vs 73.68  (ms)|0.24|$\checkmark$||
|Exp       |  0.023401 %|      0.165553 %|19.85 vs 288.97  (ms)|0.07|$\checkmark$||
|Log       |  0.964328 %|     67.734638 %|26.14 vs 1058.83  (ms)|0.02|$\checkmark$||
|Pow(2,x)  |  0.063851 %|      0.135222 %|55.68 vs 611.56  (ms)|0.09|$\checkmark$||
|Pow(x,2)  | 14.666046 %|     64.879814 %|55.33 vs 682.70  (ms)|0.08|$\checkmark$||
