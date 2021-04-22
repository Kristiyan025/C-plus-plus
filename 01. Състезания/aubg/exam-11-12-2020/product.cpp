#include<bits/stdc++.h>
using namespace std;

class Product
{
private:
    string id;
    string name;
    float* price;
    string category;
public:
    bool operator<=(const Product& p)
    {
        return this->price <= p.price;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);



}
