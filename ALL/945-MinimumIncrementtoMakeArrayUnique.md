### 排序
```cpp
//时间复杂度O(nlogn)
class Solution 
{
public:
    int minIncrementForUnique(vector<int>& A)
    {
        if (A.size() == 0) return 0;
        //将数组排序
        sort(A.begin(), A.end());
        //记录move操作的次数
        int count = 0;
        //遍历数组，使其后一个比前一个大1即可，若已大1，不变
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i+1] <= A[i])
            {
                count = count + A[i] + 1 - A[i+1];
                A[i+1] = A[i] + 1; 
            }
        }
        return count;
    }
};
```
### 哈希法 
[参考题解](https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/ji-shu-onxian-xing-tan-ce-fa-onpai-xu-onlogn-yi-ya/)
```cpp
//使用哈希的思想
//时间复杂度O(n)
class Solution 
{
public:
    int minIncrementForUnique(vector<int>& A) 
    {
        //判断特殊情况
        if (A.size() == 0) return 0;
        //构造散列表
        //最坏情况为40000个40000
        vector<int> hash(80000, -1);
        //move计数
        int move = 0;
        for (int num : A)
        {
            int b = findPos(num, hash);
            //递增次数为num的增量
            move += b - num;
        }
        return move;
    }
    int findPos(int value, vector<int>& hash)
    {
        //直接寻址法确定位置
        int b = hash[value];
        if (b == -1)
        {
            hash[value] = value;
            return value;
        }
        //当前位置已经有值，向后寻址.线性探测法解决冲突
        b = findPos(hash[value]+1, hash);
        //路径压缩，将寻到的地址赋给前面被寻找的地方，下次直接从最后一个被寻址的地方往后搜寻新的空位
        hash[value] = b;
        return b;
    }
};
```