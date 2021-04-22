class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<unsigned int> > dp(n);
        for(int i = 0; i < n; i++)
        {
            dp[i] = vector<unsigned int>(n - i, INT_MAX);
            dp[i][0] = 0;
        }

        for(int j = 1; j < n; j++)
        {
            for(int i = 0; i < n - j; i++)
            {
                int stop = i + j;
                int max1 = arr[i];
                for(int k = i; k < stop; k++)
                {
                    if(arr[k] > max1) max1 = arr[k];
                    int max2 = arr[k + 1];
                    for(int p = k + 2; p <= stop; p++)
                    {
                        if(arr[p] > max2) max2 = arr[p];
                    }
                    dp[i][j] = min(dp[i][j], max1 * max2 + dp[i][k - i]
                              + dp[k + 1][stop - (k + 1)]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
