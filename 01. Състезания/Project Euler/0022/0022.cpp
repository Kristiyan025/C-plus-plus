#include<bits/stdc++.h>
using namespace std;

vector<string> names;

int main()
{
    ios_base::sync_with_stdio(false);

    ifstream f("names.txt");
    string curr;
    char c;
    bool isReadingName = false;
    while(f >>c)
    {
        if(c == '"')
        {
            isReadingName = !isReadingName;
            if(!isReadingName)
            {
                names.emplace_back(curr);
                curr = "";
            }
        }
        else if(isReadingName)
        {
            curr += c;
        }
    }

    f.close();
    sort(names.begin(), names.end());
    unsigned long long res = 0;
    int current;
    for(int i = 0; i < names.size(); i++)
    {
        current = 0;
        for(char l : names[i]) current += l - 'A' + 1;
        res += (i + 1) * current;
    }

    cout <<res <<endl;
}
