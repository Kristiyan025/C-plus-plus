#include <iostream>
#include <cstdlib>
using namespace std;
int n,m;
int chisla[50][50]={0};

int broi()
{
    chisla[0][0]=1;
    if((n+m)%3!=2)
    {
        return 0;
    }
    else if(n==m && n==1)
    {
        return 1;
    }
    else if((n==1&&m>1)||(m==1&&n>1))
    {
        return 0;
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if((i+j)%3 == 0)
                {
                    if(i>1)
                    {
                        chisla[i][j]+=chisla[i-2][j-1];
                    }
                    if(j>1)
                    {
                        chisla[i][j]+=chisla[i-1][j-2];
                    }
                }
            }
        }
        return chisla[n-1][m-1];
    }
}
int main()
{
cin >>n >>m;
cout<<broi();

return 0;

}
