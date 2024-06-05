```cpp
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() == 0 || prices.size() == 1) return 0;
        int buy = prices[0];
        int profit = 0;
        for (int price : prices)
        {
            buy = min(price,buy);
            profit = max(profit,price-buy);
        }
        return profit;
    }
};
```