#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

const char maxN = 101;
int n, m;
vector< vector<char> > g;
string letters, path;
vector<int> lst, nxt;

int main()
{
	ios_base::sync_with_stdio(false);

	int test[100];
	for(int i = 0; i < 100; i++)
    {
        test[i] = 0;
    }
	memset(test, 3, sizeof(test));
	for(int i = 0; i < 100; i++)
    {
        cout <<test[i] <<" ";
    }cout <<endl;

   	cin >>n >>m;
	g.resize(n);
	lst.resize(n);
	nxt.resize(n);

    cin >>letters;
	short a, b;
    for(char i = 0; i < m; i++)
	{
		cin >>a >>b;
		a--;
		b--;
        g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

    cin >>path;

	for(char i = 0; i < n; i++)
    {
        lst[i] = letters[i] == path[0];
	}

    for(char i = 1; i < path.size(); i++)
    {
        /*
        for(char j = 0; j < n; j++)
        {
            cout <<lst[j] <<" ";
        } cout <<endl;
        */
        nxt.assign(n, 0);
		for(char j = 0; j < n; j++)
		{
            if(letters[j] == path[i])
            {
                for(char k : g[j])
			    {
			        if(letters[k] == path[i - 1])
			        {
			            nxt[j] += lst[k];
                    }
		        }
            }
        }
		lst = nxt;
	}

	int ans = 0;
	for(char i = 0; i < n; i++)
	{
	    //cout <<lst[i] <<" ";
		ans += lst[i];
	}//cout <<endl;

	cout <<ans <<endl;
}

/*
6 8
POPOLO
1 2
2 3
3 3
3 4
4 5
5 6
6 1
2 5
POLO

*/
