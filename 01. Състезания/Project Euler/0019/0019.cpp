#include<bits/stdc++.h>
using namespace std;

const char week = 7;
char today = (1 + 365) % week;
short sundays = 0;

vector<char> months =
{
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};

void modulise()
{
    for(int i = 0; i < months.size(); i++)
    {
        months[i] %= week;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);

    modulise();
    for(int y = 1901; y < 2001; y++)
    {
        bool isLeap = y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
        for(int i = 0; i < months.size(); i++)
        {
            sundays += today == 0;
            today += months[i];
            if(i == 1) today += isLeap;
            today %= week;
        }
    }

    cout <<sundays <<endl;
}
