#include<bits/stdc++.h>
using namespace std;

int n;
unsigned long long m;
vector<short> p;
vector<short> before, after;

/*
void bruteForce()
{
    for(int i = 0; i < n; i++)
    {
        before[i] = i;
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            after[j] = p[before[j]];
        }

        before = after;
    }
}
*/

void binaryLifting(int t)
{
    for(int i = 0; i < n; i++)
    {
        before[i] = i;
    }
    while(t > 0)
    {
        if(t % 2 == 1)
        {
            t--;
            for(int i = 0; i < n; i++)
            {
                after[i] = p[before[i]];
            }
            before = after;
            /*
            for(int i = 0; i < n; i++)
            {
                cout <<before[i] + 1 <<" ";
            }

            cout <<endl;
            */
        }


        t >>= 1;
        for(int i = 0; i < n; i++)
        {
            after[i] = p[p[i]];
        }
        p = after;
        /*
        for(int i = 0; i < n; i++)
        {
            cout <<before[i] + 1 <<" ";
        }

        cout <<endl;
        */
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    //cout <<SHRT_MAX;

    cin >>n >>m;

    p.resize(n);
    before.resize(n);
    after.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >>p[i];
        p[i]--;
    }

    binaryLifting(m);

    for(int i = 0; i < n; i++)
    {
        cout <<before[i] + 1 <<" ";
    }

    cout <<endl;
    /*
    bruteForce();

    for(int i = 0; i < n; i++)
    {
        cout <<before[i] + 1 <<" ";
    }
    cout <<endl;
    */
}
