```cpp
class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> vec;
        //numRows为0,直接返回
        if (numRows == 0) return vec;
        vec.resize(numRows);
        //第一行填充1
        vec[0].push_back(1);
        if (numRows == 1) return vec;
        for (int i = 1; i < numRows; i++)
        {
            //先对这一行进行resize
            vec[i].resize(i+1);
            //首尾填充0
            vec[i][0] = 1;
            vec[i][i] = 1;
            //对其他位置进行填充
            for (int j = 1; j <= i-1; j++)
            {
                vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
            }
        }
        return vec;
    }
};
```