#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const int sz = 20;

ull C(int k, int n)
{
    if(k == 0 || k > n) return 0;
    if(k == 1 || k == n) return 1;
    if((n >> 1) < k) k = n - k;
    ull res = 1;
    for(int i = 1; i <= k; i++)
    {
        res *= n - i + 1;
        res /= i;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cout <<C(sz, sz << 1) <<endl;

}
