### 思路
- 暴力法直接遍历
- [数学法](https://leetcode-cn.com/problems/distribute-candies-to-people/solution/xiang-xi-jie-shi-shu-xue-fang-fa-zen-yao-zuo-gao-z/)
```cpp
class Solution 
{
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        //初始化数组
        vector<int> res(num_people,0);
        //此次应分的糖果数
        int gift = 0;
        while ( candies > 0)
        {
            res[gift % num_people] += min(candies,gift + 1);
            candies -= min(candies,gift + 1);
            gift += 1;
        }
        return res;
    }
};
```