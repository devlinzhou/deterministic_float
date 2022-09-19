## deterministic_float
 * Deterministic float point, soft float point.
 * Fast soft float point for deterministic computing, That
you can make **deterministic plugin** ：**Physics Engine**、**PathFinding**(recast navigation)、**AI Engine** by use GFloat to replace float-point.
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
## Performance float vs GFloat
 * Some main fuction compare，more information view TestAndBenchMark 
 * call 1000000 Times, float vs GFloat time

|Function|Win64 5950X|Win64 12900H | iOS M1 Pro | Android |
|:--|:--:|:--: |:--:|:--:|
|add|1.47 - 4.3 (ms)| | |
|Mul|1.58 - 2.0 (ms)| 1.25 - 1.54 (ms)|  |
|Sin|12.08 - 15.25 (ms)|10.57 - 7.68 (ms)| |
|Sqrt|1.54 - 11.46 (ms)|1.03 - 7.73 (ms) ||
|Exp| | ||
	
	
## How to start
 * Four OS platform project for fast and easy to start test&benchmark

|Target Platform| Compiler| Project |
|:--|:--|:--|
|Win|Visual Studio 2022| deterministic/deterministic_float.sln|
|MacOS|XCode| deterministic/deterministic_float.xcodeproj |
|iOS|XCode| deterministic/deterministic_float_ios.xcodeproj |
|Android||todo|

## Current Support Platform For Test&Benchmark 
|Operation System|Win64|MacOS| iOS| Android|
|--|--|--|--|--|
|Now| $\checkmark$  |$\checkmark$|$\checkmark$| todo |





