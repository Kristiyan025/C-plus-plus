#include<bits/stdc++.h>
using namespace std;

const int n = 20;

int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}


int main()
{
    ios_base::sync_with_stdio(false);

    int res = lcm(1, 2);
    for(int i = 3; i <= n; i++)
    {
        res = lcm(res, i);
    }

    cout <<res <<endl;
}
