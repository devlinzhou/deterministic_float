## deterministic_float
 * Deterministic float point, soft float point.
 * Fast soft float point for deterministic computing, That
you can make **deterministic plugin** ：**Physics Engine**、**PathFinding**(recast navigation)、**AI Engine** by use GFloat to replace float-point.
## IEEE-754 & My GFloat
* IEEE-754 float
  <table  >
    <tr>
        <th align="center" >sign</th>
        <th align="center" colspan = "5" width="400">exponent（8 bits）</th>
        <th align="center" colspan = "5" width="400">fraction（23 bits）</th>
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
        <th align="center" colspan = "5" width="400">fraction（23 bits）</th>
        <th align="center" colspan = "5" width="400">exponent（8 bits）</th>
    </tr>
    <tr>
        <td >31</td>
        <td >30</td><td>29</td><td>...</td><td>9</td><td>8</td>
        <td >7</td><td>6</td><td>...</td><td>1</td><td>0</td>
    </tr>
    </table>
## Performance float vs GFloat
 * Some main fuction compare，more information you can look TestAndBenchMark 
 * The ratio of performance, to do more optimization

|function|float ：GFloat(ratio)|
|--|:--:|
|add|5|
|Mul|1.05|
|Sin|10|
|Sqrt|30|
|exp|20|
	
	
## How to start
 * Window Visual Studio 2022 ： open deterministic/deterministic_float.sln
 * XCode MacOS : open deterministic/deterministic_float.xcodeproj
 * XCode iOS   : open deterministic/deterministic_float_ios.xcodeproj 

## Current Support Platform
|Operation System|Win64|MacOS| iOS| Android|
|--|--|--|--|--|
|Now| $\checkmark$  |$\checkmark$|$\checkmark$|  |





