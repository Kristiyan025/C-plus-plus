#include<bits/stdc++.h>
using namespace std;

int main()
{
    for(int m = 0; m<20; m++)
    {
        vector<int> redica;
        int a;
        while(cin >>a)
        {
            redica.push_back(a);
        }
        int n = redica.size();
        int maxProduct = 0;
        int i1 = -1, i2 = -1, i3 = -1;
        for(int i = 1; i < n - 1; i++)
        {
            int maxiBefore = redica[0];
            int maxiAfter = redica[i];
            int j1 = -1, j2 = -1;
            for(int j = 1; j < i; j++)
            {
                if(maxiBefore < redica[j])
                {
                    maxiBefore = redica[j];
                    j1 = j;
                }
            }
            for(int j = i+1; j < n; j++)
            {
                if(maxiAfter < redica[j])
                {
                    maxiAfter = redica[j];
                    j2 = j;
                }
            }
            if(j1!=-1 && j2!=-1)
            {
                int current = maxiBefore * redica[i] * maxiAfter;
                if(maxProduct < current)
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
            cout <<i1 <<" " <<i2 <<" " <<i3;

        }

    }

    return 0;
}
