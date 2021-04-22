#include<bits/stdc++.h>
using namespace std;

/*
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3

*/

using number = short;

const number bound = 1e4 + 1;

struct point
{
    number x, y;
    point() {}
    point(number x, number y)
    {
        this->x = x;
        this->y = y;
    }
};

bool operator <(const point& p1, const point& p2)
{
        return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

number n;
set<point> initial;

bool cw(const point& p1, const point& p2, const point& p3) //clockwise
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y) < 0;
}

bool ccw(const point& p1, const point& p2, const point& p3) //counter-clockwise
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y) > 0;
}

void convexHull(vector<point>& pts) //Graham's scan
{
    if(pts.size() < 3) return;

    point& a = pts[0], b = pts.back();

    vector<point> up = {a}, bottom = {a};
    for(int i = 1; i < pts.size(); i++)
    {
        if(ccw(a, b, pts[i]) || i == pts.size() - 1) //Upper half
        {
            while(up.size() > 1 && !cw(up[up.size() - 2], up.back(), pts[i]))
            {
                up.pop_back();
            }

            up.emplace_back(pts[i]);
        }

        if(cw(a, b, pts[i]) || i == pts.size() - 1) //Bottom half
        {
            while(bottom.size() > 1 && !ccw(bottom[bottom.size() - 2], bottom.back(), pts[i]))
            {
                bottom.pop_back();
            }

            bottom.emplace_back(pts[i]);
        }
    }

    int counter;
    pts.resize(up.size() + bottom.size() - 2);
    for(counter = 1; counter < bottom.size(); counter++)
    {
        pts[counter] = bottom[counter];
    }

    for(int i = up.size() - 2; i > 0; i--)
    {
        pts[counter++] = up[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    number a, b;
    while(true)
    {
        cin >>n;
        if(n == 0) break;

        initial.clear();
        for(int i = 0; i < n; i++)
        {
            cin >>a >>b;
            initial.insert(point(a, b));
        }

        vector<point> pts(initial.begin(), initial.end());
        convexHull(pts);
        cout <<pts.size() <<endl;
        for(int i = 0; i < pts.size(); i++)
        {
            cout <<pts[i].x <<" " <<pts[i].y <<endl;
        }
    }
}
