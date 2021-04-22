#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool isMarked = false;
    int dS = 0;
    int mini;
};

int n, m;
vector<int> a;
vector<node> t;
int l, r, x;

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        t[v].mini = a[tl];
        //cout <<"tl " <<tl <<" tr " <<tr <<" m " <<t[v].mini <<endl;
        return;
    }

    int mid = tl + ((tr - tl) >> 1),
    le = v + 1, ri = v + ((mid - tl + 1) << 1);
    build(le, tl, mid);
    build(ri, mid + 1, tr);
    t[v].mini = min(t[le].mini, t[ri].mini);
    //cout <<"tl " <<tl <<" tr " <<tr <<" m " <<t[v].mini <<endl;
}

void push(int v, int le, int ri)
{
    t[le].dS += t[v].dS;
    t[ri].dS += t[v].dS;
    t[le].mini += t[v].dS;
    t[ri].mini += t[v].dS;
    t[le].isMarked = t[ri].isMarked = true;
    t[v].isMarked = false;
}

void inc(int v, int tl, int tr)
{
    if(l > tr || r < tl) return; //totally outside
    if(l <= tl && tr <= r) //totally inside
    {
        t[v].isMarked = true;
        t[v].dS += x;
        t[v].mini += x;
        cout <<"tl " <<tl <<" tr " <<tr <<" m " <<t[v].mini <<" ds " <<t[v].dS <<" mark " <<t[v].isMarked <<endl;
        return;
    }

    int mid = tl + ((tr - tl) >> 1),
    le = v + 1, ri = v + ((mid - tl + 1) << 1);
    if(t[v].isMarked)
    {
        push(v, le, ri);
    }

    inc(le, tl, mid);
    inc(ri, mid + 1, tr);
    cout <<"tl " <<tl <<" tr " <<tr <<" m " <<t[v].mini <<" ds " <<t[v].dS <<" mark " <<t[v].isMarked <<endl;
}

int rmq(int v, int tl, int tr)
{
    if(l > tr || r < tl) return INT_MAX;
    if(l <= tl && tr <= r)
    {
        return t[v].mini;
    }

    int mid = tl + ((tr - tl) >> 1),
    le = v + 1, ri = v + ((mid - tl + 1) << 1);
    if(t[v].isMarked)
    {
        push(v, le, ri);
    }

    return min(rmq(le, tl, mid),
               rmq(ri, mid + 1, tr));
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >>n;
    a.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >>a[i];
    }

    t.assign(2 * n, node());
    build(1, 0, n - 1);
    //*
    cin >>m;
    while(m--)
    {
        stringstream ss;
        cin.ignore();
        string line;
        getline(cin, line);
        int sep = 0;
        for(int i = 0; i < line.size(); i++)
            sep += (line[i] == ' ');
        ss.str(line);
        ss >>l >>r;
        if(sep == 2) //inc
        {
            ss >>x;
            cout <<"l " <<l <<" r " <<r <<" x " <<x <<endl;
            if(r < l)
            {
                t[1].dS += x;
                t[1].mini += x;
                t[1].isMarked = true;
                swap(l, r);
                x *= -1;
            }

            inc(1, 0, n - 1);
        }
        else //rmq
        {
            cout <<"l " <<l <<" r " <<r <<endl;
            if(r < l)
            {
                int rCopy = r;
                r = l;
                l = 0;
                int left = rmq(1, 0, n - 1);
                l = rCopy;
                r = n - 1;
                cout <<min(left, rmq(1, 0, n - 1)) <<endl;
            }
            else
            {
                cout <<rmq(1, 0, n - 1) <<endl;
            }
        }
    }
    //*/
}
