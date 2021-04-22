#include<bits/stdc++.h>
using namespace std;

using number = char;

set<number> ans;

int n;
vector<number> digits, signs;

void combine_signs(number index = 0)
{
    if(index == n - 1)
    {
        //all signs have been chosen

    }
    for(number i = 10; i < 14; i++)
    {
        signs[index] = i;
        combine_signs(index + 1);
    }
}
bool same_prec(number op1, number op2)
{
    return (op1 < 12 && op2 < 12) ||
           (op1 > 11 && op2 > 11);
}

number evaluate()
{
    vector<number> expr(2 * n - 1);
    number index = 0;
    stack<number> s;
    for(number i = 0; i < 2 * n - 1; i++)
    {
        if(i % 2 == 0) //digit
        {
            expr[index++] = digits[i >> 1];
        }
        else //sign
        {
            number sign = signs[i >> 1];
            if(sign > 11) //high precedence
            {
                expr[index++] = sign;
            }
            else //low precedence
            {
                s.push(sign);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >>n;
    digits.resize(n);
    signs.resize(n - 1);
    for(number i = 0; i < n; i++)
    {
        cin >>digits[i];
        digits[i] -= '0';
    }

}
