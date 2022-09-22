## deterministic_float
 * Cross-platform deterministic float point, fast soft float point.
 * Fast soft float point for deterministic computing, That
you can make **deterministic plugin** by use GFloat to replace float-point. like：
    * Physics Engine (Bullet、PhysX)
    * AI Path Finding (Recast Navigation)
    * AI Engine
 * Compare the overall performance of float754 and GFloat numbers, They differ by no more than **500%**, Refer to the multiply-add instructions for measuring the computing power of the graphics card. compare multiply and add function:
    * Windows platform my GFloat's performance is nearly 400% slower than float
    * Apple platform(ARM64 CPU) GFloat's performance is  200% slower than float


  * 跨平台的确定性浮点数，高性能的软件浮点数
  * 你可以使用我的浮点数替代各种中间件的浮点数，从而实现带确定性的计算，实现帧同步游戏逻辑，也可以实现加密货币计算逻辑，例如：
    * 物理引擎（Bullet、PhysX）
    * AI 寻路（Recast Navigation）
    * AI 引擎
  * 整体上我的GFloat 与 IEEE754 硬件浮点数float 性能差距 maybe 500%。参考显卡衡量计算能力的乘加指令，主要比较乘法和加法函数的性能。
    * windows平台上 GFloat比float慢400%
    * 苹果平台（ARM64 CPU)，GFloat比float慢200%
 

## IEEE-754 & My GFloat
* IEEE-754 float
  <table  >
    <tr>
        <th align="center" >sign</th>
        <th align="center" colspan = "5" width="400">exponents（8 bits）</th>
        <th align="center" colspan = "5" width="400">fractions（23 bits）</th>
    </tr>
    <tr>
        <td >31</td>
        <td >30</td><td>29</td><td>...</td><td>24</td><td>23</td>
        <td >22</td><td>21</td><td>...</td><td>1</td><td>0</td>
    </tr>
    </table>

    * $\mathbf{X}_{IEEE754} = (-1)^\mathbf{sign} \times (1.\mathbf{fraction}) \times 2 ^{\mathbf{exponent} - 127}$
* My GFloat
  <table  >
    <tr>
        <th align="center" >sign</th>
        <th align="center" colspan = "5" width="400">fractions（23 bits）</th>
        <th align="center" colspan = "5" width="400">exponents（8 bits）</th>
    </tr>
    <tr>
        <td >31</td>
        <td >30</td><td>29</td><td>...</td><td>9</td><td>8</td>
        <td >7</td><td>6</td><td>...</td><td>1</td><td>0</td>
    </tr>
    </table>
    
    * $\mathbf{X}_{GFloat} = (-1)^\mathbf{sign} \times (\mathbf{fraction}) \times 2 ^{\mathbf{exponent} - 127}$

## Performance float vs GFloat
 * Several important functions compare, for more information to view TestAndBenchMark 
 * Call every function 1000000 Times, get the float vs GFloat time

Platform|Win64 5950X|Win64 12900H | iOS A15 | MacOS M1 Pro | Android |
|:--|:--:|:--: |:--:|:--:|:--:|
| |float vs GFloat| float vs GFloat| float vs GFloat|float vs GFloat |float vs GFloat
|add|1.47 vs 4.3 ms| 1.20 vs	2.79ms| 1.36 vs 2.14 ms|1.41 vs 2.38 ms |
|Mul|1.58 vs 2.0 ms| 1.25 vs 1.54 ms| 1.42 vs 1.38 ms |1.51 vs 1.56 ms|
|Sin|12.08 vs 5.71 ms|10.57 vs 7.68 ms| 2.84 vs 6.65 ms|2.89 vs 7.65 ms |
|Sqrt|1.54 vs 11.46 ms|1.03 vs 7.73 ms|1.14 vs 7.75 ms |1.20 vs 8.91 ms|
|Exp| 3.33 vs 35.06ms| 3.06 vs 28.20ms|7.24 vs 19.70 ms|7.84 vs 22.01 ms|
	
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
|--|--|--|--|--|
|Yes or No | $\checkmark$  |$\checkmark$|$\checkmark$| todo |





