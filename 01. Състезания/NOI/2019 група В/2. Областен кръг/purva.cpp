#include <iostream>
#include <cstdlib>
#include<vector>
using  namespace  std;

int main()
{
    /*  Vhodni Danni  */
 int n;
 cin >>n;
 vector<int> darveta(n);
 for(int i = 0; i< n; i++)
 {
     cin >>darveta[i];
 }

 int precheshti = n;
 for(int i = 0; i<n; i++)
 {
     // za vseki naklon ima 2 vida greshni darveta :
     // darvetata predi basovoto darvo i
     // darveta sled basovoto darvo

     //drveta[i] e basovoto darvo za purvi variant
     int firstBase = darveta[i];
     //drveta[i] e basovoto darvo za vtori variant
     int secondBase = darveta[i];

     int firstPredi = 0;
     int firstSled = 0;
     int secondPredi = 0;
     int secondSled = 0;
     // int thirdPredi = 0; ne e nugno zashtoto e sahtoto kato firstPredi
     // int thirdSled = 0; ne e nugno zashtoto e sahtoto kato secondSled

             /*  Predi basata  */
     for(int j = i - 1; j >= 0; j--)
     {
         if(darveta[j] < firstBase) firstBase = darveta[j];
         else firstPredi++;
         if(darveta[j] > secondBase) secondBase = darveta[j];
         else secondPredi++;
     }

     firstBase = darveta[i];
     secondBase = darveta[i];
             /*  Sled basata  */
     for(int j = i + 1; j < n; j++)
     {
         if(darveta[j] > firstBase) firstBase = darveta[j];
         else firstSled++;
         if(darveta[j] < secondBase) secondBase = darveta[j];
         else secondSled++;
     }

     int firstNoNeeded = firstPredi + firstSled;
     int secondNoNeeded = secondPredi + secondSled;
     int thirdNoNeeded = firstPredi + secondSled;
     int nai_malko = min(firstNoNeeded, min(secondNoNeeded, thirdNoNeeded));
     precheshti = min(precheshti, nai_malko);
 }

 cout <<n - precheshti;
 return 0;
}
