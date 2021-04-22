#include<iostream>
#include<vector>
#include<bitset>
#include<queue>
using namespace std;

const short maxN = 1e4 + 1;
short n;
int m;
vector<short> g[maxN];
vector<char> counts[maxN];
bitset<maxN> visited = 0;
short tin[maxN], low[maxN];
vector<short> bridges[maxN];
short timer = 0;
short maxi = 0;
short from, ending;

void dfs(short v, short p = -1)
{
    visited[v] = 1;
    tin[v] = low[v] = ++timer;
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
            if(low[to] > tin[v] && counts[v][to] == 1)
            {
                bridges[v].push_back(to);
                bridges[to].push_back(v);
            }
        }
    }
}

void bfs(short start)
{
    visited = 0;
    visited[start] = 1;
    queue<short> q;
    queue<short> longest;
    q.push(start);
    while(!q.empty())
    {
        short v = q.front();
        short v_l = longest.front();
        q.pop();
        longest.pop();
        for(short to : bridges[v])
        {
            if(!visited[to])
            {
                visited[to] = true;
                q.push(to);
                longest.push(v_l + 1);
                if(maxi < longest.front())
                {
                    maxi = longest.front();
                    from = start;
                    ending = to;
                }
            }
        }
    }
}

int main()
{
    cin >>n >>m;
    short s, p;
    for(short i = 1; i <= n; i++)
    {
        counts[i].assign(n + 1, 0);
    }
    for(short i = 0; i < m; i++)
    {
        cin >>s >>p;
        g[s].push_back(p);
        g[p].push_back(s);
            counts[s][p]++;
            counts[p][s]++;

    }

    for(short i = 1; i <= n; i++)
    {
        if(!visited[i]) dfs(i);
    }

    for(short i = 1; i <= n; i++)
    {
        if(bridges[i].size() != 0) bfs(i);
    }

    cout <<from <<" " <<ending <<endl;
}
