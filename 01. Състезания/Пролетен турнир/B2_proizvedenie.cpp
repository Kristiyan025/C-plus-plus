#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> redica;
    int a;
    while(cin >>a)
    {
        redica.push_back(a);
    }
    int n = redica.size();
    unsigned long long maxProduct = 0;
    int i1 = -1, i2 = -1, i3 = -1;
    for(int i = 1; i < n - 1; i++)
    {
        int maxiBefore = -1;
        int maxiAfter = redica[i];
        int j1 = -1, j2 = -1;
        for(int j = 0; j < i; j++)
        {
            if(redica[j] > maxiBefore && redica[j] < redica[i])
            {
                maxiBefore = redica[j];
                j1 = j;
            }
        }
        for(int j = i+1; j < n; j++)
        {
            if(redica[j] > maxiAfter && redica[j] > redica[i])
            {
                maxiAfter = redica[j];
                j2 = j;
            }
        }
        if(j1 != -1 && j2 != -1)
        {
            unsigned long long current = maxiBefore * redica[i] * maxiAfter;
            if(current > maxProduct)
            {
                maxProduct = current;
                i1 = j1;
                i2 = i;
                i3 = j2;
            }
        }

    }
    cout <<maxProduct <<endl;
    if(i1 != -1 && i2 != -1 && i3 != -1)
    {
        cout <<redica[i1] <<" " <<redica[i2] <<" " <<redica[i3] <<endl;
        cout <<i1 <<" " <<i2 <<" " <<i3 <<endl;


    }

    return 0;
}
