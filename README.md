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

|Platform|Win64 5950X|Win64 12900H | iOS A15 | MacOS M1 Pro | Android |
|:--|:--:|:--: |:--:|:--:|:--:|
|Add|1.47 - 4.3 ms|1.20 - 2.79  (ms)  | 1.36 - 2.14 ms|1.41 - 2.38 ms |
|Mul|1.58 - 2.0 ms| 1.25 - 1.54 ms| 1.42 - 1.38 ms |1.51 - 1.56 ms|
|Sin|12.08 - 15.25 ms|10.57 - 7.68 ms| 2.84 - 6.65 ms|2.89 - 7.65 ms |
|Sqrt|1.54 - 11.46 ms|1.03 - 7.73 ms|1.14 - 7.75 ms |1.20 - 8.91 ms|
|Exp|  |3.06 - 28.20  (ms) |7.24 - 19.70 ms|7.84 - 22.01 ms|

  <table  >
    <tr>
        <th colspan = "1" >Platform</th>
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
        <td>Add</td><td>1.47ms</td><td >4.3ms</td><td>1.20</td><td>2.79</td>
        <td>1.36</td><td >2.14</td><td>1.41</td><td>2.38</td><td></td><td></td>
    </tr>
    <tr>
        <td>Mul</td><td>1.58</td><td >2.0</td><td>1.25</td><td>1.54</td>
        <td>1.42</td><td>1.38</td><td>1.51</td><td>1.56</td><td></td><td></td>
    </tr>
      <tr>
        <td>Sin</td><td>12.08</td><td >15.25</td><td>10.57</td><td>7.68</td>
        <td>2.84</td><td>6.65</td><td>2.89</td><td>7.65</td><td></td><td></td>
    </tr>
      <tr>
        <td>Sqrt</td><td>1.54</td><td >11.46</td><td>1.03</td><td> 7.73</td>
        <td>1.14 </td><td>7.75 </td><td>1.20</td><td>8.91</td><td></td><td></td>
    </tr>
      <tr>
        <td>Exp</td><td></td><td ></td><td>3.06</td><td>28.20</td>
        <td>7.24</td><td>19.70</td><td>7.84</td><td>22.01</td><td></td><td></td>
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





