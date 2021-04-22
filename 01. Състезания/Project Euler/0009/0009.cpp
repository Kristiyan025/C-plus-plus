#include<bits/stdc++.h>
using namespace std;

const int sum = 1000;

int main()
{
    ios_base::sync_with_stdio(false);
    int c;
    for(int a = 1; a <= sum / 3; a++)
    {
        for(int b = a + 1; b <= sum - a; b++)
        {
            c = sum - a - b;
            if(a * a + b * b == c * c)
            {
                cout <<a * b * c <<endl;
            }
        }
    }

}
