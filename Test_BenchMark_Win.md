# GFloat Test And BenchMark
### OS : Windows 64-bit
### CPU : AMD Ryzen 9 5950X 16-Core Processor            
### CPU frequency : 3.38GHz
### Math: float vs GFloat,  Call 1000000 times per function
|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|1.64 - 9.74  (ms) |0.17|$\checkmark$||
|Sub|0.000057 %|11.111112 %|1.61 - 10.13  (ms) |0.16|$\checkmark$||
|Mul|0.000011 %|0.000047 %|1.62 - 3.56  (ms) |0.45|$\checkmark$||
|Div|0.000011 %|0.000048 %|1.60 - 4.46  (ms) |0.36|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|7.77 - 5.54  (ms) |1.40||$\checkmark$|
|Floor|0.000000 %|0.000000 %|7.64 - 2.30  (ms) |3.33||$\checkmark$|
|Whole|0.000004 %|0.033956 %|1.32 - 7.61  (ms) |0.17|$\checkmark$||
|WholeFrac|0.000004 %|0.000012 %|1.50 - 12.90  (ms) |0.12|$\checkmark$||
|FromInt|0.000000 %|0.000000 %|1.28 - 2.63  (ms) |0.49|$\checkmark$||
|operator <|0.000004 %|0.000012 %|6.66 - 14.61  (ms) |0.46|$\checkmark$||
|operator -|0.000004 %|0.000012 %|1.42 - 1.95  (ms) |0.73|$\checkmark$||
|Sin|0.851353 %|2119.013916 %|12.73 - 45.08  (ms) |0.28|$\checkmark$||
|Cos|0.852330 %|1849.828125 %|12.67 - 45.12  (ms) |0.28|$\checkmark$||
|Tan|11.252217 %|5760.838379 %|11.84 - 79.83  (ms) |0.15|$\checkmark$||
|ASin|1.691105 %|100.000000 %|12.93 - 13.44  (ms) |0.96|$\checkmark$||
|ACos|3.212385 %|9229.857422 %|12.75 - 12.98  (ms) |0.98|$\checkmark$||
|ATan|0.028279 %|10.312484 %|9.54 - 31.69  (ms) |0.30|$\checkmark$||
|ATan(10,x)|43.590416 %|100.000000 %|10.72 - 25.76  (ms) |0.42|$\checkmark$||
|ATan(x,10)|0.134983 %|100.000000 %|11.18 - 41.42  (ms) |0.27|$\checkmark$||
|Sqrt|0.063807 %|20.955223 %|1.52 - 43.07  (ms) |0.04|$\checkmark$||
|invSqrt|0.063796 %|20.955204 %|1.80 - 36.21  (ms) |0.05|$\checkmark$||
|Exp|0.012545 %|0.784185 %|3.07 - 49.35  (ms) |0.06|$\checkmark$||
|Log|0.083722 %|99.999954 %|3.76 - 106.81  (ms) |0.04|$\checkmark$||
|Pow(2,x)|0.062345 %|0.781039 %|7.04 - 73.93  (ms) |0.10|$\checkmark$||
|Pow(x,2)|1.655677 %|19.762711 %|6.91 - 72.41  (ms) |0.10|$\checkmark$||
