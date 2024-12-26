#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, a, b, c, d;
long long dp[101][101];
bool cantPass[101][101][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c >> d;
        if (a != c) cantPass[min(a, c)][b][0] = true;
        else cantPass[a][min(b, d)][1] = true;
    }

    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0) continue;
            long long leftVal = 0;
            if (0 < i && !cantPass[i - 1][j][0]) leftVal = dp[i - 1][j];
            long long downVal = 0;
            if (0 < j && !cantPass[i][j - 1][1]) downVal = dp[i][j - 1];
            dp[i][j] = downVal + leftVal;
        }
    }
    cout << dp[n][m];
    return 0;
}