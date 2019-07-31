#include <bits/stdc++.h>
using namespace std;

int N,K,a;

int main()
{
    cin >>N >>K;
    set <int> s;
    for (int i = 0; i < K; i++)
    {
        cin >>a;s.add(a);
    }
    sort( ch.begin(), ch.end() );
    ch.erase( unique( ch.begin(), ch.end() ), ch.end() );
    K = ch.size();
    vector<long long> s(N + 1, 0);
    s[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < K; j++)
        {
            if(i - ch[j] >= 0)
            {
                s[i] = (s[i] + s[i - ch[j]]) % 1000000007;
            }
        }
    }

    cout <<s[N] <<endl;
    return 0;
}
