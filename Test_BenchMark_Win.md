# GFloat Test And BenchMark
### Operation System  : Windows 64-bit
### CPU : AMD Ryzen 9 5950X 16-Core Processor            
### CPU Base Frequency by Compute    : 3.39 GHz
### CPU Base Frequency by GetCPUInfo : 0 GHz
### The C++ compiler version is: Visual Studio 1932
### Math: float vs GFloat,  Call 1000000 times per function
|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|1.42 - 8.83  (ms) |0.16|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.47 - 9.44  (ms) |0.16|$\checkmark$||
|Mul|0.000011 %|0.000047 %|1.42 - 3.01  (ms) |0.47|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.44 - 4.04  (ms) |0.36|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.40 - 4.39  (ms) |1.69||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.64 - 1.85  (ms) |4.14||$\checkmark$|
|Whole|0.000004 %|0.033956 %|1.26 - 7.01  (ms) |0.18|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.33 - 11.71  (ms) |0.11|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.36 - 2.85  (ms) |0.48|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.15 - 14.23  (ms) |0.43|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.33 - 1.56  (ms) |0.85|$\checkmark$||
|Sin|0.851353 %|2119.013916 %|11.82 - 38.68  (ms) |0.31|$\checkmark$||
|Cos|0.852330 %|1849.828125 %|11.55 - 43.31  (ms) |0.27|$\checkmark$||
|Tan|11.252217 %|5760.838379 %|11.31 - 73.11  (ms) |0.15|$\checkmark$||
|ASin|1.691105 %|100.000000 %|12.90 - 12.40  (ms) |1.04||$\checkmark$|
|ACos|3.212385 %|9229.857422 %|12.52 - 12.01  (ms) |1.04||$\checkmark$|
|ATan|0.028279 %|10.312484 %|9.38 - 30.65  (ms) |0.31|$\checkmark$||
|ATan(10,x)|43.590416 %|100.000000 %|10.62 - 24.53  (ms) |0.43|$\checkmark$||
|ATan(x,10)|0.134983 %|100.000000 %|10.43 - 39.66  (ms) |0.26|$\checkmark$||
|Sqrt|0.063807 %|20.955223 %|2.45 - 42.77  (ms) |0.06|$\checkmark$||
|invSqrt|0.063796 %|20.955204 %|1.80 - 35.29  (ms) |0.05|$\checkmark$||
|Exp|0.012545 %|0.784185 %|3.14 - 51.19  (ms) |0.06|$\checkmark$||
|Log|0.083722 %|99.999954 %|4.21 - 114.09  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.062345 %|0.781039 %|7.85 - 78.66  (ms) |0.10|$\checkmark$||
|Pow(x,2)|1.655677 %|19.762711 %|6.95 - 72.77  (ms) |0.10|$\checkmark$||
