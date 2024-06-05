```cpp
class Solution 
{
public:
    int arrayPairSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        int sum = 0;
        while (i < nums.size() && j < nums.size())
        {
            sum += min(nums[i], nums[j]);
            i += 2;
            j += 2;
        }
        return sum;
    }
};
```