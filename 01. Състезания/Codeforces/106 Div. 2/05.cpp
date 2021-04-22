#include<bits/stdc++.h>
using namespace std;

const int maxi = 1e7;
bitset<maxi> sieve = 0;

void er()
{
    for(int i = 2; i <= maxi; i++)
    {
        if(!sieve[i])
        {
            cout <<i <<", ";
            for(int j = i * i; j <= maxi; j += i)
            {
                sieve[j] = 1;
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);

    cout <<"{ ";
    er();
    cout <<"}\n";

}
