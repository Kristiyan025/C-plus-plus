#include  <iostream>
#include  <bits/stdc++.h>
using  namespace  std;

const char digits[] = {'0','1','2','3','4','5','6','7','8','9'};

int main()
{
cin.tie(NULL);
ios_base::sync_with_stdio(false);
 	long long wholePart, d;
 	char ch;
 	string s;
 	bool isNeg =false;
 	cin>>wholePart >>ch >>d;
    if(wholePart<0)
    {
        wholePart*=-1;
        isNeg = true;
    }
 	//int t = trunc(d);
 	//cout <<t<<' '<<fixed<<setprecision(10)<< d;
 	do
    {
        s= digits[wholePart%10] + s;
        wholePart/=10;
    }
	while(wholePart > 0);
	s+='.';
	string ds;
    do
    {
        ds= digits[d%10]+ds;
        d/=10;
    }
	while(d > 0);
    s+=ds;
    if(isNeg) s = '-'+s;
	cout<<s;

return 0;


}
