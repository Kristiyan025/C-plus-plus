#include<bits/stdc++.h>
using namespace std;

const int INF = 21000;
int n, m, k;
vector<vector<int> > g;

struct triplet
{
    int a;
    int b;
    int c;
};

vector<triplet> triplets;
vector<int> d, p;

bool cmp(int a, int b)
{
    return !(d[a] > d[b]);
}

void bfs(int from = 1)
{
    d.assign(n + 1, INF);
    p.assign(n + 1, -1);
    set<int, decltype(cmp)*> q(cmp);
    q.insert(from);
    d[from] = 0;
    while(!q.empty())
    {
        int v = *(q.begin());
        q.erase(q.begin());
        cout <<v <<endl;

        set<int> forbidden;
        for(auto tr : triplets)
        {
            if(tr.b == v && p[v] == tr.a)
            {
                forbidden.insert(tr.c);
            }
        }

        for(int i : forbidden)
        {
            cout <<i <<" ";
        }
        cout <<endl;
        for(int i : g[v])
        {
            cout <<i <<" ";
        }
        cout <<endl;
        vector<int> allowed(g[v].size(), -1);
        set_difference(g[v].begin(), g[v].end(), forbidden.begin(), forbidden.end(), allowed.begin());
        for(int next : allowed)
        {
            if(next != -1 /*&& d[v] + 1 < d[next]*/)
            {
                if(p[p[p[next]]] == next) continue;
                //q.erase(next);
                d[next] = d[v] + 1;
                p[next] = v;
                q.insert(next);
            }

            if(next == n)return;
        }
    }
}
/*
vector<int> res;
bool firstTime = true;

void dfs(vector<int> path = vector<int>(1, 1))
{
    /*for(int i : path)
    {
        cout <<i <<" ";
    }
    cout <<endl;
    int len = path.size();
    //if(len > m) return;
    if(len > res.size() && !firstTime) return;
    if(len > 2)
    {
        for(auto t : triplets)
        {
            if(path[len - 3] == t.a &&
               path[len - 2] == t.b &&
               path[len - 1] == t.c)
            {
                return;
            }
        }
    }
    if(path[len - 1] == n && (len < res.size() || firstTime))
    {
        res = path;
        firstTime = false;
        return;
    }

    for(int next : g[path[len - 1]])
    {
        path.emplace_back(next);
        dfs(path);
        path.pop_back();
    }
}*/

int main()
{
    ios_base::sync_with_stdio(false);

    cin >>n >>m >>k;
    g.resize(n + 1);
    int a, b, c;
    for(int i = 0; i < m; i++)
    {
        cin >>a >>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    triplets.resize(k);
    for(int i = 0; i < k; i++)
    {
        cin >>a >>b >>c;
        //cout <<"p";
        triplets[i] = {a, b, c};
    }

    bfs();

    /*if(res.size() == 0)
    {
        cout <<-1<<endl;
        return 0;
    }

    cout <<res.size() - 1 <<endl;
    for(int node : res)
    {
        cout <<node <<" ";
    }
    cout <<endl;*/

    if(p[n] == -1)
    {
        cout <<-1 <<endl;
        return 0;
    }

    vector<int> order;
    int previous = n;
    while(previous != -1)
    {
        order.emplace_back(previous);
        previous = p[previous];
    }

    cout <<order.size() - 1 <<endl;
    for(int i = order.size() - 1; i >= 0; i--)
    {
        cout <<order[i] <<" ";
    }
    cout <<endl;
}
