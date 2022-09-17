# GFloat Test And BenchMark
### Operation System  : Windows 64-bit
### CPU : 12th Gen Intel(R) Core(TM) i9-12900H
### CPU Base Frequency by Compute    : 2.92 GHz
### CPU Base Frequency by GetCPUInfo : 2.9 GHz
### The C++ compiler version is: Visual Studio 1931
### Math: float vs GFloat,  Call 1000000 times per function
|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|1.07 - 8.82  (ms) |0.12|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.27 - 9.75  (ms) |0.13|$\checkmark$||
|Mul|0.000011 %|0.000047 %|1.19 - 1.76  (ms) |0.68|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.30 - 2.55  (ms) |0.51|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|8.40 - 3.07  (ms) |2.74||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.45 - 1.57  (ms) |4.75||$\checkmark$|
|Whole|0.000004 %|0.033956 %|0.99 - 6.70  (ms) |0.15|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.10 - 8.99  (ms) |0.12|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|0.98 - 1.55  (ms) |0.63|$\checkmark$||
|operator <|0.000004 %|0.000012 %|5.92 - 14.11  (ms) |0.42|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.10 - 1.32  (ms) |0.84|$\checkmark$||
|Sin|0.891018 %|17402.228516 %|10.79 - 31.99  (ms) |0.34|$\checkmark$||
|SinTable|226.618286 %|19956082.000000 %|10.85 - 8.56  (ms) |1.27||$\checkmark$|
|Cos|0.864097 %|24585.277344 %|10.26 - 35.06  (ms) |0.29|$\checkmark$||
|Tan|1.605866 %|17397.841797 %|9.79 - 55.97  (ms) |0.17|$\checkmark$||
|ASin|0.896484 %|18.060110 %|12.64 - 8.32  (ms) |1.52||$\checkmark$|
|ACos|3.210415 %|9229.857422 %|11.88 - 7.82  (ms) |1.52||$\checkmark$|
|ATan|0.000449 %|10.312484 %|10.16 - 24.88  (ms) |0.41|$\checkmark$||
|ATan(10,x)|0.002432 %|10.290107 %|10.10 - 20.30  (ms) |0.50|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|10.63 - 31.58  (ms) |0.34|$\checkmark$||
|Sqrt|0.063807 %|20.955223 %|0.93 - 25.62  (ms) |0.04|$\checkmark$||
|invSqrt|0.063796 %|20.955204 %|1.56 - 23.14  (ms) |0.07|$\checkmark$||
|Exp|0.009381 %|0.059776 %|2.60 - 37.95  (ms) |0.07|$\checkmark$||
|Log|0.082670 %|62.666660 %|2.85 - 89.52  (ms) |0.03|$\checkmark$||
|Pow(2,x)|0.060173 %|0.141206 %|5.93 - 55.53  (ms) |0.11|$\checkmark$||
|Pow(x,2)|1.646202 %|19.762711 %|6.41 - 55.25  (ms) |0.12|$\checkmark$||
