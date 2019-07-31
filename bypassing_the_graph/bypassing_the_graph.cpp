#include <bits/stdc++.h>
using namespace std;

bool a[99][99];
int n; // the count of vertices

int bfs (int v)
{
    int count = 0;
    vector<bool> used(n , false);
    queue<int> q;
    q.push(v);
    used[v] = true;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        count++;
        for(int i = 0; i < n; i++)
        {
            if(a[current][i] && !used[i])
            {
                used[i] = true;
                q.push(i);
            }
        }
    }
    return count;
}


int main()
{
 cin >>n;
 int s; // current vertex
 cin >>s;
 s--;
 int t;
 for(int i = 0; i < n; i++)
 {
     for(int j = 0; j < n; j++)
     {
         cin >>t;
         if(t == 1) a[i][j] = true;
         else a[i][j] = false;
     }
 }
 cout <<"The count of connected vertices: " <<bfs(s);

 return 0;
}
