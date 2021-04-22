#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = 2e5;
int nums[maxN];
int main()
{
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >>t;
    while(t--)
    {
        cin >>n;
        for(int i = 0; i < n; i++)
        {
            cin >>nums[i];
        }
        int pLen, nLen;
        ll pSum = LLONG_MIN, nSum = LLONG_MIN;
        int pId = -1, nId = -1;
        for(int i = 0; i < n; i++)
        {
            int curr = nums[i];
            if(curr > 0)
            {
                if(pId == -1)
                {
                    if(nId == -1)
                    {
                        pId = i;
                        pLen = 1;
                        pSum = curr;
                    }
                    else
                    {
                        pId = i;
                        pLen = nLen + 1;
                        pSum = nSum + curr;
                    }
                }
                else
                {
                    if(nId == -1)
                    {
                        if(pLen == 1 && pSum < curr)
                        {
                            pId = i;
                            pSum = curr;
                        }
                    }
                    else
                    {
                        ll currSum = nSum + curr;
                        int currLen = nLen + 1;
                        if(pLen < currLen)
                        {
                            pLen = currLen;
                            pSum = currSum;
                            pId = i;
                        }
                        else if(pLen == currLen && pSum < currSum)
                        {
                            pSum = currSum;
                            pId = i;
                        }
                    }
                }
            }
            else
            {
                if(nId == -1)
                {
                    if(pId == -1)
                    {
                        nId = i;
                        nLen = 1;
                        nSum = curr;
                    }
                    else
                    {
                        nId = i;
                        nLen = pLen + 1;
                        nSum = pSum + curr;
                    }
                }
                else
                {
                    if(pId == -1)
                    {
                        if(nLen == 1 && nSum < curr)
                        {
                            nId = i;
                            nSum = curr;
                        }
                    }
                    else
                    {
                        ll currSum = pSum + curr;
                        int currLen = pLen + 1;
                        if(nLen < currLen)
                        {
                            nLen = currLen;
                            nSum = currSum;
                            nId = i;
                        }
                        else if(nLen == currLen && nSum < currSum)
                        {
                            nSum = currSum;
                            nId = i;
                        }
                    }
                }
            }
            /*
            cout <<"i: " <<i <<"\n";
            cout <<"pId: " <<pId <<" pSum: " <<pSum <<" pLen: " <<pLen <<"\n";
            cout <<"nId: " <<nId <<" nSum: " <<nSum <<" nLen: " <<nLen <<"\n";
            */
        }

        if(pLen > nLen && pId != -1) cout <<pSum <<"\n";
        else if(pLen < nLen && nId != -1) cout <<nSum <<"\n";
        else cout <<max(pSum, nSum) <<"\n";
    }

}
