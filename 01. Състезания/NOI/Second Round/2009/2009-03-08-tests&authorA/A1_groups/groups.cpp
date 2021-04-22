#include <iostream>
using namespace std;
long long F[801][801];

int min(int x, int y)
{
    if (x<y)
      return x;
    else
      return y;  
}

int main()
{
  int n,k,p,q,i, m;
   
  cin >> n >> k;
  F[1][1]=1;          
  for (p=2;p<=n;p++)
  {
    m=min(p,k);
    for (q=1;q<=m;q++)
      if ((q==p) or (q==1))
        F[q][p] = 1;
      else  
        F[q][p] = F[q-1][p-1]+F[q][p-q];        
  }
    
  cout << F[k][n] << endl;
  
  return 0;
}
