#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct point
{
    double x;
    double y;
};

struct line
{
    double a;
    double b;
    double c;
};

line setLine(point p1, point p2)
{
    line l;
    l.a = p1.y - p2.y;
    l.b = p2.x - p1.x;
    l.c = p1.x * p2.y - p2.x * p1.y;
    return l;
}

bool isPointOnLine(point p, line l)
{
    double distance= abs((l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b));
    if(distance==0) return true;
    return false;
}

int main()
{
    vector<point> points;
    int n;
    cin >>n;
    for(int i = 0; i < n; i++)
    {
        point p;
        cin >> p.x >>p.y;
        points.push_back(p);
    }
    int pointCount=2;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            line l = setLine(points[i], points[j]);
            int currentCount = 2;
            for(int p = j + 1; p < n; p++)
            {
                if(isPointOnLine(points[p], l))
                {
                    currentCount++;
                }
            }
            if(currentCount > pointCount)
            {
                pointCount = currentCount;
            }
        }
    }
    cout <<pointCount;

    return 0;
}
