#include <iostream>
#include <cstdlib>
using namespace std;
int n,m;
long chisla[15][15]={0};
/*  dobavqne na nachinite do kletka [i][j] kum vsichki vuzmogni  */
void rec(int i,int j)
{
    if(i >= 1 && j <= (m - 3))
    {
        chisla[i - 1][j + 2] += chisla[i][j];
    }
    if(i <= (n - 2) && j <= (m - 3))
    {
        chisla[i + 1][j + 2] += chisla[i][j];
    }
    if(i  <= (n - 3) && j <= (m - 2))
    {
        chisla[i + 2][j + 1] += chisla[i][j];
    }
    if(i <= (n - 3) && j >= 1)
    {
        chisla[i + 2][j - 1] += chisla[i][j];
    }
}
/* obikalqne na masiva po diagonali */
void obikalqne()
{
    for(int p = 0; p < n; p++)
    {
        int j = 0;
        for(int i = p; i >= 0; i--)
        {

            if(j >= m)
            {
                break;
            }
            else //if(!(chisla[i][j]==0))
            {
                //cout<<i <<" " <<j <<endl;
                rec(i,j);
            }
            j++;
        }
    }
    for(int p = 1; p < m; p++)
    {
        int i = n - 1;
        for(int j = p; j <= m; j++)
        {
            if((i < 0 || i >= n)||(j < 0 || j >= m))
            {
                break;
            }
            else if(!chisla[i][j]==0)
            {
                //cout<<i <<" " <<j <<endl;
                rec(i,j);
            }
            i--;
        }
    }
}
int main()
{
cin >>n >>m;
chisla[0][0]=1;
obikalqne();
/* proverqvane na vuzmognostite na vsqka kletka

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cout<<chisla[i][j] <<" ";
    }
    cout<<endl;
}

*/
cout<<chisla[n-1][m-1];
return 0;

}
