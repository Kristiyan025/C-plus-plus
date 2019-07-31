#include  <iostream>
#include <queue>

using  namespace  std;

int t(char p)
{
    if(p=='*' || p=='/') return 3;
    else if(p=='+' || p=='-') return 2;
    else if(p=='(') return 1;
}
int main()
{
cin.tie(NULL);
ios_base::sync_with_stdio(false);
 string s;
	queue<string> red;
	stack<char> sym;
	for(int i =0; i < s.length(); i++)
    {
        if(s[i]>='0' && s[i] <='9')
        {
            string ch=s[i];
            while(i + 1 < s.length() && s[i]>='0' && s[i] <='9')
            {
                i++;
                ch+=s[i];
            }
            red.push_back(ch);
        }
        else if(s[i] == '*' || s[i] == '/')
        {
            sym.push(s[i]);
        }
        else if(s[i] == '+' || s[i] == '-')
        {
            if(!sym.empty() && (sym.top() == '+' || sym.top() == '-'))
            {
                char p = sym.top();
                sym.pop();
                red.push(p);
            }
            else if()
            sym.push(s[i]);
        }
        else if(s[i] == '(')
        {
            sym.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(sym.top()!='(')
            {

                char c=sym.top();
                sym.pop();
                red.push(c);
            }

            sym.pop();
        }
    }






return 0;


}
