#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >>t;
    while(t--)
    {
        int n, k1, k2, w, b;
        cin >>n >>k1 >>k2;
        cin >>w >>b;
        int W = k1 + k2, B = (n << 1) - W;
        if((w << 1) <= W && (b << 1) <= B) cout <<"YES\n";
        else cout <<"NO\n";
    }

}
