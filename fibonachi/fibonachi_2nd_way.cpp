#include  <iostream>
#include  <cstdlib>
using  namespace  std;
int fibonachi_setter(int n)
{
    if(n==1 || n==2) return 1;
    else return fibonachi_setter(n-1)+fibonachi_setter(n-2);

}
int main()
{
int n;
cin>>n;
cout<<fibonachi_setter(n);
return 0;
}

