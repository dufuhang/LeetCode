### 思路
连续整数序列求和，可以想到使用**滑动窗口**
### 注意点
- 滑动窗口为左闭右开的一个窗口，左边界和右边界都只能向右移动，不能像左
- 当左边界到达目标值的一半时，寻找即可终止：因为此时左边界右边的值都是大于目标值的一半的，所以窗口中的和是始终大于目标值的，所以可以终止。
- 当和与目标值相等时，需要寻找新的左边界，所以先将和减去此时的左边界，再将
i++
```cpp
class Solution
 {
public:
    vector<vector<int>> findContinuousSequence(int target) 
    {
        //滑动窗口的左边界值和右边界值。滑动窗口左闭右开
        int i = 1;
        int j = 1;
        //和
        int sum = 0;
        //存储结果
        vector<vector<int>> ans;
        //当左边界到达target的中间值时则退出循环（因为右边界一定是大于target的中间值的，所以和始终是大于target的。
        while (i <= target / 2)
        {
            //和小于target，右边界向右移动
            if (sum < target) 
            {
                //先累加当前j的值，再将j++
                sum += j;
                j++;
            }
            //和大于target，左边界向右移动
            else if (sum > target)
            {
                sum -= i;
                i++;
            }
            else 
            {
                vector<int> temp;
                for (int k = i; k < j; k++)
                {
                    temp.push_back(k);
                }
                ans.push_back(temp);
                sum -= i;
                i++;
            }
        }
        return ans;
    }
};
```