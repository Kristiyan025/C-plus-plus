#include <bits/stdc++.h>
using namespace std;

int main()
{
cin.tie(NULL);
ios_base::sync_with_stdio(false);
string s;
cin>>s;
int n=s.size();
unsigned long long count = n;
for (int i = 0; i < n; i++)
{
    int strana=0;
    bool istr =true;
    for (int j = 1; j <= i; j++)
    {
        if(istr)
        {
            if(i+j < n && i-j >= 0 && s[i-j] == s[i+j])
            {
                //cout <<strana <<" " <<i <<" " <<j <<" " <<i-j <<" " <<i+j<<endl;
                strana++;
            }
            else
            {
                istr=false;
            }
        }
        else break;
    }
    //cout <<endl;
    count+=strana;
    strana =0;
    istr = true;
    for (int j = 0; j <= i; j++)
    {
        if(istr)
        {
            int j1 = j+1;
            if(i+j1 < n && i-j >=0&& s[i-j] == s[i+j1])
            {
                strana++;
            }
            else
            {
                istr=false;
            }
        }
        else break;
    }
    count+=strana;
}
cout <<count;

    return 0;
}
