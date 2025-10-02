#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;

vector<vector<int>> dp(1001, vector<int>(51, 1e9));

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) 
{
    temperature += 10, t1 += 10, t2 += 10;
    dp[0][temperature] = 0;
    for (int i = 0; i < onboard.size() - 1; ++i)
    {
        for (int j = 0; j <= 50; ++j)
        {
            if (onboard[i] == 1 && (j < t1 || t2 < j))
            {
                continue;
            }
            
            // 1. 에어컨 끄고 온도 변화
            int nextT = j;
            if (j < temperature && j < 50)
            {
                nextT += 1;
            }
            else if (temperature < j && 0 < j)
            {
                nextT -= 1;
            }
            dp[i + 1][nextT] = min(dp[i][j], dp[i + 1][nextT]);
            
            
            // 2. 에어컨 끄고 온도 유지
            if (j == temperature)
            {
                dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
            }
            
            // 3. 에어컨 키고 온도 변화
            if (0 < j)
            {
                dp[i + 1][j - 1] = min(dp[i][j] + a, dp[i + 1][j - 1]);
            }
            
            if (j < 50)
            {
                dp[i + 1][j + 1] = min(dp[i][j] + a, dp[i + 1][j + 1]);
            }
            
            // 4. 에어컨 키고 온도 유지
            dp[i + 1][j] = min(dp[i][j] + b, dp[i + 1][j]);
        }
    }
    
    int result = 1e9;
    for (int i = 0; i <= 50; ++i)
    {
        if (!(onboard[onboard.size() - 1] == 1) || (t1 <= i && i <= t2))
        {
            result = min(result, dp[onboard.size() - 1][i]);
        }
    }
    return result;
}