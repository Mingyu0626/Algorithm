#include <iostream>
#include <algorithm>

using namespace std; 

int n;
int v[101][101];
long long dp[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];
    
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 0) continue;
            int jump = v[i][j];
            int newX = i + jump;
            int newY = j + jump;
            if (newX < n) dp[newX][j] += dp[i][j];
            if (newY < n) dp[i][newY] += dp[i][j];
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}