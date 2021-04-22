#include<bits/stdc++.h>
using namespace std;

const int maxi = 4e6;

int fib()
{
    unsigned long long res = 0;
    int f1 = 1, f2 = 1, fn = 0;
    while(fn <= maxi)
    {
        fn = f1 + f2;
        res += ((fn & 1) == 0 ? fn : 0);
        f1 = f2;
        f2 = fn;
    }

    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);

    cout <<fib() <<endl;

}
