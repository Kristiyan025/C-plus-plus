#include<bits/stdc++.h>
using namespace std;

const short maxN = 1e4 + 1;
short n, q;
int m;
vector<short> g[maxN];
vector<char> counts[maxN];
bitset<maxN> visited = 0;
short tin[maxN], low[maxN];
vector<short> bridges[maxN];
short timer = 0;

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

bool bfs(short start, short ending)
{
    visited = 0;
    visited[start] = 1;
    queue<short> q;
    q.push(start);
    while(!q.empty())
    {
        short v = q.front();
        //cout <<"v " <<v <<endl;
        q.pop();
        for(short to : bridges[v])
        {
            //cout <<"to " <<endl;
            if(!visited[to])
            {
                if(to == ending) return true;
                visited[to] = true;
                q.push(to);
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    bool isStarting = true;
    while(1)
    {
        if(!isStarting) cout <<"-" <<endl;
        isStarting = false;
        cin >>n >>m >>q;
        if(n == 0 && m == 0 && q == 0) break;
        short s, p;
        for(short i = 1; i <= n; i++)
        {
            counts[i].assign(n + 1, 0);
            g[i].clear();
            bridges[i].clear();

        }
        for(short i = 0; i < m; i++)
        {
            cin >>s >>p;
            g[s].push_back(p);
            g[p].push_back(s);
                counts[s][p]++;
                counts[p][s]++;
        }

        visited = 0;
        timer = 0;
        for(short i = 1; i <= n; i++)
        {
            if(!visited[i]) dfs(i);
        }

        /*for(short i = 1; i <= n; i++)
        {
            for(short v : bridges[i])
            {
                cout <<v <<" ";
            }
            cout <<endl;
        }*/

        for(short i = 0; i < q; i++)
        {
            cin >>s >>p;
            if(bridges[i].size() == 0) {cout <<"N\n"; continue;}
            cout <<(bfs(s, p) ? 'Y' : 'N') <<endl;
        }
    }
}
/*

//12363
//Hedge Mazes
//Graphs;Finding Bridges
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int V[MAX], L[MAX], P[MAX], n, gpe;
vector<int> G[MAX];

inline int findset(int v) {
    if (P[v] != -1 && P[v] != v)
        return P[v] = findset(P[v]);
    return v;
}

inline int unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a<b) swap(a,b);
    P[b] = a;
}

void dfs(int u, int v) {
    V[v] = L[v] = ++gpe;

    for(int i = 0; i < G[v].size(); i++) {
        int w = G[v][i];
        if(!V[w]){
            dfs(v, w);
            L[v] = min(L[v], L[w]);

            if (L[w] > V[v])
                unionset(v, w);
        } else if(w != u) {
            L[v] = min(L[v], V[w]);
        }
    }
}

int main() {
    int m, q;
    while(cin >> n >> m >> q, n|m|q) {
        memset(G, 0, sizeof(vector<int>)*(n+1));
        memset(V, 0, sizeof(int)*(n+1));
        memset(L, 0, sizeof(int)*(n+1));
        memset(P, -1, sizeof(int)*(n+1));
        gpe = 0;

        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        for(int i=0; i<n; i++)
            if (!V[i])
                dfs(i, i);

        for(int i=0; i<q; i++) {
            int a, b;
            cin >> a >> b;
            cout << (findset(a)==findset(b) ? "Y" : "N") << endl;
        }
        cout << "-" << endl;
    }
}*/
