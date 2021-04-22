// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];

        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends

// return length of longest strictly increasing subsequence

int longestSubsequence(int n, int a[])
{
    if(n == 0) return 0;

    vector<int> seqs;
    seqs.emplace_back(a[0]);
    for(int i = 1; i < n; i++)
    {
        if(a[i] < seqs[0])
        {
            seqs[0] = a[i];
        }
        else if(a[i] > seqs.back())
        {
            seqs.emplace_back(a[i]);
        }
        else
        {
            auto place = lower_bound(seqs.begin(), seqs.end(), a[i]);
            *place = a[i];
            cout <<"i = " <<i <<" pl = " <<(place - seqs.begin()) <<endl;
        }

        cout <<"seqs: ";
        for(auto s : seqs) cout <<s <<" ";
        cout <<endl;
    }

    return seqs.size();
}
