#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<int> p, s, mini, maxi;

void init()
{
    p.resize(n + 1);
    s.resize(n + 1);
    mini.resize(n + 1);
    maxi.resize(n + 1);
    for(int i = 1; i <= n; i++)
    {
        p[i] = mini[i] = maxi[i] = i;
        s[i] = 1;
    }
}

int get(int v)
{
    if(p[v] == v) return v;
    p[v] = get(p[v]);
    mini[p[v]] = min(mini[v], mini[p[v]]);
    maxi[p[v]] = max(maxi[v], maxi[p[v]]);
    return p[v];
}

void unite(int u, int v)
{
    u = get(u);
    v = get(v);
    if(u == v) return;
    if(s[u] < s[v])
    {
        swap(u, v);
    }
    s[u] += s[v];
    mini[u] = min(mini[u], mini[v]);
    maxi[u] = max(maxi[u], maxi[v]);
    p[v] = u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>n >>m;
    init();
    string c;
    int u, v;
    for(int i = 0; i < m; i++)
    {
        cin >>c >>u;
        if(c == "get")
        {
            u = get(u);

            cout <<mini[u] <<" " <<maxi[u] <<" " <<s[u] <<"\n";
        }
        else
        {
            cin >>v;
            unite(u, v);
        }
    }
}
