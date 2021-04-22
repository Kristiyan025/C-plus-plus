#include<bits/stdc++.h>
using namespace std;

const int maxN = 100;
int n, m;
vector<string> names;
unordered_map<string, char> ids;
vector<vector<char> > g;
bitset<maxN> visited;
vector<char> tin, low;
char timer;
unordered_set<char> cut_vertices;

void dfs(char v, char p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
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

            if(low[to] >= tin[v] && p != -1)
            {
                cut_vertices.insert(v);
            }
            children++;
        }
    }
    if(p == -1 && children > 1)
    {
        cut_vertices.insert(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >>n;
    string loc, dest;
    int maps = 1;
    while(n != 0)
    {
        names = vector<string>(n);
        ids = unordered_map<string, char>();
        g = vector<vector<char> >(n, vector<char>());
        visited = 0;
        tin = vector<char>(n, -1);
        low = vector<char>(n, -1);
        timer = 0;
        cut_vertices = unordered_set<char>();

        for(char i = 0; i < n; i++)
        {
            cin >>loc;
            names[i] = loc;
            ids[loc] = i;
        }

        cin >>m;
        for(char i = 0; i < m; i++)
        {
            cin >>loc >>dest;
            g[ids[loc]].push_back(ids[dest]);
            g[ids[dest]].push_back(ids[loc]);
        }
/*
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < g[i].size(); j++)
            {
                cout <<(char)(g[i][j]+'0') <<" ";
            }cout <<endl;
        }
*/
        for(char i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }

        cout <<"City map #" <<maps++ <<": " <<cut_vertices.size() <<" camera(s) found\n";
        //sort(cut_vertices.begin(), cut_vertices.end());
        for(int i :cut_vertices)
        {
            cout <<names[i] <<endl;
        }
        cout <<endl;

        cin >>n;
    }
}
