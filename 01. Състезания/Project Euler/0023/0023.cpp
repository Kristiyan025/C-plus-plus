#include<bits/stdc++.h>
using namespace std;

const int maxi = 28123;

set<short> abundant;
bitset<maxi> pairSumAbundant = 0;
int res;

void binary_lifting(int a, int b)
{
    res = 1;
    while(b > 0)
    {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
}

int sumOfProperDivisors(int num)
{
    int number = num;
    unordered_map<int, int> factorization;
    for(int i = 2; num > 1; i++)
    {
        while(num % i == 0)
        {
            factorization[i]++;
            num /= i;
        }
    }

    int result = 1;
    for(auto p : factorization)
    {
        binary_lifting(p.first, p.second + 1);
        result *= (res - 1) / (p.first - 1);
    }

    result -= number;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    for(int i = 2; i < maxi; i++)
    {
        if(sumOfProperDivisors(i) > i) abundant.insert(i);
    }

    for(int i : abundant)
    {
        for(auto j = abundant.begin(); j != abundant.end() && *j + i < maxi; j++)
        {
            pairSumAbundant[i + *j] = 1;
        }
    }

    unsigned long long sum = 0;
    for(int i = 0; i < maxi; i++)
    {
        sum += !pairSumAbundant[i] ? i : 0;
    }

    cout <<sum <<endl;
}
