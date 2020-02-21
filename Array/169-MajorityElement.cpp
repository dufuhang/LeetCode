class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int num = nums.size() / 2;
        map<int,int> map;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            map[*it] += 1;
            if (map[*it] > num)
            {
                return (*it);
            }
        }
        return -1;
    }
};