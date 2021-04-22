#include <bits/stdc++.h>
using namespace std;


int n;
vector< vector<int> > g;
vector<int> visited;
vector<int> tin, low;
int timer;

vector< pair<int, int> > ans;

void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
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
                //(v, to) is bridge
                ans.push_back(make_pair(v, to));
            }
        }
    }
}

void find_bridges()
{
    if(n == 0)
    {
        cout <<"0 critical links" <<endl <<endl;
        return;
    }

    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    timer = 0;
    ans.assign(0, make_pair(-1, -1));
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    sort(ans.begin(), ans.end());

    cout <<ans.size() <<" critical links" <<endl;
    for(auto p : ans)
    {
        cout <<p.first <<" - " <<p.second <<endl;
    }

    cout <<endl;
}

int main() {
    while (scanf("%d",&n) == 1){
        for(int i = 0; i < n; i++)
        {
            vector<int> v;
            g.push_back(v);
        }

        int server, count;
        char c;
        for(int i = 0; i < n; i++)
        {
            cin >>server >>c >>count >>c;
            g[server].assign(count, -1);
            for(int j = 0; j < count; j++)
            {
                cin >>g[server][j];
            }
        }

        find_bridges();
    }
}
