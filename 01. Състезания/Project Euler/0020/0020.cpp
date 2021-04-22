#include<bits/stdc++.h>
using namespace std;

using vc = vector<short>;
using ull = unsigned long long;

const short fact = 100;
vc a = { (char)2 };
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

int main()
{
    ios_base::sync_with_stdio(false);

    char k;
    for(short i = 2; i <= fact; i++)
    {
        mult(res, a, s);
        res = s;

        k = 0;
        a[k]++;
        while(a[k] > 10)
        {
            a[k] -= 10;
            if(k + 1 == a.size()) a.emplace_back((char)0);
            a[k + 1]++;
            k++;
        }
    }

    int sum = 0;
    for(char c : res) sum += c;
    cout <<sum <<endl;
}
