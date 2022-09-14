# deterministic_float
fast soft float for deterministic computing, that
you can make deterministic physics engine、pathfind、AI engine by use my GFloat.

the IEEE-745 float
  <table  >
    <tr>
        <th align="center" >sign（1bit）</th>
        <th align="center" colspan = "5" width="400">exponent（8 bits）</th>
        <th align="center" colspan = "5" width="400">fraction（23 bits）</th>
    </tr>
    <tr>
        <td >31</td>
        <td >30</td><td>29</td><td>...</td><td>24</td><td>23</td>
        <td >22</td><td>21</td><td>...</td><td>1</td><td>0</td>
    </tr>
    </table>


    my GFloat
  <table  >
    <tr>
        <th align="center" >sign（1bit）</th>
        <th align="center" colspan = "5" width="400">fraction（23 bits）</th>
        <th align="center" colspan = "5" width="400">exponent（8 bits）</th>
    </tr>
    <tr>
        <td >31</td>
        <td >30</td><td>29</td><td>...</td><td>24</td><td>23</td>
        <td >22</td><td>21</td><td>...</td><td>1</td><td>0</td>
    </tr>
    </table>





