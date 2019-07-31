/*
EXAMPLE INPUT:
  N = 5
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5

EXAMPLE OUTPUT:
The largest sum is: 30
GO LEFT!
GO LEFT!
GO RIGHT!
GO LEFT!
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int n; //MAXIMAL VALUE OF N IS 15
int a[16][16]; //  THESE ARRAY IS FOR THE INPUT
int f[16][16];//  THESE ARRAY IS FOR THE MAXIMAL VALUES OF EVERY VERTEX


void find_road(bool* road,int pos, int i, int j)
{
    /*
    A       B
     \     /
      \   /
       \ /
        0
    IF IT IS MORE OPTIMAL TO COME FROM A => IN THE ARRAY WILL BI SAVED 0
    IF IT IS MORE OPTIMAL TO COME FROM b => IN THE ARRAY WILL BI SAVED 1
    */
    if(i == 1) return;
    else if(i == j)
    {
        road[pos] = 0;
        find_road(road, pos - 1, i - 1, j - 1);
    }
    else if (j == 1)
    {
        road[pos] = 1;
        find_road(road, pos - 1, i - 1, j);
    }
    else
    {
        if(f[i - 1][j - 1] >= f[i - 1][j])
        {
            road[pos] = 0;
            find_road(road, pos - 1, i - 1, j - 1);
        }
        else
        {
            road[pos] = 1;
            find_road(road, pos - 1, i - 1, j);
        }
    }
}

int main()
{
    cin >> n;

    /*  GETTING THE VALUES OF THE TRIANGLE AND SETTING SOME VALUES IN THE OPTIMAL ARRAY */
    f[0][0] = 0;
    f[0][1] = 0;
    for(int i = 1; i <= n; i++)
    {
        f[i][0] = 0;
        for(int j = 1; j <= i; j++)
        {
            cin >>a[i][j];
        }
        if(i != n) f[i][i+1] = 0;
    }

    /*  FINDING THE MAXIMAL VALUE FOR EVERY VERTEX  */
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
        }
    }

    /*  FINDING THE MAXIMAL VALUE IN THE LAST ROW  */
    int maxSum = f[n][1];
    int j = 1;
    for(int i = 2; i <= n; i++)
    {
        //maxSum = max(maxSum, f[n][i]);
        if(maxSum < f[n][i])
        {
            maxSum = f[n][i];
            j = i;
        }
    }
    cout <<"The largest sum is: " <<maxSum <<endl;

    /*  FINDING THE OPTIMAL ROAD  */
    bool road[n-1];
    find_road(road, n - 2, n, j);
    for(int i = 0; i < n - 1; i++)
    {
        if(road[i]) cout <<"GO LEFT!" <<endl;
        else cout <<"GO RIGHT!" <<endl;
    }

    return 0;
}
