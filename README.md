## deterministic_float
 * Cross-platform deterministic float point, fast soft float point.
 * Fast soft float point for deterministic computing, That
you can make **deterministic plugin** by use GFloat to replace float-point. like：
    * Physics Engine (Bullet、PhysX)
    * AI Path Finding (Recast Navigation)
    * AI Engine
 * Compare the overall performance of float754 and GFloat numbers, They differ by no more than **100%**
    * **Is the fastest soft floating point in the world**?

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
 * Most inportance function compare, more information to view TestAndBenchMark 
 * Call every function 1000000 Times, get the float vs GFloat time

  <table  >
    <tr>
        <th colspan = "1" >OS</th>
        <th align="center" colspan = "2" >Win 5950X</th>
        <th align="center" colspan = "2" >Win 12900H</th>
        <th align="center" colspan = "2" >iOS A15</th>
        <th align="center" colspan = "2" >OSX M1pro</th>
        <th align="center" colspan = "2" >Android</th>
    </tr>
    <tr>
        <td > </td>
        <td >float</td><td >GFloat</td><td >float</td><td >GFloat</td>
        <td >float</td><td >GFloat</td><td >float</td><td >GFloat</td>
        <td >float</td><td >GFloat</td>
    </tr>
    <tr>
        <td>Add</td><td>1.47ms</td><td >4.3ms</td><td>1.20ms</td><td>2.79ms</td>
        <td>1.36ms</td><td >2.14ms</td><td>1.41ms</td><td>2.38ms</td><td></td><td></td>
    </tr>
    <tr>
        <td>Mul</td><td>1.58ms</td><td >2.0ms</td><td>1.25ms</td><td>1.54ms</td>
        <td>1.42ms</td><td>1.38ms</td><td>1.51ms</td><td>1.56ms</td><td></td><td></td>
    </tr>
      <tr>
        <td>Sin</td><td>12.08ms</td><td >15.25ms</td><td>10.57ms</td><td>7.68ms</td>
        <td>2.84ms</td><td>6.65ms</td><td>2.89ms</td><td>7.65ms</td><td></td><td></td>
    </tr>
      <tr>
        <td>Sqrt</td><td>1.54ms</td><td >11.46ms</td><td>1.03ms</td><td> 7.73ms</td>
        <td>1.14ms </td><td>7.75ms </td><td>1.20ms</td><td>8.91ms</td><td></td><td></td>
    </tr>
      <tr>
        <td>Exp</td><td>3.33ms</td><td >35.06ms</td><td>3.06ms</td><td>28.20ms</td>
        <td>7.24ms</td><td>19.70ms</td><td>7.84ms</td><td>22.01ms</td><td></td><td></td>
    </tr>
    </table>
	
	
## How to start
 * Four OS platform projects for fast and easy to start test&benchmark

|Target Platform| Compiler| Project |
|:--|:--|:--|
|Win|Visual Studio 2022| deterministic/deterministic_float.sln|
|MacOS|XCode| deterministic/deterministic_float.xcodeproj |
|iOS|XCode| deterministic/deterministic_float_ios.xcodeproj |
|Android||todo|

## Current Support Platform For Test&Benchmark 
|Operation System|Win64|MacOS| iOS| Android|
|--|--|--|--|--|
|Yes or No | $\checkmark$  |$\checkmark$|$\checkmark$| todo |





