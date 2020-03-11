### 思路
根据题意，连续三个数组和相同。
1、对整个数组求和，除3求余。余数为0，能被3整除。余数不为0.不能被3整除，返回false
2、遍历寻找这样的子数组
3、找到3个满足条件的则返回true
4、否则返回false

### 注意：
最后的判断条件为`count == 3`
不能为2，因为最后一个可能是空数组
```cpp
class Solution 
{
public:
    bool canThreePartsEqualSum(vector<int>& A)
    {
        //求和
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) return false;
        //统计满足条件的组数
        int count = 0;
        //子数组和
        int subSum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            subSum += A[i];
            if (subSum == sum / 3) 
            {
                //找到某个子数组的和满足条件，就将count++，将子数组和重新置为0
                count++;
                subSum = 0;
            }
            //若已经找到3个满足条件的子数组，返回true
            if (count == 3)
            {
                return true;
            }
        }
        //否则，返回false
        return false;
    }
};
```