#include<bits/stdc++.h>
using namespace std;

const int maxN = 800;
int n, k;

unsigned long long counter = 0;

void bruteForce(int remaining, int sz = 1, int nesting = 0)
{
    if(remaining == 0 && nesting == k)
    {
        //cout <<sz <<" " <<nesting <<endl;
        counter++;
        return;
    }
    if(sz > n - k + 1) return;
    if(nesting == k && remaining != 0) return;

    for(int i = remaining, j = nesting; i >= 0 && j <= k; i -= sz, j++)
    {
        //cout <<"r: " <<remaining<<" sz: "<<sz <<" ns: " <<nesting <<" i: " <<i <<" j: " <<j <<endl;
        bruteForce(i, sz + 1, j);
    }
}

unsigned long long helper(int np, int kp)
{
    n = np, k = kp;
    if(k > n) return 0;
    if(k == n || k == 1) return 1;

    counter = 0;
    bruteForce(n);
    return counter;
}

int main()
{
    ios_base::sync_with_stdio(false);
    /*
    cin >>n >>k;

    bruteForce(n);
    cout <<counter <<endl;
    */
    ofstream f;
    f.open(".\\ans.txt");
    f <<"{" <<endl;
    for(int i = 1; i < 801; i++)
    {
        f <<"{ ";
        for(int j = 1; j <= i; j++)
        {
            f <<helper(i, j) <<", ";
        }
        f <<"}" <<endl;
    }
    f <<"}," <<endl;
    f.close();
}
