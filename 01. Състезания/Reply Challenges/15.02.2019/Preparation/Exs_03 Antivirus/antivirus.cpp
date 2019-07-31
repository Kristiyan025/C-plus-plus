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
 int lengths[4];
 int viruslength;
 string codes[4];
 bool f1,f2,f3;
 for(int i = 1; i <= t; i++)
 {
     input >>lengths[0] >>lengths[1] >>lengths[2] >>lengths[3];
     input >>viruslength;
     input >>codes[0] >>codes[1] >>codes[2] >>codes[3];
     string ednakvi[999];
     int js[999];
     int ls[999];
     int count = 0;
     for(int j = 0; j <= lengths[0] - viruslength + 1; j++)
     {
         string first = codes[0].substr(j,viruslength);
         f1 = false;
         for(int l = 0; l <= lengths[1] - viruslength + 1; l++)
         {
             string second = codes[1].substr(l,viruslength);
             if(first == second)
             {
                 ednakvi[count] = first;
                 js[count] = j;
                 ls[count] = l;
                 count++;
             }
         }
     }
     for(int j = 0; j < count; j++)
     {
         int third = codes[2].find(ednakvi[j]);
         int forth = codes[3].find(ednakvi[j]);
         if(third != -1 && forth != -1)
         {
             output <<"Case #" <<i <<": " <<js[j] <<" " <<ls[j] <<" " <<third <<" " <<forth <<endl;
             break;
         }
     }
 }

 input.close();
 output.close();

return 0;
}
