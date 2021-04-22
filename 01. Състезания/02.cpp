#include<bits/stdc++.h>
using namespace std;

int k;
vector< set<int> > v;
vector<int> sizes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >>k;
    v.resize(k);
    sizes.resize(k);
    int a;
    int maxi = 0, mini = 1;
    cin >>sizes[0] >>sizes[1];
    if(sizes[0] < sizes[1])
    {
        swap(maxi, mini);
    }
    for(int i = 2; i < k; i++)
    {
        cin >>a;
        sizes[i] = a;
        if(a < sizes[mini])
        {
            maxi = mini;
            mini = i;
        }
        else if(a < sizes[maxi])
        {
            maxi = i;
        }
    }

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < sizes[i]; j++)
        {
            cin >>a;
            v[i].insert(a);
        }
    }

    vector<int> inter(sizes[mini]);
    vector<int> hh(sizes[mini]);
    vector<int>::iterator it = set_intersection(v[mini].begin(), v[mini].end(), v[maxi].begin(), v[maxi].end(), inter.begin());
    inter.resize(it - inter.begin());

    for(int i = 0; i < k; i++)
    {
        if(i != mini && i != maxi)
        {
            it = set_intersection(inter.begin(), inter.end(), v[i].begin(), v[i].end(), hh.begin());
            hh.resize(it - hh.begin());
            inter = hh;
        }
    }

    if(inter.size() == 0)
    {
        cout <<'x' <<endl;
    }
    else
    {
        cout <<inter[0] <<endl;
    }
}
