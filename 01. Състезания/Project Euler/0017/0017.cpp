#include<bits/stdc++.h>
using namespace std;

using vs = vector<string>;

vs digCounts =
{
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

vs f10to20 =
{
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
};

vs tenths =
{
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

string conjunction = "and";
string hundred = "hundred";
string thausand = "oneThousand";



int main()
{
    ios_base::sync_with_stdio(false);

    int sumDig = 0;
    for(string n : digCounts) sumDig += n.length();
    int sumf10t20 = 0;
    for(string n : f10to20) sumf10t20 += n.length();
    int sumTenths = 0;
    for(string n : tenths) sumTenths += n.length();

    int sum = 9 * sumDig;
    sum += sumf10t20;
    sum += 10 * sumTenths;
    sum *= 10;
    sum += 100 * sumDig + 9 * 100 * hundred.length();
    sum += 9 * 99 * conjunction.length();
    sum += thausand.length();

    cout <<sum <<endl;
}
