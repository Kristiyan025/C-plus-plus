#include<bits/stdc++.h>
using namespace std;


template<typename T>
int foo(T arr[], int length)
{
    if(length == 0) return -1;
    int minimum = 0;
    for(int i = 1; i < length; i++)
    {
        if(arr[i] < arr[minimum])
        {
            minimum = i;
        }
    }

    return minimum;
}

int main()
{ //Testing
    int arr[] = {7, 8, 3, 4};
    int mini = foo<int>(arr, 4);
    cout <<mini <<endl; //2
}
