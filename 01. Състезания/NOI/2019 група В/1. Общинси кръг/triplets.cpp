#include <iostream>
#include <cstdlib>
using namespace std;
int b1[200];
int b2[200];
int b3[200];
int count=-1;
/*  v tezi massivi shte se pazqt stranite na vsicki triugulnici otgovarqshti na dadenite usloviq */

bool dali(int a1, int a2, int a3)
{
    if(!((a1<a2+a3) && (a2<a1+a3) && (a3<a1+a2))) return false;
    else if(a1==a2 || a2==a3 || a3==a1) return false;
    else
    {
        for(int p = 0; p <= count; p++)
        {
            if((a1 == b1[p] && a2 == b2[p] && a3 == b3[p]) ||
                (a1 == b1[p] && a2 == b3[p] && a3 == b2[p]) ||
                (a1 == b2[p] && a2 == b1[p] && a3 == b3[p]) ||
                (a1 == b2[p] && a2 == b3[p] && a3 == b1[p]) ||
                (a1 == b3[p] && a2 == b1[p] && a3 == b2[p]) ||
                (a1 == b3[p] && a2 == b2[p] && a3 == b1[p]))
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    int n;
    int a[200];
    int broi = 0;
    cin >>n;
    for(int i = 0; i < n; i++)
    {
        cin >>a[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int l = 0; l < n; l++)
            {
                if(i==j || j==l || i==l) continue;
                else if(dali(a[i],a[j],a[l]))
                {
                     broi++;
                     count++;
                     b1[count] = a[i];
                     b2[count] = a[j];
                     b3[count] = a[l];
                }
            }
        }
    }
    cout <<broi;

    return 0;
}
