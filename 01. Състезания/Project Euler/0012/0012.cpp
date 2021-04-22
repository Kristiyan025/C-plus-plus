#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const int maxi = 500;
ull counter, i;

int countFactors(ull num)
{
    unordered_map<int, int> factors;
    for(i = 2; num > 1; i++)
    {
        while(num % i == 0)
        {
            factors[i]++;
            num /= i;
        }
    }

    counter = 1;
    for(auto fac : factors)
    {
        counter *= fac.second + 1;
    }

    return counter;
}


int main()
{
    ios_base::sync_with_stdio(false);

    ull t = 1;
    ull dt = 2;
    while(true)
    {
        t += dt++;
        if(countFactors(t) >= maxi)
        {
            cout <<t <<endl;
            return 0;
        }
    }
}
