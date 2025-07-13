#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
const int MOD = 1000000000;
long long dp[101][10][1024], result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 9; i++) 
    {
        dp[1][i][1 << i] = 1;
    }

    for (int length = 2; length <= n; length++) 
    {
        for (int lastNum = 0; lastNum <= 9; lastNum++) 
        {
            for (int mask = 0; mask <= 1023; mask++) 
            {
                int newMask = mask | (1 << lastNum);
                if (0 < lastNum)
                {
                    dp[length][lastNum][newMask] = 
                        (dp[length][lastNum][newMask] + dp[length - 1][lastNum - 1][mask]) % MOD;
                }
                if (lastNum < 9)
                {
                    dp[length][lastNum][newMask] = 
                        (dp[length][lastNum][newMask] + dp[length - 1][lastNum + 1][mask]) % MOD;
                }
            }
        }
    }

    for (int i = 0; i <= 9; i++) 
    {
        result = (result + dp[n][i][1023]) % MOD;
    }
    cout << result;
    return 0;
}