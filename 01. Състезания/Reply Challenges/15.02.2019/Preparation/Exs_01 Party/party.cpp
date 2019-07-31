#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


int main()
{
 ifstream input(".\\input.txt");
 ofstream output(".\\Output.txt");
 int t;
 input >>t;

 int n;
 int obshto;
 int current;

 for(int i = 1; i <= t; i++)
 {
     input >>n;
     obshto = 0;
     for(int j = 0; j < n; j++)
     {
         input >>current;
         if(current > 0)
         {
             obshto += current;
         }
     }
     output <<"Case #" <<i <<": " <<obshto <<endl;
 }
 input.close();
 output.close();

return 0;
}
