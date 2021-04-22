#include<iostream>
using namespace std;

const char* msg = "%02d)Move Disk #%d from %c to %c.\n";
int step;
void hanoi(int count, char from = 'A', char temp = 'B', char to = 'C')
{
    if(count == 1)
    {
        printf(msg, step++, 1, from, to);
        return;
    }

    hanoi(count - 1, from, to, temp);
    printf(msg, step++, count, from, to);
    hanoi(count - 1, temp, from, to);
}

int main()
{
    step = 1;
    int n = 0;
    while(scanf("%d", &n) == 1 && n < 1);
    hanoi(n);
}
