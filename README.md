## deterministic_float
 * deterministic float, soft float
 * Fast soft float for deterministic computing, That
you can make deterministic physics engine、pathfind、AI engine by use my GFloat.
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
## How to start
 * Window Visual Studio 2022 ： open deterministic/deterministic_float.sln
 * XCode MacOS : open deterministic/deterministic_float.xcodeproj
 * XCode iOS   : open deterministic/deterministic_float_ios.xcodeproj 

## Current Support Platform
||Win64|MacOS| iOS| Android|
|--|--|--|--|--|
|| $\checkmark$  |$\checkmark$|$\checkmark$|  |





