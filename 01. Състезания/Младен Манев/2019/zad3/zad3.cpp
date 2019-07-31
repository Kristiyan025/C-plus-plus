#include <bits/stdc++.h>
using namespace std;

struct pt
{
    double x,y;
};
double ots(pt p1, pt p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) - (p1.y - p2.y)*(p1.y - p2.y));
}
struct line
{
    double a,b,c;
};
void init(line l, pt p1, pt p2)
{
    l.a = p1.y-p2.y;
    l.b = p2.x-p1.x;
    l.c = p1.x*p2.y-p2.x*p1.y;
}
pt third(pt p1, pt p2, double line1, double line2)
{
    double razt = ots(p1,p2);
    /*if(!(razt+line1>line2 &&
       razt+line2>line1 &&
       line2+line1>razt))
        return p1;*/
    line line3;
    init(line3, p1, p2);
    double part = line1 - (line1+line2 - razt)/2;
    double xdob = abs(p1.x-p2.x)* part / razt;
    double ydob = abs(p1.y-p2.y)* part / razt;
    if(p1.y >p2.y)
    {
        ydob*=-1;
    }
    if(p1.x > p2.x)
    {
        xdob*=-1;
    }
    pt peta;
    peta.x = p1.x+xdob;
    peta.y = p1.y+xdob;
    double h = sqrt(line1*line1 - part*part);
    line perp;
    perp.a = line3.b;
    perp.b = -line3.a;
    perp.c = line3.a*peta.y - line3.b*peta.x;
    pt p4;
    p4.x =peta.x+100;
    p4.y = -(perp.a*p4.x+perp.c)/perp.b;
    double length = ots(peta,p4);
    pt p3;
    p3.x = peta.x + 100*h/length;
    p3.y = peta.y + (p4.y-peta.y)*h/length;
    return p3;
}

int main()
{
cin.tie(NULL);
ios_base::sync_with_stdio(false);
    pt start,end;
    cin >>start.x >>start.y;
    cin >>end.x >>end.y;
    int n;
    cin >>n;
    vector<double> r(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin >>r[i];
    }
    if(n == 2)
    {
        pt point = third(start,end, r[0],r[1]);
        if(point.x == start.x && point.y == start.y)
        {
             cout<<"NO"<<endl;
             return 0;
        }
        cout <<"YES"<<endl;
        cout <<fixed<<setprecision(3) <<start.x <<' ' <<fixed<<setprecision(3) <<start.y <<endl;
        cout <<fixed<<setprecision(3) <<point.x <<' ' <<fixed<<setprecision(3) <<point.y <<endl;
        cout <<fixed<<setprecision(3) <<end.x <<' ' <<fixed<<setprecision(3) <<end.y <<endl;

    }
    return 0;
}
