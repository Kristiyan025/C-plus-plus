#include<bits/stdc++.h>
using  namespace  std;

int N,K;

int cena = 0;
vector<int> gotovi;
gotovi.push_back(0);

void func(vector< vector<int> > categories)
{
    for(int m = 0; m<gotovi.size();m++)
    {
        int curr = gotovi[m];
        int currCena = K+1;
        vector<int> ednakvi;
        vector<int> index;
        vector<int> newV(N);
        for(int p = 0; p<N;p++)
        {
            if(p!=m)
            newV[p] = p;
        }
        for(int i = 0; i < newV.size(); i++)
        {

            for(int j = 0; j< categories[i].size(); j++)
            {
                for(int l = 0; l< categories[curr].size(); l++)
                {
                    if(categories[i][j] == categories[curr][l])
                    {
                        ednakvi.push_back(categories[curr][l]);
                        index.push_back(i);
                    }
                }
            }

            int maxi = ednakvi.max();
            currCena = max(currCena, maxi);
            if(currCena!=K+1)
            {
                cena+=currCena;
                gotovi.push_back()
            }
        }
    }

}


int main()
{
 cin >>N >>K;
 vector< vector<int> > categories(N);
 for(int i = 0; i < N; i++)
 {
     int count;
     cin <<count;
     for(int j = 0; j < count; j++)
     {
         int chislo;
         cin <<chislo;
         categories[i].push_back(chislo);
     }
 }


return 0;
}
