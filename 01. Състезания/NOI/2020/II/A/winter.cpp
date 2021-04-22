#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 1;
int n, m;
vector<vector<int> > g;
vector<vector<bool> > bridges;
bitset<maxN> visited = 0;
vector<int> tin, low;
int timer = 0;

void dfs(int v, int p = -1)
{
    visited[v] = 1;
    tin[v] = low[v] = timer++;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if(to == p) continue;
        if(visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v])
            {
                //(v, to) - BRIDGE
                bridges[v][i] = 1;
            }
        }
    }
}

int bfs(int from)
{
    visited[from] = 1;
    queue<int> q;
    q.push(from);
    int nodes = 0;
    int i;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        nodes++;
        for(i = 0; i < g[v].size(); i++)
        {
            int to = g[v][i];
            if(!visited[to] && !bridges[v][i])
            {
                visited[to] = 1;
                q.push(to);
            }
        }
    }

    return nodes;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout <<sizeof(int) <<endl;
    cin >>n >>m;
    g.resize(n + 1);
    bridges.resize(n + 1);
    tin.resize(n + 1);
    low.resize(n + 1);

    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >>a >>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        bridges[a].emplace_back(0);
        bridges[b].emplace_back(0);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    unsigned long long result = 0;
    visited = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            int nodes = bfs(i);
            //cout <<nodes <<endl;
            result += 1LL * nodes * (nodes - 1) / 2;
        }
    }

    cout <<result <<endl;
}
