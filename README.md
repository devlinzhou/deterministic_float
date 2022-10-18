## deterministic_float
 * Cross-platform deterministic float point, fast soft float point.
 * Fast soft float point for deterministic computing, That
you can make **deterministic plugin** by use GFloat to replace float-point. like：
    * Physics Engine (Bullet、PhysX)
    * AI Path Finding (Recast Navigation)
    * AI Engine
 * Compare the overall performance of hard float IEEE-754 and GFloat numbers, They differ by no more than 500%, Refer to the multiply-add instructions for measuring the computing power of the graphics card. compare multiply and add function:



  * 跨平台的确定性浮点数，高性能的软件浮点数
  * 你可以使用GFloat替代各种中间件的浮点数，从而实现带确定性的计算，实现帧同步游戏逻辑，也可以实现加密货币计算逻辑，例如：
    * 物理引擎（Bullet、PhysX）
    * AI 寻路（Recast Navigation）
    * AI 引擎
  * 整体上GFloat与IEEE754的硬件浮点数float，性能差距在500%以内。参考显卡衡量计算能力的乘加指令，主要比较乘法和加法函数的性能：
 
 

## Performance float（IEEE-754） vs GFloat
 * Several important functions compare, for more information to view TestAndBenchMark 
 * Call every function 1000000 Times, get the float vs GFloat time

Platform|Win64 5950X|Win64 12900H | iOS A15 | MacOS M1 Pro | Android HUAWEI P40 <br /> HiSilicon KIRIN 990|
|:--|:--:|:--:|:--:|:--:|:--:|
| |float vs GFloat| float vs GFloat| float vs GFloat|float vs GFloat |float vs GFloat
|Add|0.63 vs 2.63 ms| 0.44 vs 1.48ms| 0.43 vs 1.85 ms|0.34 vs 2.24 ms | 0.89 vs 8.76 ms
|Mul|0.70 vs 1.14 ms| 0.52 vs 0.79 ms| 0.42 vs 0.78 ms |0.34 vs 0.93 ms|0.62 vs 2.10 ms
|Sin|10.20 vs 8.39 ms|8.6 vs 3.15 ms| 3.6 vs 4.9 ms|2.29 vs 5.28 ms | 11.58 vs 15.75 ms
|Sqrt|1.08 vs 9.29  ms|0.7 vs 6.2 ms|0.83 vs 5.64 ms |0.64 vs 6.06 ms| 0.65 vs 15.77 ms
|Exp| 2.06 vs 10.83ms| 2.15 vs 24.52ms|5.52 vs 7.03 ms|5.75 vs 6.52 ms| 6.06 vs 20.90 ms
	
## How to start
 * Four OS platform projects for fast and easy to start test&benchmark

|Target Platform| Compiler| Project |
|:--|:--|:--|
|Win|Visual Studio 2022| deterministic/deterministic_float.sln|
|MacOS|XCode 13.4| deterministic/deterministic_float.xcodeproj |
|iOS|XCode 13.4| deterministic/deterministic_float_ios.xcodeproj |
|Android||todo|

## Current Support Platform For Test&Benchmark 
|Operation System|Win64|MacOS| iOS| Android|
|--|:--:|:--:|:--:|:--:|
|Yes or No | $\checkmark$  |$\checkmark$|$\checkmark$| $\checkmark$ |





