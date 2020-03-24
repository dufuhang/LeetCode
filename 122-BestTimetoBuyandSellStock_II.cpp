class Solution 
{
public:
    //类型一中只能进行一次交易，所以需找到利润最大的那个。
    //但是本题可以多次交易，只要明天比当天的价格高，就可以买入卖出，将利润加入利润池中
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            if (prices[i-1] < prices[i])
            {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};