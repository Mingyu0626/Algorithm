#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

vector<unordered_set<int>> dp(9);

int solution(int N, int number) 
{
    int temp = 0;
    for (int i = 1; i <= 8; ++i)
    {
        temp = temp * 10 + N;
        dp[i].insert(temp);
        
        for (int j = 1; j < i; ++j)
        {
            for (int a : dp[i - j])
            {
                for (int b : dp[j])
                {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(b - a);
                    dp[i].insert(a * b);
                    if (a != 0)
                    {
                        dp[i].insert(b / a);
                    }
                    if (b != 0)
                    {
                        dp[i].insert(a / b);
                    }
                }
            }
        }
        if (dp[i].find(number) != dp[i].end())
        {
            return i;
        }
    }
    return -1;
}