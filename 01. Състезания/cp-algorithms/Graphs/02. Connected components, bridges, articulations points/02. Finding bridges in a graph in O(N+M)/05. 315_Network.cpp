#include<bits/stdc++.h>
using namespace std;

const char maxN = 1e2;
short n;
vector<short> g[maxN];
bitset<maxN> visited;
char tin[maxN], low[maxN];
short timer;

void dfs(char v, char p = 0)
{
    tin[v] = low[v] = ++timer;
    for(char to : g[v])
    {
        if(v == p) continue;
        if(visited[to])
        {
            low[v] = min(low[v], tin[to]);
            low[p] = min(low[p], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            low[p] = min(low[p], low[to]);

            if(p && low[to] > tin[p])
            {
                cout <<"cut vertex " <<v <<endl;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    char c;
    short a, t, b;
    string line;
    while(cin >> n, n)
    {
        for(char i = 0; i <= n; i++)
        {
            g[i].clear();
        }
        cout <<"n\n";
        while(1)
        {
            //cout <<"a";
            cin.ignore();
            getline(cin, line);
            istringstream is(line);
            //cout <<line <<endl;
            is >>a;
            if(a == 0) break;
            is >>t;
            cout <<"t " <<t <<endl;
            for(char i = 0; i < t; i++)
            {
                is >>b;
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        cout <<"Graph:" <<endl;
        for(int i = 1; i <= n; i++)
        {
            cout <<"i = " <<i <<"; ";
            for(char to : g[i])
            {
                cout <<to <<" ";
            }
            cout <<endl;
        }
        cout <<"Cut vertice: " <<endl;

        visited = 0;
        timer = 0;
        for(int i = 0; i <= n; i++)
        {
            if(!visited[i]) dfs(i);
        }
    }

}
