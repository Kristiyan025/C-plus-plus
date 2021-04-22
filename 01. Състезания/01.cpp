#include<bits/stdc++.h>
using namespace std;

const int maxN = 601;
int n, m;
vector<int> g[maxN];
bitset<maxN> visited = 0;
int tin[maxN], low[maxN];
int timer = 1;
int counter = 0;

void dfs(int v, int p = -1)
{
    visited[v] = 1;
    tin[v] = low[v] = timer++;
    for(int to : g[v])
    {
        if(to == p) continue;
        if(visited[to])
        {
            low[v]  = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v])
            {
                counter++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >>n >>m;
    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >>a >>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    cout <<counter <<endl;
}
