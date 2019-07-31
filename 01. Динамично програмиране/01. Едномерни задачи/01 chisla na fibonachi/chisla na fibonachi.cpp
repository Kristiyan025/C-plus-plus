#include  <iostream>
#include  <cstdlib>
using  namespace  std;
/*
redica na Fibonachi
chislo (n)= chislo (n-1) + chislo (n-2)
*/
int fibonachi_Nth_number(int n)
{
    if(n==1 || n==2) return 1;
    else
    {
        int firstNumber = 1;
        int secondNumber = 1;
        for(int i=3; i <= n; i++)
        {
            int temp = secondNumber;
            secondNumber = secondNumber + firstNumber;
            firstNumber = temp;
        }
        return secondNumber;
    }
}

int main()
{
int n;
cin >>n;
cout <<fibonachi_Nth_number(n);

 return 0;
}
