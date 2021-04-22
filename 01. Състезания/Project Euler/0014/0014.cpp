#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const int maxi = 1e6;
ull len;
ull dp[maxi] = { 0 };

ull findLength(ull num) //Of Collatz Sequence
{
    if(num == 1) return 0;
    if(num < maxi && dp[num] != 0) return dp[num];
    ull res;
    if((num & 1) == 0) res = 1ULL + findLength(num >> 1);
    else res = 1ULL + findLength(3ULL * num + 1);
    if(num < maxi) dp[num] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    ull maxLen = 0;
    ull maxNum;
    for(ull i = 2; i < maxi; i++)
    {
       len = findLength(i);
       if(len > maxLen)
       {
           maxLen = len;
           maxNum = i;
       }
    }

    cout <<maxNum <<endl;
}
