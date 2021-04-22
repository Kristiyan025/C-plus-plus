#include<bits/stdc++.h>
using namespace std;

const int maxLen = 10000;

string s;
int len;
bool palindromes[maxLen][maxLen] = {0};
int dp[maxLen] = {0};

void initialize()
{
    cin >>s;
    len = s.size();
    for (int i = 0; i < len; i++)
    {
        palindromes[0][i] = palindromes[1][i] = true;
    }

    //mini dp
    for (int i = 2; i <= len; i++)
    {
        for (int j = 0; j < len - i + 1; j++)
        {
            palindromes[i][j] = (s[j] == s[j + i - 1]) && palindromes[i - 2][j + 1];
        }
    }

    /*for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cout <<palindromes[i][j] <<" ";
        }
        cout <<endl;
    }*/

    for(int i = 0; i < len; i++)
    {
        dp[i] = INT_MAX;
    }
}

int dyn_pro()
{
    dp[0] = 0;
    for (int k = 1; k < len; k++)
    {
        if(palindromes[k + 1][0])
        {
            dp[k] = 0;
            continue;
        }

        for (int i = 1; i <= k; i++)
        {
            //cout <<"k = " <<k <<" i = " <<i <<endl;
            //cout <<"is pal " <<palindromes[k - i + 1][i] <<" prev = " <<dp[i - 1] <<endl;
            dp[k] = min(dp[k], (palindromes[k - i + 1][i] ? dp[i - 1] : INT_MAX));
            //cout <<"new dp = " <<dp[k] <<endl;
        }

        dp[k]++;
        //cout <<"final dp[k] = " <<dp[k] <<endl;
    }

    /*for(int i = 0; i < len; i++)
    {
        cout <<dp[i] <<" ";
    }
    cout <<endl;*/

    return dp[len - 1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    initialize();
    cout <<dyn_pro() <<endl;
}
