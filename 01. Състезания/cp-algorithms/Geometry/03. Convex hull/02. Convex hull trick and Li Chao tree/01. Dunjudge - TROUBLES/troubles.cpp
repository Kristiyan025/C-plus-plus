#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

struct ktn
{
    int a, b;
    ktn() {}
    ktn(int _a, int _b) : a(_a), b(_b) {}
};

bool cmp1(const ktn& k1, const ktn& k2)
{
    return k1.a < k2.a || (k1.a == k2.a && k1.b < k2.b);
}

struct line
{
    int k;
    ull b;
    line(){}
    line(int _k, ull _b) : k(_k), b(_b) {}
    ull eval(int x) { return 1LL * k * x + b; }
    double inters(line& l) { return 1.0 * (l.b - b) / (k - l.k); }
};

int n;
vector<ktn> ktns;
vector<ull> dp;
deque<line> hull;

void read()
{
    cin >>n;
    vector<ktn> temp(n);
    for(int i = 0; i < n; i++)
    {
        cin >>temp[i].a >>temp[i].b;
    }

    sort(temp.begin(), temp.end(), &cmp1);
    //ktns.emplace_back(ktn(0, 0));
    for(int i = 0; i < n; i++)
    {
        while(i + 1 < n && temp[i].b <= temp[i + 1].b) i++;

        ktns.emplace_back(temp[i]);
    }

    n = ktns.size();
}

void build()
{
    dp.resize(n);
    dp[0] = ktns[0].a * ktns[0].b;
    hull.emplace_back(line(ktns[0].b, 0));
    ///             i-1       k          x          b
    ///     dp[i] = min { ktns[j].b * ktns[i].a + dp[j - 1] }
    ///             j=0
    line l;
    int x;
    for(int i = 1; i < n; i++)
    {
        x = ktns[i].a;
        l = line(ktns[i].b, dp[i - 1]);
        while(!hull.empty() && hull.back().eval(x) >= l.eval(x)) hull.pop_back();
        hull.emplace_back(l);

        while(hull.size() > 1 && hull[0].inters(hull[1]) <= x) hull.pop_front();
        dp[i] = hull[0].eval(x);
        //dp[i] = min(dp[i], ktns[i].a * ktns[i].b + dp[i - 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    read();
    build();

    //for(auto i : ktns) cout <<i.a <<" " <<i.b <<endl; cout <<endl;
    //for(int i : dp) cout <<i <<" "; cout <<endl;
    cout <<dp.back() <<endl;
}
