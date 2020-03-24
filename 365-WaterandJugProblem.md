### 思路
[我的题解](https://leetcode-cn.com/problems/water-and-jug-problem/solution/tu-jie-shui-hu-wen-ti-by-miraclept/)
```cpp
//裴蜀定理
class Solution 
{
public:
    bool canMeasureWater(int x, int y, int z) 
    {
        if (x + y < z) return false;
        if (x == 0 || y == 0)
        {
            if (z == 0) return true;
            if (x + y == z) return true;
            return false;
        }
        return z % gcd(x, y) == 0;
    }
};
```