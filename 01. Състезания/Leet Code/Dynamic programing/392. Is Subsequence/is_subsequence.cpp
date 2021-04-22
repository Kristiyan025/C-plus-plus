class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        if(s == "" || s == t) return true;

        bool dp[100][10000];
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < t.size(); j++)
            {
                dp[i][j] = false;
                if(s[i] == t[j])
                {
                    if(i == 0) dp[i][j] = true;
                    else
                        for(int k = 0; k < j; k++)
                        {
                            dp[i][j] = dp[i][j] || dp[i - 1][k];
                        }
                }
            }
        }

        bool res = false;
        for(int i = s.size() - 1; i < t.size(); i++)
        {
            res = res || dp[s.size() - 1][i];
        }

        return res;
    }
};
