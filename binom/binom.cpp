#include  <iostream>
#include  <cstdlib>
using  namespace  std;
//https://informatics.mccme.ru/
int tablica[10][10];
int main()
{
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(i==0&&j==0) tablica[i][j]=1;
        else if(i==0) tablica[i][j]=1;
        else if(j==0) tablica[i][j]=1;
        else tablica[i][j]=tablica[i-1][j]+tablica[i][j-1];
    }
}
cout<<tablica[n-1][m-1];

return 0;
}

