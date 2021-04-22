#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main()
{
    ios_base::sync_with_stdio(false);

    cout <<512 * 1024 / sizeof(ull);
    int n;
    cin >>n;
    vector<ull> a(n);
    ull xOr = 0;
    for(int i = 0; i < n; i++)
    {
        cin >>a[i];
        xOr ^= a[i];
    }

    for(int i = 0; i < n; i++)
    {
        ull needed = xOr ^ a[i];
        for(int j = i + 1; j < n ; j++)
        {
            if(a[j] == needed)
            {
                cout <<min(a[i], a[j]) <<" " <<max(a[i], a[j]) <<endl;
                return 0;
            }
        }
    }
}
/*
10
14
7
21
9
14
17
17
7
19
9
*/
