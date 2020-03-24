### 思路
橘子的腐烂是向外一层一层的扩散，所以可使用BFS来解答。
### 主要步骤：
- 将统计新鲜橘子的数量
- 将腐烂的橘子入队
- 从队中取出腐烂的橘子，再逐一腐烂上下左右的橘子，将被腐烂的橘子入队
- 直到队列为空，说明已经没有腐烂的橘子了
- 若新鲜橘子的仍不为0，则说明有的橘子无法被腐烂，此时返回-1；否则，返回腐烂的时间
### 注意
- `bool rot = false;`的作用为：当没有可腐烂的橘子时，分钟数不+1，因为可以直接进行下一层的腐烂或者结束。例如：当队列中只剩下网格右下角腐烂的橘子时，如图：

| | | |
|-|-|-|
|2|2|2|
|2|2|0|
|0|2|2|

当它的上下左右已经没有橘子可以腐烂，那么此时时间不+1。并且此时队列中已经没有其他腐烂的橘子，所以整个腐烂过程结束。

```cpp
class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        //判断特殊情况
        if (grid.size() == 0) return -1;
        //创建队列，存储已经腐烂的橘子
        queue<pair<int,int>> q;
        //新鲜橘子的数量
        int fresh = 0;
        //将腐烂的橘子入队，并统计新鲜的橘子
        for (int i = 0 ; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1) fresh++;
                //将坐标位置入队
                if (grid[i][j] == 2) q.push({i,j});
            }
        }
        //从队中一次取出腐烂的橘子，并按照上下左右的顺序腐烂。
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        //所用腐烂的时间
        int min = 0;
        //当队列不为空，说明仍有腐烂的橘子
        while (!q.empty())
        {
            //此轮（层）有多少腐烂的橘子要遍历
            int n = q.size();
            //判断是否有橘子被腐烂
            bool rot = false;
            for (int k = 0; k < n; k++)
            {
                //取出队首元素
                pair<int,int> r = q.front();
                //弹出队首元素
                q.pop();
                //将该腐烂橘子的四周注意腐烂
                for (pair<int,int> x : dir)
                {
                    int i = r.first + x.first;
                    int j = r.second + x.second;
                    //若越界，没有橘子，橘子已被腐烂，返回false
                    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == 2)
                    {
                        continue;
                    }
                    //将被腐烂的橘子入队
                    q.push({i,j});
                    //将标志置为2，并且新鲜橘子的数量减1
                    grid[i][j] = 2;
                    fresh--;
                    //判断有无腐烂的标志为true
                    rot = true;
                }
            }
            //若此轮有橘子被腐烂，
            if (rot) min++;
        }
        return fresh > 0 ? -1 : min;
    }
};
```