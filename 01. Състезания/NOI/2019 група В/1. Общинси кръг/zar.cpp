#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

vector<int> m; // mnojestvo

int broi(int n)
{
    /* namira broq na cifrite */
    if(n == 1) return 1;
    int br=0;
    int p = n;
    while(p>1)
    {
        p/=10;
        br++;
        if(p == 1)
        {
            br++;
            break;
        }
    }
    return br;
}

string redica(int n)
{
    /* vrushta chisloto kato niz */
    string s = "";
    int p = n;
    do
    {
        char c = p % 10 + 48;
        s = c + s;
        p /= 10;

    }
    while(p != 0);
    return s;
}

int main()
{
    /* zabelqzvame che ako na purviq na zarcheto mu se e padnalo x to na vtoriq shte e 7 - x*/
    int n;
    cin >>n;
    int k;
    int a;
    int b;
    int c;
    cin >>a >>b;
    string bStr = redica(b);
    int bBroi= broi(b);
    for(int i = 0; i < 10000; i++)
    {
        int c = i * 7 - a;
        if(broi(c) != bBroi) break;
        else
        {
            string cStr = redica(c);
            int povtarqshti = 0;
            for(int j = 0; j < bStr.size(); j++)
            {
                if(bStr[j] == cStr[j]) povtarqshti++;
            }
            if(povtarqshti == 1 && a >= i && c >= i && c <= 6 * i) m.push_back(i);
        }
    }
    if(m.size() == 1) cout <<1 <<endl <<m[0];
    else
    {
        int i = 1;
        while(m.size() != 1 || i < n)
        {
            cin >>a >>b;
            string bStr = redica(b);
            int bBroi= broi(b);
            i++;
            for(int j = 0; j < m.size(); j++)
            {
                int c = i * 7 - a;
                if(broi(c) != bBroi) m[j] = -1;
                else
                {
                    string cStr = redica(c);
                    int povtarqshti = 0;
                    for(int l = 0; l < bStr.size(); l++)
                    {
                        if(bStr[l] == cStr[l]) povtarqshti++;
                    }
                    if(!(povtarqshti == 1 && a >= i && c >= i && c <= 6 * i)) m.erase(j,j); //m[j] = -1;
                }
            }
        }
        int newM = m.size();
        for(int l = 0; l < m.size(); l++)
        {
            if(m[l] == -1) newM--;
        }
        cout <<newM <<endl;
        for(int l = 0; l < m.size(); l++)
        {
            if(m[l] != -1) cout <<m[i] <<" ";
        }
    }

    return 0;
}
