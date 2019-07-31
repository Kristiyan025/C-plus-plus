#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
 int chisla[1000];

 int maxC(int n)
 {
     int maxChislo = chisla[0];
     for(int i = 1; i < n; i++)
     {
         if(chisla[i] > maxChislo)
         {
             maxChislo = chisla[i];
         }
     }
     return maxChislo;
 }

int main()
{
 ifstream input(".\\input.txt");
 ofstream output(".\\Output.txt");
 int t;
 input >>t;
 int n;
 int maxChislo;
 int count;
 for(int i = 1; i <= t; i++)
 {
     count = 0;
     input >>n;
     for(int j = 0; j < n; j++)
     {
         input >>chisla[j];
     }
     maxChislo =  maxC(n);
     for(int j = 1; j <= maxChislo; j++)
     {
         if(chisla[0] >= j) count ++;
         for(int l = 1; l < n; l++)
         {
             if(chisla[l - 1] < j && chisla[l] >= j)
             {
                 count++;
             }
         }
     }
     output <<"Case #" << i <<": " <<count <<endl;
 }

 input.close();
 output.close();

 return 0;
}
