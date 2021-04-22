#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const int maxi = 2e6;
bitset<maxi> sieve = 0;

ull eratosthen()
{
    ull sum = 0;
    int i, j;
    for(i = 2; i * i < maxi; i++)
    {
        if(!sieve[i])
        {
            sum += i;
            for(j = i * i; j < maxi; j += i)
            {
                sieve[j] = 1;
            }
        }
    }

    for(; i < maxi; i++)
        if(!sieve[i])
            sum += i;

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cout <<eratosthen() <<endl;

}
