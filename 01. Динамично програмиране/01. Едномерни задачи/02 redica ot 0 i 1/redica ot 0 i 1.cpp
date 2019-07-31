#include  <iostream>
#include  <cstdlib>
using  namespace  std;

int counter(int n)
{
    int count=1;
    for (int i = 0; i < n; i++)
    {
        count*=2;
    }
    return count;
}

int main()
{
int n;
cin >>n;
cout <<counter(n);

 return 0;
}
