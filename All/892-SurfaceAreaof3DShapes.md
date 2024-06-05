### 思路
1、每个立方体提供6个表面积，每两个接触的立方体损失2个表面积

2、计算总的立方体，再计算有几个接触面，相减得到最终结果
```cpp
class Solution 
{
public:
    int surfaceArea(vector<vector<int>>& grid) 
    {
        int N = grid.size();
        //立方体的数量
        int cubes = 0;
        //接触面的数量
        int faces = 0;
        //遍历
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N;j++)
            {
                cubes += grid[i][j];
                //柱体内部接触面
                if (grid[i][j] > 0)
                {
                    faces += grid[i][j] - 1;
                }  
                //柱体与后面柱体的侧面接触面
                if (j != N - 1)
                {
                    faces += min(grid[i][j], grid[i][j+1]);
                }
                //柱体与左面柱体的侧面接触面
                if (i > 0)
                {
                    faces += min(grid[i][j], grid[i-1][j]);
                }
            }
        }
        return 6 * cubes - 2 * faces;
    }
};
```