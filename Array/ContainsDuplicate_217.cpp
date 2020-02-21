class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        set<int> s(nums.begin(), nums.end());
        return nums.size() > s.size();
    }
};

static int speedup=[]()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();