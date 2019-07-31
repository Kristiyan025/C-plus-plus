#include <bits/stdc++.h>
using namespace std;


int main()
{
cin.tie(NULL);
cout.tie(NULL);
ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<unsigned long long> gol(n);
    vector<unsigned long long> br(n);

    for (int i = 0; i < n; i++)
    {
        cin >>gol[i];
        cin >>br[i];
    }
    unsigned long long m;
    cin>>m;
    char c;
    unsigned long long k;
    for (int i = 0; i < m; i++)
    {
        cin>>c >>k;
        if(c == '+'){
            bool ist=true;
            for (int j = 0; j < n; j++)
            {
                if(gol[j]==k)
                {
                    br[j]++;
                    ist=false;
                    break;
                }
            }
            if(ist)
            {
                gol.push_back(k);
                br.push_back(1);
                n++;
            }
        }
        else if(c == '-'){
            for (int j = 0; j < n; j++)
            {
                if(gol[j] == k && br[j] != 0)
                {
                    br[j]--;
                    break;
                }
            }
        }
        else{ //if(c == '?'){
            unsigned long long p=0;
            for (int j = 0; j < n; j++)
            {
                p+= k%gol[j]*br[j];

            }
            cout <<p <<endl;
        }
    }
    return 0;
}
