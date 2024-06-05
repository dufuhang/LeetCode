### 思路
典型的DFS
```cpp
class Solution 
{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        //特殊情况
        if (grid.size() == 0) return 0;
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
        return maxArea;
    }
    int dfs(vector<vector<int>>& grid, int n_i, int n_j)
    {
        //超出边界，已被访问，本身是0,返回0
        if (n_i <0 || n_j < 0 || n_i >=grid.size() || n_j >= grid[0].size() || grid[n_i][n_j] == 0 || grid[n_i][n_j] == 2)
        {
            return 0;
        }
        //设置为2表示已被访问
        grid[n_i][n_j] =2;
        int area = 1;

        // //上
        // area += dfs(grid, n_i - 1, n_j);
        // //下
        // area += dfs(grid, n_i + 1, n_j);
        // //左
        // area += dfs(grid, n_i, n_j - 1);
        // //右
        // area += dfs(grid, n_i, n_j + 1);
        
        //使用数组控制方向
        vector<pair<int, int>> di= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int index = 0; index < 4; index++)
        {
            area += dfs(grid, n_i + di[index].first, n_j + di[index].second);
        }
        //返回结果
        return area;
    }
};
```