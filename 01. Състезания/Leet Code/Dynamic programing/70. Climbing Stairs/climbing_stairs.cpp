class Solution {
public:
    int climbStairs(int n)
    {
        if(n == 1) return 1;
        //fibonacci
        int f1 = 1, f2 = 2, f3;
        for(int i = 3; i <= n; i++)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }

        return f2;
    }
};
