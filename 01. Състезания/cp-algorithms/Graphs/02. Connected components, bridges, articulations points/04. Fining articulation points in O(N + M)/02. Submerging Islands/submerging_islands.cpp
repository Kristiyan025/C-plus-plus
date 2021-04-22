#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e4 + 1;
int n, m;
vector<vector<short> > g;
bitset<maxN> visited;
vector<short> tin, low;
short timer;
unordered_set<short> cut_vertices;

void dfs(short v, short p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    short children = 0;
    for(short to : g[v])
    {
        if(to == p) continue;
        if(visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);

            if(low[to] >= tin[v] && p != -1)
            {
                cut_vertices.insert(v);
            }
            children++;
        }
    }
    if(p == -1 && children > 1)
    {
        cut_vertices.insert(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >>n >>m;
    short a, b;
    while(!(n == 0 && m == 0))
    {
        g.resize(n + 1);
        for(int i = 1; i <= n; i++)
        {
            g[i].clear();
        }

        tin.resize(n + 1);
        low.resize(n + 1);
        visited = 0;
        timer = 0;
        cut_vertices.clear();

        for(short i = 0; i < m; i++)
        {
            cin >>a >>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        for(short i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }

        cout <<cut_vertices.size() <<endl;
        cin >>n >>m;
    }
}
