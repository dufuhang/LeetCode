### 思路
动态规划

```cpp
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        //特殊情况
        if (nums.size() <= 0) return 0;
        if (nums.size() == 1) return 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
```