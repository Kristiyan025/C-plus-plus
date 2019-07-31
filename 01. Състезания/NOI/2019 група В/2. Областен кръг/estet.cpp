#include<bits/stdc++.h>
using namespace std;

int main ()
{
 int n;
 cin >>n;
 vector<int> darveta(n);
 for(int i = 0; i < n; i++)
 {
     cin >>darveta[i];
 }
 vector<int> po_malki(n);
 po_malki[0] = 1;
 for(int i = 1; i < n; i++)
 {
     po_malki[i] = po_malki[i - 1];
     if(darveta[i - 1] < darveta[i])
        po_malki[i]++;
 }
 vector<int> po_golemi(n);
 po_golemi[n - 1] = 1;
 for(int i = n - 2; i >= 0; i--)
 {
     po_golemi[i] = po_golemi[i + 1];
     if(po_golemi[i + 1] < po_golemi[i])
        po_golemi[i]++;
 }


 int maxi = max(po_malki[n - 1], po_golemi[0]);

 for(int i = 0; i < n; i++)
 {
     int current = po_malki[i] + po_golemi[i];
     maxi = max(maxi, current);
 }
 cout <<maxi;

return 0;
}
