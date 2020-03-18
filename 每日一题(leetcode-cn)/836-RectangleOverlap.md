### 思路
因为矩形的场合宽与另一个矩形始终是平行的，所以矩形是否重叠，等价于：长和宽分别在x轴和y轴上的投影是否重叠

```cpp
class Solution 
{
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        return !(rec2[2] <= rec1[0] || rec2[0] >= rec1[2] || rec2[3] <= rec1[1] || rec2[1] >= rec1[3]);
    }
};
```