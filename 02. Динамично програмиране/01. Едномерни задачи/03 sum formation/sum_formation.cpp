#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
    int s,n;
    cin >>s >>n;
    int a[n+1];
    int f[n+1][s+1];
    for(int i = 1; i <= n; i++)
    {
        cin >>a[i];
    }
    for(int i = 0; i <= s; i++)
    {
        f[0][i] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        f[i][0] = 1;
    }
    int temp;
    if(a[1] == 1) temp = 1;
    else temp = 0;
    for(int k = 1; k <= n; k++)
    {
         f[k][1] = temp;
    }
    int w;
    for(int k = 1; k <= n; k++)
    {
        for(int j = 2; j <= s; j++)
        {
            if(j - a[k] < 0) w = 0;
            else w = f[k - 1][j - a[k]];
            f[k][j] = w + f[k - 1][j];
        }
    }
    cout <<f[n][s];

    return 0;
}
