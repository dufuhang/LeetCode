```cpp
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int count = nums.size();
        if (count == 0) return 0;
        int dp1 = 0;
        int dp0 = 0;
        int dp_prev_0 = 0;
        int dp_prev_1 = 0;
        for (int i = 0; i < count; i++)
        {
            if (i < 1)
            {
                dp1 = nums[i];
                dp0 = 0;
                dp_prev_0 = 0;
                dp_prev_1 = nums[i];
                continue;
            }
            dp0 = max(dp_prev_0, dp_prev_1);
            dp1 = dp_prev_0 + nums[i];
            dp_prev_0 = dp0;
            dp_prev_1 = dp1;
        }
        return max(dp0, dp1);
    }
};
```