- 迭代法
```cpp
class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> vec = {{}};
        for (int num : nums)
        {
            int n = vec.size();
            for ( int i = 0; i < n; i++)
            {
                vector<int> temp;
                temp = vec[i];
                temp.push_back(num);
                vec.push_back(temp);
            }
        }
        return vec;
    }
};
```
- DFS

待补充
