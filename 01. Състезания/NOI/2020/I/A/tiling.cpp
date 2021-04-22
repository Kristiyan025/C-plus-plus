#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
unsigned long long n;
int t;
int dp1()
{
    if(n == 1) return 1;
    int f0 = 1, f1 = 1, fn;
    for(int i = 2; i <= n; i++)
    {
        fn = (f1 + f0) % mod;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}

int dp2()
{
    if(n % 3 != 0) return 0;
    int f = 1;
    for(int i = 3; i <= n; i+= 3)
    {
        f = (2 * f) % mod;
        //cout <<f <<endl;
    }
    return f;
}

int dp3()
{
    if(n < 3) return n;
    int f0 = 1, f1 = 1, fn;
    int f = 0;
    for(int i = 2; i <= n; i++)
    {
        fn = ((f1 + f0) % mod + 2 * f % mod) % mod;
        f = (f + f0) % mod;
        f0 = f1;
        f1 = fn;
        //cout <<fn <<" " <<f <<endl;
    }
    return fn;
}

int tryIt(int a, int b)
{
    n = a;
    t = b;
    int res;
    switch(t)
    {
        case 1:
            res = dp1();
            break;
        case 2:
            res = dp2();
            break;
        case 3:
            res = dp3();
            break;
    }
    //cout <<res <<endl;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >>n >>t;
    /*
    for(int i = 1; i <= 100; i++)
    {
        cout <<i <<" ";
        for(int j = 1; j < 4; j++)
        {
            cout <<tryIt(i, j) <<" ";
        }
        cout <<endl;
    }
    */
    cout <<tryIt(n, t) <<endl;
}

/*
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
unsigned long long n;
int t;
vector<int> dp, partial;

void dp1()
{
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
    }
}

void dp2()
{
    for(int i = 3; i <= n; i+= 3)
    {
        dp[i] = 2 * dp[i - 3];
        dp[i] %= mod;
    }
}

void dp3()
{
    partial.assign(n + 1, 0);
    partial[0] = dp[0];
    partial[1] = partial[0] + (dp[1] = 1);
    if(dp.size() > 2) partial[2] = dp[1] + (dp[2] = 2);

    for(int i = 3; i <= n; i++)
    {
        dp[i] = ((dp[i - 1] + dp[i - 2]) % mod + 2 * partial[i - 3] % mod) % mod;

        partial[i] = (partial[i - 1] + dp[i]) % mod;
    }
}

int tryIt(int a, int b)
{
    n = a, t = b;
    dp.assign(n + 1, 0);
    dp[0] = 1;

    switch(t)
    {
    case 1:
        dp1();
        break;
    case 2:
        dp2();
        break;
    case 3:
        dp3();
        break;
    }

    /*
    for(int i = 0; i < dp.size(); i++)
    {
        cout <<dp[i] <<" ";
    }

    cout <<endl;
    for(int i = 0; i < dp.size(); i++)
    {
        cout <<partial[i] <<" ";
    }

    cout <<endl;
    *

    return dp[n];

}

int main()
{
    ios_base::sync_with_stdio(false);

    for(int i = 1; i <= 100; i++)
    {
        cout <<i <<" ";
        for(int j = 1; j < 4; j++)
        {
            cout <<tryIt(i, j) <<" ";
        }
        cout <<endl;
    }
}
*/
