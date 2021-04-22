#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 1;
int n, m;
int s, e;
vector<vector<int> > g, gT;
vector<bool> visited;
vector<int> order;
vector<int> f;
vector<int> fun;
vector<vector<int> > gCond;
vector<int> comp, bfsOrder;
unsigned long long maxFun = 0;

void dfs1(int v)
{
    visited[v] = true;
    for(int to : g[v])
    {
        if(!visited[to])
        {
            dfs1(to);
        }
    }

    order.push_back(v);
}

void dfs2(int v, int comp_id)
{
    visited[v] = true;
    fun[comp_id] += f[v];
    comp[v] = comp_id;
    for(int to : gT[v])
    {
        if(!visited[to])
        {
            dfs2(to, comp_id);
        }
    }
}

void bfs(int from, int to)
{
    visited.assign(n, false);
    visited[from] = true;
    queue<int> q;
    q.push(from);
    bfs[from] = -1;
    maxFun += fun[comp[from]];
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int next : g[v])
        {
            if(next == to) return;
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >>n >>m >>s >>e;
    s--;e--;
    g.assign(n, vector<int>());
    gT.assign(n, vector<int>());
    visited.assign(n, false);
    f.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >>f[i];
    }

    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >>a >>b;
        a--; b--;
        g[a].push_back(b);
        gT[b].push_back(a);
    }

    /*for(int i = 0; i < n; i++)
    {
        cout <<"g["<<i<<"]: ";
        for(int to : g[i])
        {
            cout <<to <<" ";
        }cout <<endl;
    }

    for(int i = 0; i < n; i++)
    {
        cout <<"gT["<<i<<"]: ";
        for(int to : gT[i])
        {
            cout <<to <<" ";
        }cout <<endl;
    }*/

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }


    visited.assign(n, false);
    comp.resize(n);
    bfsOrder.resize(n);
    for(int i = 0; i < n; i++)
    {
        int v = order[n - 1 - i];
        if(!visited[v])
        {
            gCond.push_back(vector<int>());
            fun.push_back(0);
            dfs2(v, fun.size() - 1);
        }
    }

    s = comp[s];
    e = comp[e];

    /*cout <<"fun: ";
    for(int to : fun)
    {
        cout <<to <<" ";
    }cout <<endl;

    cout <<"comp: ";
    for(int to : comp)
    {
        cout <<to <<" ";
    }cout <<endl;*/

    bfs(s, e);
    cout <<maxFun <<endl;
}
