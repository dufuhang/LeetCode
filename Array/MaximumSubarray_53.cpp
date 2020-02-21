class Solution 
{
public:
    //使用动态规划(DP) Dynamic Programing
    int maxSubArray(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (dp[i-1] + nums[i] > nums[i])
            {
                dp[i] = dp[i-1] + nums[i];
            }
            else
            {
                dp[i] = nums[i];
            }
        }
        auto it = max_element(dp.begin(),dp.end());
        return *it;
    }
};