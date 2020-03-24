### 思路
1、动态规划

2、设`dp[amount]`为组成amount的最少硬币数，那么就可以分解为`min(dp[amount-coins])+1`.转移方程为:
$$dp[i]=min_{j=0...n-1}(dp[i-c_j]) + 1$$

如下表格:
假设硬币为{1,2,5},amount = 11
|dp[i]|硬币最少数量|
|-|-|
|dp[0]|0|
|dp[1]|1 //$dp[1]=min(dp[1-1],dp[1-2],dp[1-5])+1 = 1$|
|dp[2]|1 //$dp[2]=min(dp[2-1],dp[2-2],dp[2-5])+1 = 1$|
|dp[3]|2 //$dp[3]=min(dp[3-1],dp[3-2],dp[3-5])+1 = 2$|
|dp[4]|2 //$dp[4]=min(dp[4-1],dp[4-2],dp[4-5])+1 = 4$|
|...|...|
|dp[11]|3 //$dp[11]=min(dp[11-1],dp[11-2],dp[11-5])+1 = 3$|

```cpp
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        //初始化dp table。
        //全部初始化为amount+1,是因为每一个金额最多都由amount个一元硬币组成，再+1相当于初始化为无限大
        vector<int> dp(amount + 1,amount + 1);
        //将dp[0]置为0
        dp[0] = 0;
        //从1元开始
        for (int i = 1; i < dp.size(); i++)
        {
            //遍历所有硬币
            for (int j = 0; j < coins.size(); j++)
            {
                //如果硬币面额大于所求金额，则跳过这个硬币
                if (coins[j] > i) continue;
                //如果有更小值，就赋给dp[i]
                //注意：+1为加上本次减去的coins[j]这枚硬币
                dp[i] = min(dp[i],dp[i-coins[j]] + 1);
            }
        }
        //若dp[amount] > amount，则说明没有符合要求的结果，返回-1
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};
```