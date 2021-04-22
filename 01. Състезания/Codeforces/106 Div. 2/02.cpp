#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >>t;
    while(t--)
    {
        string s;
        cin >>s;

        bool isPoss = true;
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == '1' && s[i - 1] == '1')
            {
                for(int j = i + 2; j < s.length(); j++)
                {
                    if(s[j] == '0' && s[j - 1] == '0')
                    {
                        isPoss = false;
                        break;
                    }
                }

                if(!isPoss) break;
            }
        }

        if(isPoss) cout <<"YES\n";
        else cout <<"NO\n";
    }

}
