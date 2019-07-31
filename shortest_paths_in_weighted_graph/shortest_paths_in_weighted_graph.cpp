/*
      Dijkstra's Algorithm

    It works only with nonnegative weights
    https://arena.maycamp.com/practice/get_problem_description?contest_id=228&problem_id=1578
*/
#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > graph;
int n; // vertices count

vector<int> shortest_paths_from(int start) // bfs
{
    vector<bool> poseteni(n);
    vector<int> distances(n);
    for(int i = 0; i < n; i++)
    {
        poseteni[i] = false;
        distances[i] = INT_MAX;
    }
    distances[start] = 0;
    int current = start;
    while(current != -1)
    {
        poseteni[start] = true;
        int newCurrent = -1;
        for(int i = 0; i < n; i++)
        {
            if(graph[current][i] != -1 && !poseteni[i])
            {
                if(distances[current] + graph[current][i] < distances[i])
                {
                    distances[i] = distances[current] + graph[current][i];
                    if(newCurrent == -1 || distances[i] < distances[newCurrent])
                    {
                        newCurrent = i;
                    }
                }
            }
        }
        current = newCurrent;
    }
    for(int i = 0; i < n; i++)
    {
        if(distances[i] == INT_MAX)
        {
            distances[i] = -1;
        }
    }
    return distances;
}

int shortest_path(int start, int end)
{
    vector<int> distances = shortest_paths_from(start);
    return distances[end];
}

vector< vector<int> > all_shortest_paths()
{
    vector< vector<int> > distances(n);
    for(int i = 0; i < n; i++)
    {
        distances[i] = shortest_paths_from(i);
    }
    return distances;
}

int main()
{
 cin >>n;
 // graph initialization
 vector<int> p(n);
 for(int i = 0; i < n; i++)
 {
     graph.push_back(p);
     for(int j = 0; j < n; j++)
     {
         graph[i][j] = -1; //there is no edge
     }
 }
 int edgesCount;
 cin >>edgesCount;
 for(int i = 0; i < edgesCount; i++)
 {
     int start,end,weight;
     cin >>start >>end >>weight;
     graph[start][end] = weight;
     graph[end][start] = weight;
 }
 vector< vector<int> > distances = all_shortest_paths();
 cout <<"      ";
 for(int i = 0; i < n; i++)
 {
     stringstream ss;
     ss << i;
     string s = '[' + ss.str() + ']';
     cout <<setw(4) <<s;
 }
 cout <<endl;
 for(int i = 0; i < n; i++)
 {
     cout <<setw(4) <<'[' <<i <<']';
     for(int j = 0; j < n; j++)
     {
         cout <<setw(4) <<distances[i][j];
     }
     cout <<endl;
 }

return 0;
}
