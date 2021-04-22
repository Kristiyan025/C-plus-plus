#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<int> p, d;

void init()
{
    p.resize(n + 1);
    d.resize(n + 1);
    for(int i = 0; i <= n; i++)
    {
        p[i] = i;
        d[i] = 0;
    }
}

int get(int v)
{
    if(p[v] == v) return v;
    return p[v] = get(p[v]);
}

void unite(int u, int v)
{
    int up = get(u);
    int vp = get(v);
    if(d[up] < d[vp])
    {
        swap(up, vp);
    }
    d[up] += d[up] == d[vp];
    p[vp] = up;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>n >>m;
    init();
    string s;
    int u, v;
    for(int i = 0; i < m; i++)
    {
        cin >>s >>u >>v;
        if(s == "get")
        {
            cout <<(get(u) == get(v) ? "YES\n" : "NO\n");
        }
        else
        {
            unite(u, v);
        }
    }
}
