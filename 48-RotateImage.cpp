//先上下翻转
//再按斜对角线对称翻转
//即可完成顺时针旋转90度

class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        //行数
        int n = matrix.size();
        //交换行
        for (int i = 0; i < n / 2; i++)
        {
            swap(matrix[i], matrix[n-i-1]);
        }
        //斜对角线对称交换
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};