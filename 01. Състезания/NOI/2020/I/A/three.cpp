#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 1;
int n;
vector <bitset<maxN> > mtx; //g
vector<int> unused;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >>n;
    unused.assign(n + 1, n - 1);
    mtx.resize(n + 1);

    int a, b;
    for(int i = 0; i < n - 1; i++)
    {
        cin >>a >>b;
        mtx[a][b] = mtx[b][a] = 1;
        unused[a]--;
        unused[b]--;
    }

    unsigned long long count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(unused[i] > 1)
        {
            count += (unused[i] * (unused[i] - 1) / 2);
        }

        for(int j = i + 1; j <= n; j++)
        {
            if(!mtx[i][j]) unused[j]--;
        }
    }

    cout <<count <<endl;
}
