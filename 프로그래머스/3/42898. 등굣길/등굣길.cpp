#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) 
{
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    unordered_set<int> us;
    
    for (int i = 0; i < puddles.size(); ++i)
    {
        us.insert(puddles[i][0] * 100 + puddles[i][1]);
    }
    
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1 && j == 1) continue;
            
            if (us.find(j * 100 + i) == us.end())
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}