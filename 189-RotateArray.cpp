class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        //k为几，就进行几轮轮换：[1,2,3]，k=5  => [2,3,1]
        //不要误认为k为从数组末往前数几个元素进行轮换
        k %= nums.size();
        vector<int> vec(nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
        nums.insert(nums.begin(), vec.begin(), vec.end());
    }
};