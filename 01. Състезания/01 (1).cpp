#include<bits/stdc++.h>
using namespace std;

const int maxN =1e5 + 1;
//const long long maxSumFear = 1LL * 1e10 + 1;
int n, k;
int A[maxN];
vector<unsigned long long> sums[maxN];


/*unsigned long long dynamic_programming(int crab, int pos, int p)
{
    unsigned long long group_fear = 0;
    if(crab != 0 && p > 0) group_fear = sums[crab - p][crab - 1];

    if(crab == n)
    {
        return group_fear * (p - 1);
    }
    if(pos == k && crab < n)
    {
        return 0;
    }

    long long& cell = dp[crab][pos][p];
    if(cell != -1)
    {
        return cell;
    }
    long long f1 = dynamic_programming(crab + 1, pos, p + 1);
    f1 = f1 == 0 ? ULONG_LONG_MAX : f1;
    long long f2 = dynamic_programming(crab + 1, pos + 1, 0) + 1LL * (group_fear + A[crab]) * p;
    f2 = f2 == 0 ? ULONG_LONG_MAX : f2;
    cell = min(f1, f2);
    return cell = (cell == ULONG_LONG_MAX ? 0 : cell);
}*/

unsigned long long dynamic_programming()
{
    vector< vector<unsigned long long> > dp, dp_old;
    dp.resize(n);
    dp_old.resize(n);
    for(int pos = 0; pos < k; pos++)
    {
        dp_old[pos].assign(k, ULONG_LONG_MAX);
    }

    dp_old[0][0] = 0;

    for(int crab = 1; crab < n - 1; crab++)
    {
        for(int j = 0; j < k; j++)
        {
            for(int g = 0; g < n; g++)
            {
                cout <<dp_old[j][g] <<" ";
            }
            cout <<endl;
        }
        for(int j = 0; j < n; j++)
        {
            dp[j].assign(k, ULONG_LONG_MAX);
        }
        for(int pos = 0; pos < k; pos++)
        {cout <<1;
            for(int p = 0; p < crab; p++)
            {
                int group_fear = 0;
                if(p > 0) group_fear = sums[crab - p][crab - 1];

                unsigned long long tt = 0;
                unsigned long long& cellA = dp_old[pos][p];
                unsigned long long& cellB = p + 1 < k ? dp[pos][p + 1] : tt;
                cellB = min(cellB, cellA);
                unsigned long long& cellC = pos + 1 < n ? dp[pos + 1][0] : tt;
                cellC = min(cellC, cellA + 1LL * (group_fear + A[crab]) * p);
            }
        }
        dp_old = dp;
    }
    unsigned long long minimum = ULONG_LONG_MAX;
    for(int pos = 0; pos < k; pos++)
    {
        for(int p = 0; p < n; p++)
        {
            minimum = min(minimum, dp[pos][p]);
        }
    }

    return minimum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >>n >>k;
    if(n == k)
    {
        cout <<0 <<endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        cin >>A[i];
        sums[i].assign(n, 0);
    }
    for(int i = 0; i < n; i++)
    {
        sums[i][i] = A[i];
        for(int j = i + 1; j < n; j++)
        {
            sums[i][j] = sums[i][j - 1] + A[j];
        }
    }
    cout <<dynamic_programming() <<endl;
    return 0;
}
