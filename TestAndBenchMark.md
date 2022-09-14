### Call Function: cmath vs GFloat math1000000Times 
|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|2.20 - 14.14  (ms) |0.16|$\checkmark$||
|Sub|0.000057 %|11.111112 %|2.16 - 14.80  (ms) |0.15|$\checkmark$||
|Mul|0.000011 %|0.000047 %|2.20 - 5.12  (ms) |0.43|$\checkmark$||
|Div|0.000011 %|0.000048 %|2.65 - 6.98  (ms) |0.38|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|11.73 - 6.96  (ms) |1.68||$\checkmark$|
|Floor|0.000000 %|0.000000 %|11.44 - 2.80  (ms) |4.08||$\checkmark$|
|Whole|0.000004 %|0.000012 %|2.01 - 17.86  (ms) |0.11|$\checkmark$||
|Sin|145.312622 %|46582.132812 %|16.72 - 11.48  (ms) |1.46||$\checkmark$|
|Sqrt|8.995338 %|57.559483 %|2.00 - 14.41  (ms) |0.14|$\checkmark$||
|invSqrt|8.995339 %|57.559471 %|2.68 - 9.60  (ms) |0.28|$\checkmark$||
|Exp|0.010056 %|0.061122 %|4.59 - 141.35  (ms) |0.03|$\checkmark$||
|Log|inf %|inf %|5.79 - 356.72  (ms) |0.02|$\checkmark$||
|Pow(2,x)|0.056069 %|0.141206 %|10.43 - 257.38  (ms) |0.04|$\checkmark$||
|Pow(x,2)|1.646391 %|100.000000 %|11.05 - 265.35  (ms) |0.04|$\checkmark$||
