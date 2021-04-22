#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull maxN = 1e18 + 1;
ofstream f;

short zeros;
ull i, ans;

void counter(ull number)
{
    zeros = 0;
    while(number > 0)
    {
        zeros += ~number & 1;
        number >>= 1;
    }
}

void calc()
{
    ans = 0;
    f <<"{ ";
    for(i = 1; i < maxN; i++)
    {
        counter(i);
        ans += zeros;
        f <<ans <<", ";
    }
    f <<"}" <<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    f.open(".\\ans.txt");
    calc();
    f.close();
}
