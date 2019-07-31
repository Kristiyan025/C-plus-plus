#include  <iostream>
#include  <cmath>
#include  <cstdlib>
using  namespace  std;

int main()
{
    cout<<"a="; double a;cin>>a;
    cout<<"b="; double b;cin>>b;
    cout<<"c="; double c;cin>>c;
    if(a==0) if(b==0) if(c==0)cout<<"Vsqko x e reshenie!"<<endl;
                         else cout<<"Nqma reshenie!"<<endl;
               else {
                      double x;
                      x=-c/b;
                      cout<<"x="<<x<<endl;
                    }
      else {
            double d=b*b-4*a*c;
            if(d>=0)  {
                       double x1=(-b+sqrt(d))/(2*a);
                       double x2=(-b-sqrt(d))/(2*a);
                       cout<<"x1="<<x1<<endl;
                       cout<<"x2="<<x2<<endl;
                       }
              else cout<<"Nqma realni koreni!"<<endl;
           }


return 0;
}


