# GFloat Test And BenchMark
### Operation System  : Windows 64-bit
### CPU : AMD Ryzen 9 5950X 16-Core Processor            
### CPU Base Frequency by Compute    : 3.39 GHz
### CPU Base Frequency by GetCPUInfo : 0 GHz
### The C++ compiler version is: Visual Studio 1932
### Math: float vs GFloat,  Call 1000000 times per function
|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|1.43 - 8.84  (ms) |0.16|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.41 - 9.42  (ms) |0.15|$\checkmark$||
|Mul|0.000011 %|0.000047 %|1.48 - 3.08  (ms) |0.48|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.40 - 4.07  (ms) |0.34|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.47 - 4.36  (ms) |1.71||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.58 - 1.84  (ms) |4.12||$\checkmark$|
|Whole|0.000004 %|0.033956 %|1.30 - 6.97  (ms) |0.19|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.30 - 11.38  (ms) |0.11|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.24 - 2.61  (ms) |0.47|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.33 - 14.17  (ms) |0.45|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.25 - 1.51  (ms) |0.83|$\checkmark$||
|Sin|0.851353 %|2119.013916 %|11.68 - 38.73  (ms) |0.30|$\checkmark$||
|Cos|0.852330 %|1849.828125 %|11.54 - 42.28  (ms) |0.27|$\checkmark$||
|Tan|11.252217 %|5760.838379 %|11.07 - 71.75  (ms) |0.15|$\checkmark$||
|ASin|1.691105 %|100.000000 %|12.79 - 12.55  (ms) |1.02||$\checkmark$|
|ACos|3.212385 %|9229.857422 %|12.48 - 11.99  (ms) |1.04||$\checkmark$|
|ATan|0.028279 %|10.312484 %|9.32 - 30.25  (ms) |0.31|$\checkmark$||
|ATan(10,x)|43.590416 %|100.000000 %|10.37 - 24.83  (ms) |0.42|$\checkmark$||
|ATan(x,10)|0.134983 %|100.000000 %|10.47 - 39.12  (ms) |0.27|$\checkmark$||
|Sqrt|0.063807 %|20.955223 %|1.37 - 42.53  (ms) |0.03|$\checkmark$||
|invSqrt|0.063796 %|20.955204 %|1.82 - 35.59  (ms) |0.05|$\checkmark$||
|Exp|0.012545 %|0.784185 %|3.10 - 52.12  (ms) |0.06|$\checkmark$||
|Log|0.083722 %|99.999954 %|3.99 - 111.16  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.062345 %|0.781039 %|8.68 - 76.13  (ms) |0.11|$\checkmark$||
|Pow(x,2)|1.655677 %|19.762711 %|6.76 - 70.15  (ms) |0.10|$\checkmark$||
