#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;
    int a, b;
    cin >>a;
    if(n == 1)
    {
        cout <<0 <<endl;
        return 0;
    }

    int temp;
    int counter = 0;
    for(int i = 1; i < n; i++)
    {
        cin >>b;
        temp = a - b;
        if(temp > 0)
        {
            counter++;
        }
        a = b;
    }

    cout <<counter <<endl;
}
