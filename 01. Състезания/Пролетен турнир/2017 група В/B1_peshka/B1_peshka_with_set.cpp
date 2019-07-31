#include <bits/stdc++.h>
using namespace std;

int N,K,a;

int main()
{
    cin >>N >>K;
    set <int> s;
    for (int i = 0; i < K; i++)
    {
        cin >>a; s.insert(a);
    }
    K = s.size();
    vector<long long> p(N + 1, 0);
    p[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j:s)
        {
            if(i - j >= 0)
            {
                p[i] = (p[i] + p[i - j]) % 1000000007;
            }
        }
    }

    cout <<p[N] <<endl;
    return 0;
}
