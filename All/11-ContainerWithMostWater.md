### 题目大意
> 数组中[a1,a2,a3,...,an]代表该元素在x坐标轴上的位置，每个元素值都代表在其
> 坐标点上的垂直线段的长度。找到两条垂直线段所围成的矩形面积最大。
### 分析
> 看题目容易想到使用双指针分别指向开头和结尾的线段，依次遍历，将面积存入Smax中，
> 直到两指针相遇，结束循环，输出最大值即所求。
### 问题❓
> 解法很容易想出来，但是如何证明在两指针向前向后遍历的过程中不会漏掉最优解呢？
> 如何证明此解法是正确的，最后能够得到最优解。
### 证明
> 以下证明来自[Krahets](https://leetcode-cn.com/u/jyd/)的[双指针法证明](https://leetcode-cn.com/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/)

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int i = 0;
        int j = height.size()-1;
        int Smax = 0;
        while (i < j)
        {
            Smax = height[i] < height[j] ? 
            max(Smax,(j - i) * height[i++]) : 
            max(Smax,(j - i) * height[j--]);
        }
        return Smax;
    }
};
```