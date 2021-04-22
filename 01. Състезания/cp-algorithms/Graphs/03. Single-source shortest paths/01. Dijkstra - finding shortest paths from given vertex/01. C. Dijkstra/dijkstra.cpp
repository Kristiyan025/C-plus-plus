#include<bits/stdc++.h>
using namespace std;

const unsigned long long INF = 1e12 + 1111;
const int maxN = 1e5 + 1;
int n, m;
vector<vector<pair<int, int> > > g;
//bitset<maxN> visited;
vector<int> p;
vector<unsigned long long> d;

void bfs(int from)
{
    //visited.assign(n + 1, false);
    d.assign(n + 1, INF);
    p.assign(n + 1, -1);
    d[from] = 0;
    set<pair<int, int> > q;
    q.insert({0, from});
    while(!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(auto edge : g[v])
        {
            int to = edge.first;
            int len = edge.second;

            if(d[v] + len < d[to])
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >>n >>m;
    g.resize(n + 1);
    int a, b, w;
    for(int i = 0; i < m; i++)
    {
        cin >>a >>b >>w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    bfs(1);
    if(p[n] == -1)
    {
        cout <<-1 <<endl;
        return 0;
    }

    int previous = n;
    vector<int> order;
    while(previous != -1)
    {
        order.push_back(previous);
        previous = p[previous];
    }

    for(int i = order.size() - 1; i >= 0; i--)
    {
        cout <<order[i] <<" ";
    }
    cout <<endl;
}
