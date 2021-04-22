#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool isFilled = false;
    bool isWithSame = false;
    int n = -1;
};

int n, m;
vector<node> t;
int l, r, x;

void query(int v, int tl, int tr)
{
    //cout <<"v " <<v <<" tl " <<tl <<" tr " <<tr <<" f " <<t[v].isFilled <<" s " <<t[v].isWithSame <<" n " <<t[v].n <<endl;
    if(tl > r || tr < l) return; //totally outside
    if(tl == tr)
    {
        if(!t[v].isFilled && tl != x)
        {
            t[v].isFilled = t[v].isWithSame = true;
            t[v].n = x;
        }
        return;
    }
    int mid = tl + ((tr - tl) >> 1);
    int le = v + 1, ri = v + ((mid - tl + 1) << 1);
    if(l <= tl && tr <= r) //totally inside
    {
        if(!t[v].isFilled)
        {
            if(mid >= r) query(le, tl, mid);
            else if(mid < l) query(ri, mid + 1, tr);
            else
            {
                query(le, tl, mid);
                query(ri, mid + 1, tr);
            }

            if(t[le].isFilled && t[ri].isFilled)
            {
                t[v].isFilled = true;
                if(t[le].isWithSame && t[ri].isWithSame && t[le].n == t[ri].n)
                {
                    t[v].isWithSame = true;
                    t[v].n = t[le].n;
                }
            }

            return;
        }
        else return;
    }
    query(le, tl, mid);
    query(ri, mid + 1, tr);
}

void print(int v, int tl, int tr)
{
    if(tl == tr)
    {
        cout <<(!t[v].isFilled ? 0 : t[v].n) <<" ";
        return;
    }
    if(t[v].isWithSame)
    {
        for(int i = tl; i <= tr; i++)
            cout <<t[v].n <<" ";
        return;
    }

    int mid = tl + ((tr - tl) >> 1);
    int le = v + 1, ri = v + ((mid - tl + 1) << 1);
    print(le, tl, mid);
    print(ri, mid + 1, tr);
}

int main()
{
    cin >>n >>m;
    t.assign(2 * n, node());
    while(m--)
    {
        cin >>l >>r >>x;
        query(1, 1, n);
    }

    print(1, 1, n);
    cout <<endl;
}
