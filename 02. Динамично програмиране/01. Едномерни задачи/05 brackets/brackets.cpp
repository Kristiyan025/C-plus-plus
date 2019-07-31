#include <iostream>
#include <vector>
using namespace std;



int main()
{
    string s;
    cin >>s;
    int n = s.size();
    int pos = n + 1;
    int razl = n - 1;
    int f[pos][razl];//f[i,d]
    //if(s[i]=='(') f[i,d]=f[i-1,d-1]
    //if(s[i]==')') f[i,d]=f[i-1,d+1]
    //if(s[i]=='?') f[i,d]=f[i-1,d-1]+f[i-1,d+1]
    for(int i = 0; i < pos; i++)
    {
        for(int j = 0; j < razl; j++)
        {
            f[i][j] = 0;
        }
    }
    f[0][0] = 1;

    for(int i = 1; i <pos; i++)
    {
        for(int j = 0; j < razl; j++)
        {
            if(s[i - 1] == '(' && j != 0)
               f[i][j] += f[i - 1][j - 1];
            else if(s[i - 1] == ')' && j != n - 2)
               f[i][j] += f[i - 1][j + 1];
            else if(s[i - 1] == '?')
            {
                if(j != 0) f[i][j] += f[i - 1][j - 1];
                if(j != n - 2) f[i][j] += f[i - 1][j + 1];
            }
        }
    }
    /*proverka
    for(int i = 0; i < pos; i++)
    {
        for(int j = 0; j < razl; j++)
        {
            cout <<f[i][j] <<" ";
        }
        cout <<endl;
    }/*
    cout <<f[n][0];

    return 0;
}
