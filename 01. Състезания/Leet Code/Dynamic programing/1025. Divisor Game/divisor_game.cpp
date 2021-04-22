class Solution {
public:
    bitset<1001> used = 0, visited = 0;
    bool divisorGame(int N, bool isAlice = true)
    {
        if(visited[N])
        {
            return used[N];
        }

        if(N == 1)
        {
            return used[1] = false;
        }

        bool result = false;
        for(int i = 1; i < N ; i++)
        {
            if(N % i == 0)
            {
                result = result || !divisorGame(N - i, !isAlice);
            }
        }

        visited[N] = true;
        return used[N] = result;
    }
};
