#include<bits/stdc++.h>
using namespace std;

const int maxi = 1000;

int f(int k)
{
    int res = 0;
    for(int i = k; i < maxi; i += k)
    {
        res += i;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int a = 3, b = 5;

    cout <<f(a) + f(b) - f(a * b) <<endl;

}
