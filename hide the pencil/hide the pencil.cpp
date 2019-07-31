#include  <iostream>
#include <cstring>
#include  <cstdlib>
using  namespace  std;
int cases[200][200]={0};
int n,m,h;
bool isVisible(int i,int j)
{
    if(h <= cases[i][j]) return true;
    bool top = false, right = false, bottom = false, left=false;
    for(int it = i - 1;it >= 0;it--)
    {
        if(h <= cases[it][j])
        {
            top = true;
            break;
        }
    }
    for(int jr = j + 1;jr < m;jr++)
    {
        if(h <= cases[i][jr])
        {
            right = true;
            break;
        }
    }
    for(int ib = i + 1;ib < n;ib++)
    {
        if(h <= cases[ib][j])
        {
            bottom = true;
            break;
        }
    }
    for(int jl = j - 1;jl >= 0;jl--)
    {
        if(h <= cases[i][jl])
        {
            left = true;
            break;
        }
    }
    if(top && right && bottom && left)  return true;
    return false;
}

int main(){
cin >>n >>m >>h;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        int nextCase;
        cin >>nextCase;
        cases[i][j]=nextCase;
    }
}
int count=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(isVisible(i,j))
        {
            count++;
        }
    }
}
cout <<count;
return 0;
}
