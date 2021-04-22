#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    double res = 0.0000000000000;
    cout <<fixed;

    string s1, s2;
    cin >>s1 >>s2;
    int n = s1.size();
    int unknowns = 0, diff = 0;
    for(int i = 0; i < n; i++)
    {
        if(s2[i] == '?')
        {
            diff += (s1[i] == '+' ? 1 : -1);
            unknowns++;
        }
        else if(s1[i] == '+' && s2[i] == '-') diff += 2;
        else if(s1[i] == '-' && s2[i] == '+') diff -= 2;
    }

    if(diff < 0) diff = -diff;
    if(unknowns < diff || (unknowns - diff) % 2 != 0)
    {
        cout <<setprecision(12) <<res <<"\n";
        return 0;
    }

    int k = abs((unknowns - diff) / 2);
    long long ans = 1;
    for(int i = 1; i <= k; i++)
    {
        ans *= (unknowns - i + 1);
        ans /= i;
    }

    res = 1.0 * ans / (1 << unknowns);
    cout <<setprecision(12) <<res <<"\n";
}
