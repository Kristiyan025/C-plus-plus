#include<iostream>
#include<stdio.h>
using namespace std;

const int maxN = 10000, maxQ = maxN, maxM = 10;

int n, m ,q;

struct circle
{
    short x, y, r;
} circles[maxN];

struct pt
{
    short x, y;
} pts[maxM];

short s[maxQ];

int logic()
{
    scanf("%i %i %i", &n, &m, &q);
    for(int i = 0; i < n; i++)
    {
        scanf("%i %i %i", &circles[i].x, &circles[i].y, &circles[i].r);
    }

    for(int i = 0; i < m; i++)
    {
        scanf("%i %i", &pts[i].x, &pts[i].y);
    }

    for(int i = 0; i < q; i++)
    {
        scanf("%i", &s[i]);
    }

    long long score = 0;
    long previous = 1;
    for(int i = 0; i < q; i++)
    {
        //cout <<"i = " <<i <<endl;
        int r = s[i] * (previous % 2 == 0 ? 2 : 1);
        //cout <<"r = " <<r <<endl;
        previous = 0;
        for(int j = 0; j < m; j++)
        {
            pt& p = pts[j];
            for(int k = 0; k < n; k++)
            {
                circle& c = circles[k];
                if(1L * (p.x - c.x) * (p.x - c.x) +
                   1L * (p.y - c.y) * (p.y - c.y) <
                   (r - c.r) * (r - c.r)) // circle is fully in
                {
                    previous++;
                }
            }
        }
        //cout <<"prev = " <<previous <<endl;
        score += previous;
    }

    return score;// <<endl;
}

int main()
{
    cout <<logic() <<endl;
}
