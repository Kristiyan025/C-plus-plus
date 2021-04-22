#include<bits/stdc++.h>
using namespace std;

#define cref(x) const x&

using ull = unsigned long long;

struct line
{
    int k;
    ull b;
    line(){}
    line(int _k, ull _b) : k(_k), b(_b) {}
    ull eval(int x) { return 1LL * k * x + b; }
    double inters(line& l) { return 1.0 * (l.b - b) / (k - l.k); }
};

bool operator <(cref(line) l1, cref(line) l2)
{
    return l1.k < l2.k || (l1.k == l2.k && l1.b < l2.b);
}

int n, k;
vector<int> a;
vector<ull> dp, prv;

set<line> hull;
/*
void add(cref(line) l)
{
    hull.insert(l);
    set<line>::iterator b = lower_bound(hull.begin(), hull.end(), l);
    if(b != hull.begin())
    {
        b--;
        while((b - hull.begin()) > 1 && b->inters(--b) >= l.inters(b)) hull.erase(++b);
    }

    if(hull.end() - b > 1)
    {
        while(hull.end() - a > 2 && a->inters(*(a + 1)) <= l.inters(*(a + 1))) hull.erase(a);
    }
}

void query(int x)
{

}

void build(int start = 1)
{
    hull.clear();
    dp[start] = 0;

    ///              i        k         x                b
    ///     dp[i] = min { -2 * a[j] * a[i] + a[j] * a[j] + prev[j - 1] } + a[i] * a[i];
    ///
    line l;
    for(int i = 1; i <= n; i++)
    {
        l = line(-2 * a[i], a[i] * a[i] + prv[i - 1]);

        //while(hull.size() > 1 && hull.back().inters(hull[hull.size() - 2]) )

        dp[i] = a[i] * a[i]
    }
}

//*/
int main()
{
    ios_base::sync_with_stdio(false);
    int gg = 1;
    cout <<(--gg)++ <<endl;
    cout <<gg <<endl;
    /*
    set<int> ff = {3,4,6,3};
    for(int j : ff) cout <<j <<" ";cout <<endl;
    set<int>::iterator it = lower_bound(ff.begin(), ff.end(), 5);
    cout <<*it <<endl;
    it--;
    cout <<*it <<endl;
    set<int>::reverse_iterator rv(it);
    cout <<*rv <<endl;
    rv--;
    cout <<*rv <<endl;
    //*/
    cin >>n >>k;
    if(n == k)
    {
        cout <<0 <<endl;
        return 0;
    }

    a.resize(n + 1);
    dp.resize(n + 1);
    prv.resize(n + 1);
    a[0] = dp[0] = prv[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >>a[i];
        prv[i] = prv[i - 1] + a[i];
    }
}
