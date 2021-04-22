/*
    2nd edition of Polish Olympiad 1996
    Problem: You are given an integer N <= 20,000.
    Find the smallest multiple of N that consists
    of digits 0 and 1 only (in decimal system).
    Additional Problem: use given set {d1, d2, dp}
    of digits and find the answer for m-th system
Example:
    Input:
7 2 10
0 1
    Output:
1001
    Explanation: 1001 is the smallest number int the 10-th
    (decimal) system which represent a multiple of 7 with only
    the digits 0 and 1
*/
#include<iostream>
#include<queue>
using namespace std;

string bfs(short n, vector<char>& digits, char m = 10)
{
    if(n == 1) return "1";
    const int maxN = 20001;
    string dp[maxN]; //remainder
    queue<short> q;
    dp[1] = "1";
    q.push(1);
    while(!q.empty())
    {
        short curr = q.front();
        q.pop();
        for(short digit : digits)
        {
            short next = (1 * m * curr + digit) % n;
            if(dp[next] == "")
            {
                dp[next] = dp[curr] + char('0' + digit);
                q.push(next);
            }

            if(next == 0) return dp[0];
        }
    }

    return "-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
    short n , p, m;
    cin >>n >>p >>m;
    vector<char> digits(p);
    for(int i = 0; i < p; i++)
    {
        cin >>digits[i];
        digits[i] -= '0';
    }
    cout <<bfs(n, digits, m) <<endl;
}
