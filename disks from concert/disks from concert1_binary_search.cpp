#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
int times[100000];
/*
Ako n=3 diska k=2 komputara
 vremenata sa 10 i 15
 togava mini=10 i maksi=3*15=45
 togava t=(10+45)/2=27
 br=27/10 + 27/15=3 koeto shte stane i ako vremeto e mejdu 20 i 29
 no pri dvoichno tursene to shte stigne do 27 i shte spre a trqbva da e 20

3 2
10 15
*/
int main()
{
cin >>n >>k;
int first;
cin >>first;
times[0]=first;
long maksi=first, mini=first;
for(int i=1;i<k;i++)
{
    int current;
    cin >>current;
    if(current>maksi)
    {
        maksi=current;
    }
    if(current<mini)
    {
        mini=current;
    }
    times[i] = current;
}
maksi*=n;
long br=0;
long vreme=maksi;
long t=0;
while(mini<=maksi)
{
    t=(mini+maksi)/2;
    br=0;
    for(int i=0;i<k;i++)
    {
        br+=t/times[i];
    }
    if(br>=n)
    {
        vreme =min(vreme,t) ;
        maksi=t-1;
    }
   else   mini=t+1;
}
cout<<vreme<<endl;//t;
return 0;

}
