## deterministic_float
 * Cross-platform deterministic float point, fast soft float point.
 * Fast soft float point for deterministic computing, That
you can make **deterministic plugin** by use GFloat to replace float-point. like：
    * Physics Engine (Bullet、PhysX)
    * AI Path Finding (Recast Navigation)
    * AI Engine
 * Compare the overall performance of hard float IEEE-754 and GFloat numbers, They differ by no more than 200%, Refer to the multiply-add instructions for measuring the computing power of the graphics card. compare multiply and add function:
    * Windows platform(Intel i9-12900H) my GFloat's performance is nearly 200% slower than float
    * Apple platform(ARM64 CPU) GFloat's performance is  200% slower than float


  * 跨平台的确定性浮点数，高性能的软件浮点数
  * 你可以使用GFloat替代各种中间件的浮点数，从而实现带确定性的计算，实现帧同步游戏逻辑，也可以实现加密货币计算逻辑，例如：
    * 物理引擎（Bullet、PhysX）
    * AI 寻路（Recast Navigation）
    * AI 引擎
  * 整体上GFloat与IEEE754的硬件浮点数float，性能差距在200%以内。参考显卡衡量计算能力的乘加指令，主要比较乘法和加法函数的性能：
    * windows(Intel i9-12900H)平台上GFloat比float慢200%
    * 苹果(ARM64 CPU)平台上GFloat比float慢200%
 

## IEEE-754 float & My GFloat
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

## Performance float（IEEE-754） vs GFloat
 * Several important functions compare, for more information to view TestAndBenchMark 
 * Call every function 1000000 Times, get the float vs GFloat time

Platform|Win64 5950X|Win64 12900H | iOS A15 | MacOS M1 Pro | Android |
|:--|:--:|:--: |:--:|:--:|:--:|
| |float vs GFloat| float vs GFloat| float vs GFloat|float vs GFloat |float vs GFloat
|add|0.63 vs 2.63 ms| 0.44 vs 1.48ms| 1.36 vs 2.14 ms|0.34 vs 2.24 ms |
|Mul|0.70 vs 1.14 ms| 0.52 vs 0.79 ms| 1.42 vs 1.38 ms |0.34 vs 0.93 ms|
|Sin|10.20 vs 4.99 ms|8.6 vs 3.15 ms| 2.84 vs 6.65 ms|2.29 vs 3.68 ms |
|Sqrt|1.08 vs 9.29  ms|0.7 vs 6.2 ms|1.14 vs 7.75 ms |0.64 vs 8.33 ms|
|Exp| 2.06 vs 29.81ms| 2.15 vs 24.52ms|7.24 vs 19.70 ms|5.75 vs 21.46 ms|
	
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





