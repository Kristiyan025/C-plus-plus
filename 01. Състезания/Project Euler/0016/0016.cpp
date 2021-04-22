#include<bits/stdc++.h>
using namespace std;

using vc = vector<short>;
using ull = unsigned long long;

vc a = { (char)2 };
int power = 1000;
vc s, res = { (char)1 };
void mult(const vc& s1, const vc& s2, vc& s)
{
    s.assign(s1.size() + s2.size(), 0);
    for(int i = 0; i < s.size() - 1; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j < s1.size() && i - j < s2.size()) s[i] += s1[j] * s2[i - j];
        }

        s[i + 1] += s[i] / 10;
        s[i] %= 10;
    }

    while(s.back() == 0) s.pop_back();
}

void binary_lifting()
{
    while(power > 0)
    {
        if(power & 1)
        {
            mult(res, a, s);
            res = s;
        }

        mult(a, a, s);
        a = s;
        power >>= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    binary_lifting();
    ull sum = 0;
    for(auto c : res)
    {
        sum += c;
    }
    cout <<sum <<endl;
}
