#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{

    int arr[31][31];
    int n;
    cin>>n;

    int a = n * n;
    int lap = (n + 1) / 2;
    for(int i = 0; i < lap; i++)
    {
        for(int j = i; j <= (n - 1 - i); j++)
        {
            arr[i][j] = a;
            a--;
        }
        for(int j = (i + 1); j <= (n - 1 - i); j++)
        {
            arr[j][n - 1 - i] = a;
            a--;
        }
        for(int j = (n - 2 - i); j >= i; j--)
        {
            arr[n - 1 - i][j] = a;
            a--;
        }
        for(int j = (n - 2 - i); j >= (i + 1); j--)
        {
            arr[j][i] = a;
            a--;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout <<setw(5) <<arr[i][j];
        }
        cout<<endl;
    }

    return 0;
}
