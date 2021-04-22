#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const ull number = 600851475143;

unordered_map<ull, ull> dp;

ull maxiFactor(ull num)
{
    if(dp[num] != 0) return dp[num];
    for(ull i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
        {
            return dp[num] = max(maxiFactor(i), maxiFactor(num / i));
        }
    }

    return dp[num] = num;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cout <<maxiFactor(number) <<endl;

}
