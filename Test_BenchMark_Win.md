# GFloat Test And BenchMark
### OS  : Windows 64-bit
### CPU : AMD Ryzen 9 5950X 16-Core Processor            
### CPU Base Frequency by Compute    : 3.39 GHz
### CPU Base Frequency by GetCPUInfo : 0 GHz
### The C++ compiler version is: Visual Studio 1932
### Math: float vs GFloat,  Call 1000000 times per function
|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|1.44 - 8.81  (ms) |0.16|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.43 - 9.44  (ms) |0.15|$\checkmark$||
|Mul|0.000011 %|0.000047 %|1.49 - 3.05  (ms) |0.49|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.44 - 4.13  (ms) |0.35|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.55 - 4.46  (ms) |1.69||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.73 - 1.84  (ms) |4.21||$\checkmark$|
|Whole|0.000004 %|0.033956 %|1.33 - 6.99  (ms) |0.19|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.30 - 11.52  (ms) |0.11|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.34 - 2.65  (ms) |0.51|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.38 - 14.55  (ms) |0.44|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.36 - 1.59  (ms) |0.85|$\checkmark$||
|Sin|0.851353 %|2119.013916 %|11.95 - 39.29  (ms) |0.30|$\checkmark$||
|Cos|0.852330 %|1849.828125 %|11.67 - 43.17  (ms) |0.27|$\checkmark$||
|Tan|11.252217 %|5760.838379 %|11.34 - 73.21  (ms) |0.15|$\checkmark$||
|ASin|1.691105 %|100.000000 %|13.05 - 12.70  (ms) |1.03||$\checkmark$|
|ACos|3.212385 %|9229.857422 %|12.73 - 12.22  (ms) |1.04||$\checkmark$|
|ATan|0.028279 %|10.312484 %|9.57 - 30.95  (ms) |0.31|$\checkmark$||
|ATan(10,x)|43.590416 %|100.000000 %|10.55 - 25.07  (ms) |0.42|$\checkmark$||
|ATan(x,10)|0.134983 %|100.000000 %|10.68 - 39.76  (ms) |0.27|$\checkmark$||
|Sqrt|0.063807 %|20.955223 %|1.33 - 43.69  (ms) |0.03|$\checkmark$||
|invSqrt|0.063796 %|20.955204 %|1.84 - 36.11  (ms) |0.05|$\checkmark$||
|Exp|0.012545 %|0.784185 %|3.09 - 48.75  (ms) |0.06|$\checkmark$||
|Log|0.083722 %|99.999954 %|3.87 - 106.46  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.062345 %|0.781039 %|7.20 - 80.62  (ms) |0.09|$\checkmark$||
|Pow(x,2)|1.655677 %|19.762711 %|7.03 - 74.40  (ms) |0.09|$\checkmark$||
