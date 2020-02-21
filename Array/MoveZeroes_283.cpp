class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int before = nums.size();
        nums.erase(remove(nums.begin(),nums.end(),0),nums.end());
        int after = nums.size();
        for (int i = 0; i < before - after; i++)
        {
            nums.push_back(0);
        }
    }
};