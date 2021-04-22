class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int> > ans(m, vector<int>(n, 0)),
                           tool(m, vector<int>(n, 0));
        //setting tool
        int mK = min(K, m - 1), nK = min(K, n - 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= mK; j++)
            {
                tool[0][i] += mat[j][i];
            }
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                tool[i][j] = tool[i - 1][j] + (i + K < m ? mat[i + K][j] : 0)
                                            - (i - K - 1 >= 0 ? mat[i - K - 1][j] : 0);
            }
        }
        //setting answer
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j <= nK; j++)
            {
                ans[i][0] += tool[i][j];
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                ans[i][j] = ans[i][j - 1] + (j + K < n  ? tool[i][j + K] : 0)
                                          - (j - K - 1 >= 0 ? tool[i][j - K - 1] : 0);
            }
        }
        return ans;
    }
};
