#include<bits/stdc++.h>
using namespace std;

int n, m;
struct node
{
    int val;
    node* next;
    node(int v, node* p)
    {
        val = v;
        next = p;
    }
};

class LinkedList
{
public:
    node* st, en;
    int sz;
    LinkedList(int val)
    {
        st = en = new node(val, nullptr);
        sz = 1;
    }
    void add_range(LinkedList lin)
    {
        en->next = lin.st;
        en = lin.en;
        sz += lin.sz;
    }
};

vector<int> p, xp;
vector<LinkedList > l;

void init()
{
    p.resize(n + 1);
    xp.resize(n + 1);
    l.resize(n + 1);
    for(int i = 1; i <= n; i++)
    {
        p[i] = i;
        xp[i] = 0;
        l[i] = new LinkedList(i);
    }
}

int get(int v)
{
    if(p[v] == v) return v;
    return p[v] = get(p[v]);
}

void add(int u, int v)
{
    u = get(u);
    for(node* i = l[u].st; i != nullptr; i = i->next)
    {
        xp[i->val] += v;
    }
}

void unite(int u, int v)
{
    u = get(u);
    v = get(v);
    if(u == v) return;
    if(l[u].size() < l[v].size())
    {
        swap(u, v);
    }
    l[u].add_range(l[v]);
    p[v] = u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >>n >>m;
    init();
    string c;
    int u, v;
    for(int i = 0; i < m; i++)
    {
        cin >>c >>u;
        if(c == "get")
        {
            cout <<xp[u] <<"\n";
        }
        else if(c == "add")
        {
            cin >>v;
            add(u, v);
        }
        else
        {
            cin >>v;
            unite(u, v);
        }
    }
}
