#include <bits/stdc++.h>
using namespace std;

vector<bool> a[100000];
int n; // the count of vertices
vector< vector<int> > components;

int isAllUsed(vector<bool> used)
{
    for(int i = 0; i < n; i++)
    {
        if(!used[i]) return i;
    }
    return -1;
}

void answer(vector<bool> &used)
{
    int t = 0;
    while(t != -1)
    {
        // bfs
        vector<int> all;
        all.push_back(t);
        int count = 0;
        int secondCount = 1;
        used[t] = true;
        while(count != secondCount)
        {
            int current = all[count];
            count++;
            for(int i = 0; i < n; i++)
            {
                if(a[current][i] && !used[i])
                {
                    used[i] = true;
                    all.push_back(i);
                     secondCount++;
                }
            }
        }
        components.push_back(all);
        t = isAllUsed(used);
    }
    //printing
    int c = components.size(), k;
    cout <<c <<endl;
    for(int i = 0; i < c; i++)
    {
        k = components[i].size();
        cout <<k <<endl;
        for(int j = 0; j < k; j++)
        {
            cout << components[i][j] + 1 <<" ";
        }
        cout <<endl;
    }
}

int main()
{
 cin >>n;
 vector<bool> used(n , false);
 vector<bool> temp(n , false);
 for(int i = 0; i < n; i++)
 {
     a[i] = temp;
 }
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
 answer(used);

 return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

int n; // the count of vertices
vector< vector<int> > components;

int isAllUsed(vector<bool> used)
{
    for(int i = 0; i < n; i++)
    {
        if(!used[i]) return i;
    }
    return -1;
}

vector<int> bfs (int v, vector<bool> &used, vector< vector<int> > a) //breath-first-search (wide search)
{
    vector<int> all;
    all.push_back(v);
    int count = 0;
    used[v] = true;
    while(count != all.size())
    {
        int current = all[count];
        count++;
        for(int i = 0; i < a[current].size(); i++)
        {
            if(!used[i])
            {
                used[i] = true;
                all.push_back(i);
            }
        }
    }
    return all;
}

void find_components(vector<bool> &used, vector< vector<int> > a)
{
    int t = 0;
    while(t != -1)
    {
        components.push_back(bfs(t, used, a));
        t = isAllUsed(used);
    }
}

void print_components(vector<bool> &used, vector< vector<int> > a)
{
    find_components(used, a);
    int c = components.size(), k;
    cout <<c <<endl;
    for(int i = 0; i < c; i++)
    {
        k = components[i].size();
        cout <<k <<endl;
        for(int j = 0; j < k; j++)
        {
            cout << components[i][j] + 1 <<" ";
        }
        cout <<endl;
    }
}

int main()
{
 cin >>n;
 vector< vector<int> > a(n);
 int s; // count of edges
 cin >>s;
 int x,y;
 for(int i = 0; i < s; i++)
 {
     cin >>x >>y;
     x--; y--;
     a[x].push_back(y);
     a[y].push_back(x);
 }
 vector<bool> used(n , false);
 print_components(used, a);

 return 0;
}*/
