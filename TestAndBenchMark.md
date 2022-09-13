### Call Function: cmath vs GFloat math1000000Times 
|Function| avg error|max error| Performance float vs GFloat | float / GFloat | float fast| GFloat fast|
|--|--|--|--|--|--|--|
|Add|0.000064 %|5.882353 %|2.15 - 11.61  (ms) |0.18|$\checkmark$||
|Sub|0.000057 %|11.111112 %|2.05 - 12.49  (ms) |0.16|$\checkmark$||
|Mul|0.000011 %|0.000047 %|2.08 - 3.94  (ms) |0.53|$\checkmark$||
|Div|0.000011 %|0.000048 %|2.07 - 5.49  (ms) |0.38|$\checkmark$||
|Ceil|0.000009 %|0.116550 %|10.17 - 6.32  (ms) |1.61||$\checkmark$|
|Floor|0.000000 %|0.000000 %|10.31 - 2.49  (ms) |4.14||$\checkmark$|
|Whole|0.000004 %|0.000012 %|1.78 - 15.65  (ms) |0.11|$\checkmark$||
|Sin|0.203093 %|96.925941 %|14.78 - 21.88  (ms) |0.68|$\checkmark$||
|Cos|457.826233 %|1187674.000000 %|16.13 - 28.26  (ms) |0.57|$\checkmark$||
|Tan|3834.031250 %|120035864.000000 %|15.29 - 45.69  (ms) |0.33|$\checkmark$||
|ASin|1.279024 %|100.000000 %|18.12 - 17.08  (ms) |1.06||$\checkmark$|
|ACos|3.210914 %|9229.877930 %|16.96 - 26.00  (ms) |0.65|$\checkmark$||
|ATan|0.000449 %|10.312468 %|13.15 - 64.56  (ms) |0.20|$\checkmark$||
|ATan(10,x)|0.002387 %|10.290107 %|14.20 - 59.41  (ms) |0.24|$\checkmark$||
|ATan(x,10)|0.003450 %|10.345943 %|14.29 - 79.91  (ms) |0.18|$\checkmark$||
