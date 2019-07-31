#include <bits/stdc++.h>
using namespace std;
/*
 edna redica shte narichame stroga ako otgovarq na slednite usloviq:

 * sudurja samo A i B
 * moje da se razdeli na podredici ili samo s A ili samo s B,
   kato ne moje dve podredici ot edin i sushti tip da sa edna do druga
 * podredicite samo s A sa s cheten broi A-ta, a tezi samo s B - s necheten broi B-ta


 Po dadeno chislo n da se nameri broq na vsichki n-cifreni strogi redici

*/

int main()
{
 int n;
 cin >>n;
 /*
   za vsqko chislo i ot 1 do n shte pazim stoinosti:
   * a[i] - broq na i-cifrenite redici zavurshvashti na M
   * b[i] - broq na i-cifrenite redici zavurshvashti na A
 */
 vector<int> a(n);
 vector<int> b(n);
 /*
   ako a[i] e broq na redicite ot posocheniq vid =>
      shte zavurshvat ...M M M ili ...A A M => a[i] = a[i - 2] + b[i - 1]
   ako b[i] e broq na redicite ot posocheniq vid =>
      shte zavurshvat ...B A A ili ...A A A => b[i] = a[i - 2] + b[i - 2]
 */
 a[0] = 1;
 b[0] = 0;
 a[1] = 0;
 b[1] = 1;
 for(int i = 2; i < n; i++)
 {
     a[i] = a[i - 2] + b[i - 1];
     b[i] = a[i - 2] + b[i - 2];
 }
 for(int i = 0; i < n; i++)
 {
    cout <<a[i] <<" " <<b[i] <<endl;
 }
 cout <<a[n - 1] + b[n - 1] <<endl;

return 0;
}
