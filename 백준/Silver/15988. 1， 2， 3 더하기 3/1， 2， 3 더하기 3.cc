#define YAHO 1000000009
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
long long dp[1000001][4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    dp[1][1] = 1;
    dp[2][1] = 1, dp[2][2] = 1;
    dp[3][1] = 2, dp[3][2] = 1, dp[3][3] = 1;
    for (int j = 4; j <= 1000000; j++)
    {
        dp[j][1] = (dp[j - 1][1] + dp[j - 1][2] + dp[j - 1][3]) % YAHO;
        dp[j][2] = (dp[j - 2][1] + dp[j - 2][2] + dp[j - 2][3]) % YAHO;
        dp[j][3] = (dp[j - 3][1] + dp[j - 3][2] + dp[j - 3][3]) % YAHO;
    }

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % YAHO << '\n';
    }
    return 0;
}