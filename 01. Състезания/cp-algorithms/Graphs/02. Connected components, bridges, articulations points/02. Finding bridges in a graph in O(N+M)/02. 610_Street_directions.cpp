#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

const short maxN = 1e3 + 1;
short n, m, a, b;
bitset<maxN> visited = 0;
bitset<maxN> printed[maxN];
short tin[maxN] = {0},
      low[maxN] = {0};
short timer;

void dfs(short v, short p, vector<short> g[]) //finding bridges
{
    visited[v] = true;
    tin[v] = low[v] = ++timer;
    for(short k = 0; k < g[v].size(); k++)
    {
        short to = g[v][k];
        if(to == p) continue;
        if(visited[to])
        {
            low[v] = min(low[v], tin[to]);
            if(!printed[v][to])
            {
                cout <<v <<' ' <<to <<endl;
                printed[v][to] = true;
                printed[to][v] = true;
            }
        }
        else
        {
            dfs(to, v, g);

            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v])
            {
              cout <<v <<' ' <<to <<endl;
              cout <<to <<' ' <<v <<endl;
            }
            if(low[to] <= tin[v] && !printed[v][to])//not a bridge
            {
                cout <<v <<' ' <<to <<endl;
                printed[v][to] = true;
                printed[to][v] = true;
            }
        }
    }
}



int main()
{
    short t = 0;
    while(true)
    {
        cin >>n >>m;
        if(n == 0 && m == 0) return 0;

        cout <<++t <<endl <<endl;
        vector<short> g[maxN];
        for(int i = 0; i < m; i++)
        {
            cin >>a >>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        for(short i = 1; i <= n; i++)
        {
            printed[i] = 0;
            tin[i] = 0;
            low[i] = 0;
        }

        visited = 0;

        timer = 0;
        dfs(1, -1, g);
        cout <<"#\n";
    }
}
