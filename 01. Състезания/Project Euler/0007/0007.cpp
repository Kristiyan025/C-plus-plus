#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const ull number = 10001;
const ull check = 20 * number;
ull counter = 0;

bitset<check> sieve = 0;

ull eratosthenes()
{
    for(ull i = 2; i <= check; i++)
    {
        if(!sieve[i])
        {
            if(++counter == number)
            {
                return i;
            }

            for(ull j = i * i; j <= check; j += i)
            {
                sieve[j] = 1;
            }
        }
    }

    return -1;
}


int main()
{
    ios_base::sync_with_stdio(false);

    cout <<eratosthenes() <<endl;

}
