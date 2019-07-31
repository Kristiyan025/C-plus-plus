//https://action.informatika.bg/problems/87

#include <bits/stdc++.h>
using namespace std;

    int n,m;
bool isIn(string s, int pos, int pi, int pj, vector<string> bukvi)
{
    bool curr = false;
    if(pos == s.size()) return true;
    else
    {
        if( pi>0 && bukvi[pi - 1][pj] == s[pos])
        {
            curr == curr || isIn(s, pos + 1, pi - 1, pj, bukvi);
        }
        if( pj>0 && bukvi[pi][pj - 1] == s[pos])
        {
            curr == curr || isIn(s, pos + 1, pi, pj - 1, bukvi);
        }
        if( pi<n && bukvi[pi + 1][pj] == s[pos])
        {
            curr == curr || isIn(s, pos + 1, pi + 1, pj, bukvi);
        }
        if( pj<m && bukvi[pi][pj + 1] == s[pos])
        {
            curr == curr || isIn(s, pos + 1, pi, pj + 1, bukvi);
        }

        return curr;
    }
}

int main()
{
    cin >>n >>m;
    vector<string > bukvi(n);
    for(int i = 0; i < n; i++)
    {
        cin>>bukvi[i];
    }
    int k;
    cin >>k;
    string s;
    bool isY;
    for(int p = 0; p <k; p++)
    {
        cin >>s;
        isY = false;
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m;j++)
            {
                if(bukvi[i][j] == s[0] && isIn(s, 1, i,j,bukvi))
                {
                    isY = true;
                }
            }
        }
        if(isY) cout <<"Yes";
        else cout<<"No";
        cout <<endl;

    }

    return 0;
}
