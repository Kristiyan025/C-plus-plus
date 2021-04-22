class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1, INT_MIN);
        dp[0] = 0;
        dp[1] = arr[0];
        for(int i = 2; i < dp.size(); i++)
        {
            int maxi = INT_MIN, id;
            for(int t = 1; t <= k; t++)
            {
                id = i - t + 1;
                if(id >= 1)
                {
                    if(arr[id - 1] > maxi)
                    {
                        maxi = arr[id - 1];
                    }
                    if(id > 0) dp[i] = max(dp[i], dp[id - 1] + t * maxi);
                }
            }
        }

        return dp.back();
    }
};
