#include  <iostream>
#include  <cstdlib>
using  namespace  std;
int fibonachi[45]={1,1};
 main()
{
int n;
cin>>n;
for(int i=2;i<45;i++)
{
    fibonachi[i]=fibonachi[i-1]+fibonachi[i-2];
}
cout<<fibonachi[n-1];


return 0;
}

