#include <bits/stdc++.h>
using namespace std;

bool a[15][15];
int n; // the count of vertices

vector<int> bfs (int v) //breath-first-search (wide search)
{
    vector<bool> used(n , false);
    queue<int> q;
    vector<int> prev(n);
    prev[v] = -1;
    q.push(v);
    used[v] = true;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if(a[current][i] && !used[i])
            {
                used[i] = true;
                prev[i] = current;
                q.push(i);
            }
        }
    }
    return prev;
}

void path(int v, int c)
{
    vector<int> prev = bfs(v);
    vector<int> put;
    int f = c;
    while(f != -1)
    {
        put.push_back(f);
        f = prev[f];
    }
    if(put.size() == 1)
    {
        cout <<"No path!";
    }
    else
    {
        reverse(put.begin(),put.end());
        cout <<"The path is: ";
        for(int i = 0; i < put.size(); i++)
        {
            cout <<put[i] + 1 << " ";
        }
    }
}

int main()
{
 cin >>n;
 int s; // count of edges
 cin >>s;
 int x,y;
 for(int i = 0; i < s; i++)
 {
     cin >>x >>y;
     x--; y--;
     a[x][y] = 1;
     a[y][x] = 1;
 }
 cin >>x >>y;
 x--; y--;
 path(x,y);

 return 0;
}
