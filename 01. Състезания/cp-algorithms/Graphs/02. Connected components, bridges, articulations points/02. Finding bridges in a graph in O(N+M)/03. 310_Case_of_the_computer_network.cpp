#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
//#include <algorithm>
using namespace std;

const int maxN = 2e5 + 1;
int n, m, q;
vector<int> g[maxN];
vector<char> counts[maxN];
//vector< pair<int, int> > msg;
bitset<maxN> visited = 0;
int tin[maxN] = {0},
    low[maxN] = {0};
vector< bitset<maxN> > bridges, needed;
int timer = 0,
    brdgs = 0;

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
            if(low[to] > tin[v] && counts[v][to] < 2== 1)
            {
                brdgs++;
                bridges[v][to] = bridges[to][v] = 1;
            }
        }
    }
}

bool bfs(int start, int end)
{
    visited = 0;
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        //cout <<"v " <<v<<endl;
        for(int to : g[v])
        {
            //cout <<"to " <<to<<endl;
            if(!visited[to])
            {
                visited[to] = true;
                if(bridges[v][to])
                {
                    if(needed[to][v]) return false; //bridge must be used in both
                    needed[v][to] = 1;
                }

                q.push(to);
                if(to == end) return trueif(to == end) return true;
                q.push(to);
            }
        }
    }

    return false;
}

int main() {
    cin >>n >>m >>q;
    for(int i = 0; i <= n; i++)
    {
        tin[i] = low[i] = -1;
    }
    int s, d;
    //msg.resize(q);
    bridges.assign(n + 1, 0);
    needed.assign(n + 1, 0);
    for(int i = 0; i <= n; i++)
    {
        counts[i].assign(n + 1, 0);
    }
    for(int i = 0; i < m; i++)
    {
        cin >>s >>d;

        if(counts[s][d] < 2)
        {
            g[s].push_back(d);
            g[d].push_back(s);
            counts[s][d]++;
            counts[d][s]++;
        }
    }

    /*cout <<"graph\n";
    for(int i = 0; i <= n; i++)
    {
        for(int j : g[i])
        {
            cout <<j <<" ";
        }
        cout<<endl;
    }
    cout <<"counts\n";
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout <<(char)(counts[i][j] + '0')  <<" ";
        }
        cout<<endl;
    }*/
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i]) dfs(i);
    }

    /*cout <<"bridges\n";
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout <<bridges[i][j] <<" ";
        }
        cout<<endl;
    }*/
    for(int i = 0; i < q; i++)
    {
        cin >>s >>d;
        if(!bfs(s, d))
        {
            /*cout <<"needed\n";
            for(int j = 0; j <= n; j++)
            {
               for(int k = 0; k <= n; k++)
               {
                   cout <<needed[j][k] <<" ";
               }cout <<endl;
            }*/
            cout <<"No" <<endl;
            return 0;
        }
    }



    cout <<"Yes" <<endl;
}/*
6 7 1
1 2
2 3
3 1
4 5
5 6
6 4
1 4
2 6
*/
