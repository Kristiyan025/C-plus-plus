#include<bits/stdc++.h>
using namespace std;

const int n = 10;
int pos = 1e6 - 1;

int fact[n];
int perm[n];

int main()
{
    ios_base::sync_with_stdio(false);

    fact[0] = 1;
    perm[0] = 0;
    for(int i = 1; i < n; i++)
    {
        fact[i] = i * fact[i - 1];
        perm[i] = i;
    }

    int curr = 0;
    int num;
    for(int i = n - 1; i >= 0; i--)
    {
        num = 0;
        while(curr + fact[i] <= pos) curr += fact[i], num++;
        swap(perm[i], perm[num]);
        sort(perm, perm + i);
    }

    for(int i = n - 1; i >= 0; i--) cout <<perm[i]; cout <<endl;
}
