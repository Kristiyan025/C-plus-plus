class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.empty()) return 0;
        int res = 0;
        int mini = INT_MAX;
        for(int i = 0; i < prices.size(); i++)
        {
            int currRes = prices[i] - mini;
            if(currRes > res)
            {
                res = currRes;
            }

            if(prices[i] < mini)
            {
                mini = prices[i];
            }
        }

        return res;
    }
};
