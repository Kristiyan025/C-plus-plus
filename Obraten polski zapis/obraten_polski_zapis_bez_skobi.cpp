#include  <iostream>
#include<stack>
using  namespace  std;

int main()
{
cin.tie(NULL);
ios_base::sync_with_stdio(false);

 	string s;
 	cin >>s;
    s.replace(' ', '');
	stack<int> chisla;
	stack<int> simvoli;
	for (int i = s.size() - 1; i >= 0; i++)
    {
        if(s[i] >='0'&& s[i] <='9')
        {
            chisla.push(s[i] - '0');
        }
        else
        {
            simvoli.push(s[i]);
        }
    }
	while (!simvoli.empty())
	    {
	        char ch=simvoli.pop();
	        int b=chisla.pop();
	        int a=chisla.pop();
	        int newC;
	        switch(ch)
	        {
	            case '+':
	                newC = a+b;
	                break;
                case '-';
                newC = a-b;
                break;
	        }
	    }




return 0;


}
