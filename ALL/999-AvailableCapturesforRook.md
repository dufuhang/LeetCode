## 思路
1、看到题图的第一反应是DFS
2、读了题之后发现不需要遍历整个图，只要某一方向不满足要求，就换到另一个方向继续遍历，所以不需要DFS
```cpp
class Solution 
{
public:
    int numRookCaptures(vector<vector<char>>& board) 
    {
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        int count = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            while (tx >= 0 && tx < 8 && ty >= 0 && ty < 8 && board[tx][ty] != 'B')
            {
                if (board[tx][ty] == 'p')
                {
                    count++;
                    break;
                }
                else
                {
                    tx += dx[i];
                    ty += dy[i];
                }
            }
        }
        return count;
    }
};
```