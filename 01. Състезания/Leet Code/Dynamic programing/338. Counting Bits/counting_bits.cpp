class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        int counter = 0;
        int pow = 1;
        for(int i = 0; pow <= num; i++)
        {
            for(int j = pow; j < min(pow << 1, num + 1); j++)
            {
                dp[j] = dp[j - pow] + 1;
            }
            pow <<= 1;
        }

        return dp;
    }
};
