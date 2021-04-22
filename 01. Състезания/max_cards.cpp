#include<iostream>
using namespace std;

//32 4561 456 29

int main()
{
    int c1, c2, c3, c4;
    cin >>c1 >>c2 >>c3 >>c4;
    int d1, d2, d3, d4;
    if(c1 < 10)
    {
        d1 = 1e1;
    }
    else if(c1 < 100)
    {
        d1 = 1e2;
    }
    else if(c1 < 1000)
    {
        d1 = 1e3;
    }
    else
    {
        d1 = 1e4;
    }

    if(c2 < 10)
    {
        d2 = 1e1;
    }
    else if(c2 < 100)
    {
        d2 = 1e2;
    }
    else if(c2 < 1000)
    {
        d2 = 1e3;
    }
    else
    {
        d2 = 1e4;
    }

    if(c3 < 10)
    {
        d3 = 1e1;
    }
    else if(c3 < 100)
    {
        d3 = 1e2;
    }
    else if(c3 < 1000)
    {
        d3 = 1e3;
    }
    else
    {
        d3 = 1e4;
    }

    if(c4 < 10)
    {
        d4 = 1e1;
    }
    else if(c4 < 100)
    {
        d4 = 1e2;
    }
    else if(c4 < 1000)
    {
        d4 = 1e3;
    }
    else
    {
        d4 = 1e4;
    }

    if(c2 * d1 + c1 > c1 * d2 + c2) { swap(c1, c2); swap(d1, d2); }
    if(c3 * d1 + c1 > c1 * d3 + c3) { swap(c1, c3); swap(d1, d3); }
    if(c4 * d1 + c1 > c1 * d4 + c4) { swap(c1, c4); swap(d1, d4); }
    if(c3 * d2 + c2 > c2 * d3 + c3) { swap(c2, c3); swap(d2, d3); }
    if(c4 * d2 + c2 > c2 * d4 + c4) { swap(c2, c4); swap(d2, d4); }
    if(c4 * d3 + c3 > c3 * d4 + c4) { swap(c3, c4); swap(d3, d4); }

    cout <<c1 <<c2 <<c3 <<c4 <<endl;
}
