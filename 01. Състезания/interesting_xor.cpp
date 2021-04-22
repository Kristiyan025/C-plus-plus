#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int t, c, maxi;
    int bound;
    cin >>t;
    while(t--)
    {
        cin >>c;
        maxi = 0;
        /*
        bound = c;
        bound |= bound >> 1;
        bound |= bound >> 2;
        bound |= bound >> 4;
        bound |= bound >> 8;
        bound |= bound >> 16;
        bound++; //2^d
        bound >>= 1; //2^(d - 1)
        for(int a = 0; a < bound; a++)
        {
            maxi = max(maxi, (c ^ a) * a);
        }
        //*/
        int sqrtC = floor(sqrt(c));
        int da = 1;
        int potC;
        for(;; sqrtC--, da++)
        {
            potC = sqrtC ^ (sqrtC + da);
            if(potC == c)
            {
                maxi = sqrtC * (sqrtC + da);
                break;
            }
            potC = sqrtC ^ (sqrtC + da + 1);
            if(potC == c)
            {
                maxi = sqrtC * (sqrtC + da + 1);
                break;
            }
        }
        cout <<maxi <<endl;
    }
}
