#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 1;
int n;
int m;
vector<int> g[maxN];
bitset<maxN> visited = 0;
int tin[maxN], low[maxN];
vector<bool> bridges[maxN];
vector<int> sizes;
int timer = 0;

void dfs(int v, int p = -1)
{
    visited[v] = 1;
    tin[v] = low[v] = ++timer;
    for(int to : g[v])
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
            if(low[to] > tin[v])
            {
                bridges[v][to] = bridges[to][v] = 1;
            }
        }
    }
}

int bfs(int start)
{
    int counts = 0;
    visited[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int v = q.front();
        counts++;
        q.pop();
        for(int to : g[v])
        {
            if(!visited[to] && !bridges[v][to])
            {
                visited[to] = true;
                q.push(to);
            }
        }
    }

    return counts;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >>n >>m;
    for(int i = 1; i <= n; i++)
    {
        bridges[i].assign(n + 1, 0);
    }
    int s, p;
    for(int i = 0; i < m; i++)
    {
        cin >>s >>p;
        g[s].push_back(p);
        g[p].push_back(s);
    }

    visited = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i]) dfs(i);
    }

    visited = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i]) sizes.push_back(bfs(i));
    }

    unsigned long long defeated = 0;

    for(int i = 1; i < sizes.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(i != j)
            {
                defeated += sizes[i] * sizes[j];
            }
        }
    }

    cout <<fixed <<setprecision(5) <<(long double)2 * defeated / n / (n - 1) <<endl;
}
