#include<bits/stdc++.h>
using namespace std;

const int sz = 1e3;

short f1[sz], f2[sz], fn[sz];
int i, carry;

void calc()
{
    i = fn[0] = carry = 0;
    while(!(f1[i] == 0 && f2[i] == 0))
    {
        fn[i] = f1[i] + f2[i] + carry;
        carry = fn[i] / 10;
        fn[i] %= 10;
        i++;
    }

    fn[i] = carry;
}

int fibonacci()
{
    f1[0] = f2[0] = 1;
    int index = 2;
    while(fn[sz - 1] == 0)
    {
        calc();
        index++;
        copy(begin(f2), end(f2), begin(f1));
        copy(begin(fn), end(fn), begin(f2));
        //cout <<index <<" "; for(int j = sz - 1; j >= 0; j--) cout <<fn[j]; cout <<endl;
    }

    return index;
}

int main()
{
    ios_base::sync_with_stdio(false);

    //cout <<fibonacci() <<endl;


    unsigned long long a = 1, b = a, c;
    for(int i = 3; i < INT_MAX; i++)
    {
        c = a + b;
        a = b;
        b = c;
        cout <<c <<endl;
    }
}
