```cpp
//双指针遍历
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[0][i] != strs[j][i]) return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
```

