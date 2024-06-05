## 思路
X一定为牌总数的约数，且X以一定为每张牌出现的次数的约数
1、统计每个数字出现的次数
2、然后计算所有次数的最大公约数
```cpp
class Solution 
{
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        vector<int> count(10000,0);
        for (int num : deck)
        {
            count[num] += 1;
        }
        int g = 0;
        for (int i = 0; i < 10000; i++)
        {
            if (count[i] > 0)
            {
                g = gcd(count[i], g);
            }
        }
        return g >= 2;
    }
};
```