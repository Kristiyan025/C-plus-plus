#include <iostream>
#include <set>
using namespace std;
char s[64];
int a[20],n;
set <long long> Set;
void inp(istream &is)
{int i;
 is>>n;
 for (i=0;i<n;i++) cin>>a[i];
}
long long calc(int n,int *a,char *s)
{long long r=0,p=0;
 int i,j;
 for (i=0;i<n;i++) {if (s[i]=='*')
		     {p=a[i++];
		      while (i<n && s[i]=='*') p*=a[i++];
		      for (j=i-1;s[j]=='*';j--);
		      if (s[j]=='+') r=r-a[j]+p*a[j];
		      else r=r+a[j]-p*a[j];
		      i--;
		     }
		     else if (s[i]=='+') r+=a[i];
			  else r-=a[i];
		   }
 return r;
}
void makeAll(int lev)
{if (lev==n)
 {Set.insert(calc(n,a,s));
  return;
 }
 s[lev]='+';
 makeAll(lev+1);
 s[lev]='*';
 makeAll(lev+1);
 s[lev]='-';
 makeAll(lev+1);
}
int main(void)
{inp (cin);
 s[0]='+';
 makeAll(1);
 cout<<Set.size()<<endl;
 return 0;
}
