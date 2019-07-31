#include <iostream>
using namespace std;
int n,m,x;
int c(int k, int n)  //Combinations of n elements k-th class
{
    int result = 1;
    for (int i = n; i >= n - k + 1; i--)
    {
        result *= i;
    }
    for (int i = k; i >= 1; i--)
    {
        result /= i;
    }
    return result;
}

int main()
{
    cin >>n >>m >>x;
    long long p[101][101][3];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            p[i][j][0] = 1;
            p[i][j][1] = c(1,i*j);
            p[i][j][2] = c(2,i*j);
            for (int k = 1; k < 3; k++)
            {
                p[0][j][k] = 0;
                p[i][0][k] = 0;
            }
        }
    }
    for (int k = 2; k <= x; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                p[i][j][2] = 0;
                if (i - 2 >= 0 && j - 1 >= 0 && k - 2 >= 0)
                {
                    p[i][j][2] += (c(2, i) * p[i - 2][j - 1][0]) % 1000001;
                }

                if (i - 1 >= 0 && j - 2 >= 0 && k - 2 >= 0)
                {
                    p[i][j][2] += (c(1, i) * c(1,j - 1) * p[i - 1][j - 2][0]) % 1000001;
                }

                if (i - 1 >= 0 && j - 1 >= 0 && k - 1 >= 0)
                {
                    p[i][j][2] += (c(1, i) * p[i - 1][j - 1][1]) % 1000001;
                }

                if (j - 1 >= 0)
                {
                    p[i][j][2] += p[i][j - 1][2] % 1000001;
                }

                p[i][j][2] %= 1000001;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                p[i][j][0] = p[i][j][1];
                p[i][j][1] = p[i][j][2];
            }
        }
    }
    cout <<p[n][m][2];
/*
for (int k = 1; k <= x; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                p[i][j][k] = 0;
                if (i - 2 >= 0 && j - 1 >= 0 && k - 2 >= 0)
                {
                    p[i][j][k] += (c(2, i) * p[i - 2][j - 1][k - 2]) % 1000001;
                }

                if (i - 1 >= 0 && j - 2 >= 0 && k - 2 >= 0)
                {
                    p[i][j][k] += (c(1, i) * c(1,j - 1) * p[i - 1][j - 2][k - 2]) % 1000001;
                }

                if (i - 1 >= 0 && j - 1 >= 0 && k - 1 >= 0)
                {
                    p[i][j][k] += (c(1, i) * p[i - 1][j - 1][k - 1]) % 1000001;
                }

                if (j - 1 >= 0)
                {
                    p[i][j][k] += p[i][j - 1][k] % 1000001;
                }

                p[i][j][k] %= 1000001;
            }
        }
    }
*/
    return 0;
}
