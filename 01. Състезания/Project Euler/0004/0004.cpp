#include<bits/stdc++.h>
using namespace std;

const int maxi = 1e3;
const int mini = maxi / 10;


bool isPalindrome(int num)
{
    vector<short> digits;
    while(num > 0)
    {
        digits.emplace_back(num % 10);
        num /= 10;
    }

    int checks = digits.size() >> 1;
    for(int i = 0; i < checks; i++)
    {
        if(digits[i] != digits[digits.size() - i - 1]) return false;
    }

    return true;
}

int biggestPalindromeFrom2Integers()
{
    int maxI = 0, maxJ = 0, maxSum = maxI + maxJ;
    for(int i = maxi - 1; i >= mini; i--)
    {
        for(int j = i; j >= mini; j--)
        {
            if(i + j > maxSum && isPalindrome(i * j))
            {
                maxI = i;
                maxJ = j;
                maxSum = i + j;
            }
        }
    }

    return maxI * maxJ;
}

int main()
{
    ios_base::sync_with_stdio(false);


    cout <<biggestPalindromeFrom2Integers() <<endl;
}
