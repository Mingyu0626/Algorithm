#include <iostream>
#include <cmath>

using namespace std;

int n, k, mod;
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    mod = pow(10, 9) + 3;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    cout << (dp[n - 1][k] + dp[n - 3][k - 1]) % mod;
    return 0;
}