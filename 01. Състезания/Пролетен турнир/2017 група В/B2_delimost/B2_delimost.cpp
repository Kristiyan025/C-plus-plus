#include <bits/stdc++.h>
using namespace std;
int N,Q;

long long sum(vector<long long> p)
{
	long long sum = 0;
	for(int i = 1;  i <= Q; i++)
	{
		sum  = (sum + p[i]) % 1000000007;
	}
	return sum;
}

int main()
{
	cin >>N >>Q;
	vector< vector<int> > d(Q+1);  //delimostite na vsqko chislo

	for(int i = 1; i <= Q; i++)
	{
		for(int j = 1; j < i; j++)
		{
		    if(j % i == 0)
		    {
		        d[i].push_back(j);
		        d[j].push_back(i);
		    }
	    }
        for(int j = i + 1; j <= Q; j++)
        {
            if(j % i == 0)
            {
                d[i].push_back(j);
                d[j].push_back(i);
            }
        }
	}

	vector<long long> prev (Q+1, 1), curr(Q+1, 0), temp(Q+1, 0);
    for(int i = 2; i <= N; i++)
	{
		for(int j = 1; j <= Q; j++)
		{
		    for(int t = 0; t <d[j].size(); t++)
		    {
			    curr[d[j][t]] =  (curr[d[j][t]] + prev[j]) % 1000000007;
		    }
		}
		prev = curr;
		curr = temp;
	}

	cout <<sum(prev) <<endl;
	return 0;

}

