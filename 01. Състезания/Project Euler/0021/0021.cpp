#include<bits/stdc++.h>
using namespace std;

const int maxi = 10000;
int res;

int dp[maxi] = { 0, };
bitset<maxi> isAmicable = 0;

void binary_lifting(int a, int b)
{
    res = 1;
    while(b > 0)
    {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
}

int sumOfProperDivisors(int num)
{
    int number = num;
    unordered_map<int, int> factorization;
    for(int i = 2; num > 1; i++)
    {
        while(num % i == 0)
        {
            factorization[i]++;
            num /= i;
        }
    }

    int result = 1;
    for(auto p : factorization)
    {
        binary_lifting(p.first, p.second + 1);
        result *= (res - 1) / (p.first - 1);
    }

    result -= number;
    if(number < maxi) dp[number] = result;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    for(int i = 2; i < maxi; i++)
    {
        if(dp[i] == 0) sumOfProperDivisors(i);
        if(dp[i] < maxi) { if(dp[dp[i]] == i && i != dp[i]) isAmicable[i] = isAmicable[dp[i]] = 1; }
        else isAmicable[i] = sumOfProperDivisors(dp[i]) == i;
    }

    long sum = 0;
    for(int i = 3; i < maxi; i++)
    {
        sum += isAmicable[i] ? i : 0;
    }

    cout <<sum <<endl;
}
