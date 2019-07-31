#include <bits/stdc++.h>
using namespace std;

double xr,yr,rm,rg;//prustena
double linelength(double,double,double,double);
char kude(double, double, double);

struct zvezda
{
    double xz;
    double yz;
    double rz;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin >>xr >>yr >>rm >>rg;
    vector<zvezda> zvezdi; vector<zvezda> ::iterator it;
    zvezda a;
    while(cin >>a.xz >>a.yz >>a.rz)
    {
        zvezdi.push_back(a);
    }
    for(it = zvezdi.begin(); it<zvezdi.end() ; it++)
    {
        char kudeE = kude(*it);
        if(kudeE == 'i') cout <<"Zvezdata  e izcqlo zakrita ot prustena!";
        else if(kudeE == 'o') cout <<"Zvezdata izobshto ne e zakrita ot prustena!";
        else cout <<"Zvezdata e chastichno zakrita ot prustena!";
    }



return 0;
}

double linelength(double x1, double y1, double x2, double y2)
{
    double a = abs(x1 - x2);
    double b = abs(y1 - y2);
    return sqrt(a*a + b*b);
}

char kude(struct zvezda it)
{
    double r=linelength(it.xr,it.yr,it.xz,it.yz);
    if(r <= it.rm-it.rz) return 'o';
    else if(r >= it.rm + it.rz && r<=it.rg - it.rz) return 'i';
    else if(r >= it.rg + it.rz) return 'o';
    else return 'u';
}
