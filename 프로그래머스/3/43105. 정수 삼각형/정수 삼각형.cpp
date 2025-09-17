#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int n = triangle.size();
    vector<vector<int>> dp;
    dp.assign(n, vector<int>());
    for (int i = 0; i < n; ++i)
    {
        dp[i].assign(i + 1, 0);
    }
    
    dp[0][0] = triangle[0][0];
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < dp[i].size(); ++j)
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
        }
    }
    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}