#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
 int n;
 cin >>n;
 if(n == 0)
 {
     cout <<n;
     return 0;
 }
 int f[n + 1][10];
 /*
 vsaka stoinost f[k][d] ot tozi masiv
 otgovarq na nachinite da
 se obrazuva redica s k simvola
 i posledna cifra d
 */
 for(int i = 1; i <= 9; i++)
 {
     f[1][i] = 1;
 }
 f[1][0] = 0;

 for(int k = 2; k <= n; k++)
 {
     f[k][0] = f[k - 1][4] + f[k - 1][6];
     f[k][1] = f[k - 1][6] + f[k - 1][8];
     f[k][2] = f[k - 1][7] + f[k - 1][9];
     f[k][3] = f[k - 1][4] + f[k - 1][8];
     f[k][4] = f[k - 1][0] + f[k - 1][3] + f[k - 1][9];
     f[k][5] = 0;
     f[k][6] = f[k - 1][0] + f[k - 1][1] + f[k - 1][7];
     f[k][7] = f[k - 1][2] + f[k - 1][6];
     f[k][8] = f[k - 1][1] + f[k - 1][3];
     f[k][9] = f[k - 1][2] + f[k - 1][4];
 }
 int sum = 0;
 for(int i = 0; i <= 9; i++)
 {
     sum += f[n][i];
 }
 cout <<sum;

return 0;
}
