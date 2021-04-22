#include<bits/stdc++.h>
using namespace std;

using number = int;
using ll = long long;

struct point
{
    number x, y;
    bool isNazi;
    point() {}
    point(number x, number y)
    {
        this->x = x;
        this->y = y;
    }

    point& operator -=(const point& p)
    {
        this->x -= p.x;
        this->y -= p.y;
        return *this;
    }
};

bool operator ==(const point& p1, const point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator !=(const point& p1, const point& p2)
{
    return !(p1.x == p2.x && p1.y == p2.y);
}

bool operator <(const point& p1, const point& p2)
{
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

point operator -(const point& p1, const point& p2)
{
    point p(p1.x - p2.x, p1.y - p2.y);
    return p;
}

point operator +(const point& p1, const point& p2)
{
    point p(p1.x + p2.x, p1.y + p2.y);
    return p;
}

bool ccw(const point& p1, const point& p2, const point& p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y) > 0;
}

bool cw(const point& p1, const point& p2, const point& p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y) < 0;
}

ll det(const point& p1, const point& p2, const point& p3)
{
    return 1LL * (p2.x - p1.x) * (p3.y - p1.y) - 1LL * (p3.x - p1.x) * (p2.y - p1.y);
}

ll distSq(point p1)
{
    return 1LL * p1.x * p1.x + 1LL * p1.y * p1.y;
}

void convexHull(vector<point>& pts) //Graham's scan
{
    if(pts.size() < 3)
    {
        pts = {};
        return;
    }

    sort(pts.begin(), pts.end());
    point& a = pts[0], b = pts.back();

    vector<point> up = {a}, down = {a};
    set<point> unused;
    for(number i = 1; i < pts.size(); i++)
    {
        if(!cw(a, b, pts[i]))
        {
            while(up.size() > 1 && !cw(up[up.size() - 2], up.back(), pts[i]))
            {
                unused.insert(up.back());
                up.pop_back();
            }
            up.emplace_back(pts[i]);
        }
        if(!ccw(a, b, pts[i]))
        {
            while(down.size() > 1 && !ccw(down[down.size() - 2], down.back(), pts[i]))
            {
                unused.insert(down.back());
                down.pop_back();
            }
            down.emplace_back(pts[i]);
        }
    }

    pts.resize(up.size() + down.size() - 2);
    number counter = 0;
    for(number i = 0; i < down.size(); i++)
    {
        pts[counter++] = down[i];
    }
    for(number i = up.size() - 2; i > 0; i--)
    {
        pts[counter++] = up[i];
    }
    /*
    cout <<"Unused: \n";
    for(point k : unused)
    {
        cout <<k.x <<" " <<k.y <<endl;
    }
    //*/
    if(pts.size() < 3)
    {
        pts = {};
        return;
    }
    if(pts.size() == 3)
    {
        //cout <<"pts 3\n";
        bool inside;
        for(point t : unused)
        {
            inside = true;
            for(int i = 1; i < pts.size(); i++)
            {
                if(det(pts[i - 1], pts[i], t) == 0)
                {
                    inside = false;
                    break;
                }
            }
            if(inside)
            {
                return;
            }
        }

        //cout <<"no points inside\n";
        vector<point> n1 = { pts[0], pts[1] },
                      n2 = { pts[1], pts[2] },
                      n3 = { pts[2], pts[0] };
        point v1 = n1[0], v2 = n2[0], v3 = n3[0];
        //vector<point> temp;
        /*
        cout <<"n1\n";
        temp = n1;
        for(int i = 0; i < temp.size(); i++)
        {
            cout <<temp[i].x <<" " <<temp[i].y <<endl;
        }
        cout <<"n2\n";
        temp = n2;
        for(int i = 0; i < temp.size(); i++)
        {
            cout <<temp[i].x <<" " <<temp[i].y <<endl;
        }
        cout <<"n3\n";
        temp = n3;
        for(int i = 0; i < temp.size(); i++)
        {
            cout <<temp[i].x <<" " <<temp[i].y <<endl;
        }
        */
        //cout <<"n11111\n";
        for(point t : unused)
        {
            //cout <<det(n1[0], n1[1], t) <<endl;
            if(det(n1[0], n1[1], t) == 0)
            {
                n1.emplace_back(t);
            }
            else if(det(n2[0], n2[1], t) == 0)
            {
                n2.emplace_back(t);
            }
            else //if(det(n3[0], n3[1], t) == 0)
            {
                n3.emplace_back(t);
            }
        }

        /*
        cout <<"n1\n";
        temp = n1;
        for(int i = 0; i < temp.size(); i++)
        {
            cout <<temp[i].x <<" " <<temp[i].y <<endl;
        }
        cout <<"n2\n";
        temp = n2;
        for(int i = 0; i < temp.size(); i++)
        {
            cout <<temp[i].x <<" " <<temp[i].y <<endl;
        }
        cout <<"n3\n";
        temp = n3;
        for(int i = 0; i < temp.size(); i++)
        {
            cout <<temp[i].x <<" " <<temp[i].y <<endl;
        }
        //*/

        if(n1.size() > 2 && n2.size() > 2 && n3.size() > 2)
        {
            //cout <<"all with more\n";
            return;
        }
        if(unused.size() == 0 ||
           (n1.size() == 2 && n2.size() == 2 && n3.size() > 2) ||
           (n1.size() == 2 && n2.size() > 2 && n3.size() == 2) ||
           (n1.size() > 2 && n2.size() == 2 && n3.size() == 2))
        {
            //cout <<"all used or except one\n";
            pts = {};
            return;
        }
        for(int i = 0; i < n1.size(); i++)
        {
            n1[i] = n1[i] - v1;
        }
        for(int i = 0; i < n2.size(); i++)
        {
            n2[i] = n2[i] - v2;
        }
        for(int i = 0; i < n3.size(); i++)
        {
            n3[i] = n3[i] - v3;
        }
        auto comp = [](const point& p1, const point& p2)
            {
                return (distSq(p1) < distSq(p2));
            };
        //cout <<"all except 2\n";
        if(n1.size() == 2)
        {
            sort(n2.begin(), n2.end(), comp);
            sort(n3.begin(), n3.end(), comp);
            /*
            cout <<"n1 1\n";
            for(int i = 0; i < n1.size(); i++)
            {
                cout <<(v1 + n1[i]).x <<" " <<(v1 + n1[i]).y <<endl;
            }
            //*/
            pts = { v1 + n1[0], v1 + n1[1], v2 + n2[n2.size() - 2], v3 + n3[1] };
            return;
        }
        if(n2.size() == 2)
        {
            sort(n1.begin(), n1.end(), comp);
            sort(n3.begin(), n3.end(), comp);
            /*
            cout <<"n1 2\n";
            for(int i = 0; i < n1.size(); i++)
            {
                cout <<(v1 + n1[i]).x <<" " <<(v1 + n1[i]).y <<endl;
            }
            //*/
            pts = { v1 + n1[1], v2 + n2[0], v2 + n2[1], v3 + n3[n3.size() - 2] };
            return;
        }
        if(n3.size() == 2)
        {
            //cout <<"here\n";
            sort(n1.begin(), n1.end(), comp);
            sort(n2.begin(), n2.end(), comp);
            /*
            cout <<"n1 3\n";
            for(int i = 0; i < n1.size(); i++)
            {
                cout <<(v1 + n1[i]).x <<" " <<(v1 + n1[i]).y <<endl;
            }
            //*/
            pts = { v1 + n1[n1.size() - 2], v2 + n2[1], v3 + n3[0], v3 + n3[1] };
            return;
        }
    }
}

number n, s;
vector<point> nazi;
point  stal, a, b, z, translation;

bool isFurtherOnTheLine(const point& l, const point& p)
{
    return 1LL * p.x * p.x + 1LL * p.y * p.y > 1LL * l.x * l.x + 1LL * l.y * l.y;
}

bool isPointInDanger()
{
    stal = stal - translation;
    ll first = det(a, b, stal),
        last = det(a, z, stal);
    if(first < 0 || last > 0) return false;
    if(first == 0) return !isFurtherOnTheLine(b, stal);
    if(last == 0) return !isFurtherOnTheLine(z, stal);

    number l = 1, r = n - 1;
    number mid;
    point midP;
    ll d;
    while(r - l > 1)
    {
        mid = (l + r) >> 1;
        midP = nazi[mid];
        d = det(a, midP, stal);
        if(d < 0) //clockwise
        {
            r = mid;
            continue;
        }
        if(d > 0) //counter-clockwise
        {
            l = mid;
            continue;
        }

        return !isFurtherOnTheLine(midP, stal);
    }

    d = det(nazi[l], nazi[l + 1], stal);
    return d >= 0;
}

int main()
{
    //todo : degenerate quDRILATERAL BETTER CHECK
    ios_base::sync_with_stdio(false);
    cin >>n;
    nazi.resize(n);
    for(number i = 0; i < n; i++)
    {
        cin >>nazi[i].x >>nazi[i].y;
    }

    convexHull(nazi);
    n = nazi.size();
    if(n == 0)
    {
        cout <<0 <<endl;
        return 0;
    }
    /*
    cout <<"Convex hull: \n";
    for(int i = 0; i < n; i++)
    {
        cout <<nazi[i].x <<" " <<nazi[i].y <<endl;
    }
    //*/
    translation = nazi[0];
    for(int i = 0; i < n; i++)
    {
        nazi[i] = nazi[i] - translation;
    }
    a = nazi[0];
    b = nazi[1];
    z = nazi.back();
    cin >>s;
    number counter = 0;
    for(number i = 0; i < s; i++)
    {
        cin >>stal.x >>stal.y;
        counter += isPointInDanger();
    }

    cout <<counter <<endl;
}

/*
5
1 2
3 2
5 2
2 5
3 4
8
2 4
2 3
3 3
4 3
2 2
1 3
1 4
3 5

4


5
1 2
3 2
5 2
2 5
4 2
2
3 4
2 3

0


6
1 2
3 2
5 2
2 5
4 2
4 3
2
3 4
2 3

2


8
-1 2
3 2
5 2
2 5
4 2
4 3
2 2
3 4
2
3 4
2 3

2
*/
