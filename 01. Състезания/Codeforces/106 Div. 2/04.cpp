#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const int maxi = 1e4;
bitset<maxi> sieve = 0;
vector<int> primes;

void er()
{
    for(int i = 2; i <= maxi; i++)
    {
        if(!sieve[i])
        {
            //cout <<i <<", ";
            primes.emplace_back(i);
            for(int j = i * i; j <= maxi; j += i)
            {
                sieve[j] = 1;
            }
        }
    }
}


int numberOFPrimes(int n) {
    if(n == 1) return 0;
    int counter = 0;
    int bound = (n >> 1) + 1;
    for(int i = 0; primes[i] <= bound; i++)
    {
        if(n % primes[i] == 0) counter++;
    }
    return counter;
}

ull binpow(int a, int b) {
    ull res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    er();
    int t;
    cin >>t;
    int c, d, x, q, p, div;
    ull res;
    while(t--)
    {
        cin >>c >>d >>x;
        //c * p * q - d * q == x

        if(x % __gcd(c, d) != 0)
        {
            cout <<0 <<endl;
            continue;
        }

        res = 0;
        vector<int> ddd;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                ddd.emplace_back(i);
                if (x / i != i) ddd.emplace_back(x / i);

            }
        }

        for(int q : ddd)
        {
            if(x % q == 0 && (x / q + d) % c == 0)
            {
                p = (x / q + d) / c;
                div = binpow(2, numberOFPrimes(p));
                //cout <<"q " <<q <<" p " <<p <<" # " <<div <<endl;
                res +=  div;
            }
        }

        cout <<res <<endl;
    }

}
