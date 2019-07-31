#include<bits/stdc++.h>
using namespace std;
bool tribonachi[1000000];
int main(){
int num_2nd_row,stupka;

int num1_1st_row,num2_1st_row,num3_1st_row;
cin >>num1_1st_row  >>num2_1st_row >>num3_1st_row >>num_2nd_row >>stupka;
tribonachi[num1_1st_row]=1;
tribonachi[num2_1st_row]=1;
tribonachi[num3_1st_row]=1;
 int novo_1st_row;
 while(num3_1st_row<1000000)
{
      novo_1st_row=num1_1st_row+num2_1st_row+num3_1st_row;
      tribonachi[novo_1st_row]=1;
      num1_1st_row=num2_1st_row;
      num2_1st_row=num3_1st_row;
      num3_1st_row=novo_1st_row;
}
int spiral=1;bool dali=false;
 while(num_2nd_row<1000000)
{
   if(tribonachi[num_2nd_row]==1) {
        cout <<num_2nd_row<<endl;;dali=true;
   break;return 0;
   }
   else
   {
     num_2nd_row+=2*spiral*stupka;
     spiral++;
   }
}



return 0;
}
