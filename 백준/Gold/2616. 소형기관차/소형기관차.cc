#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
vector<int> v, pSum;
int dp[50001][4][2]; // [현재 인덱스][사용한 기관차 수][현재 인덱스 Pick 여부]

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, 0), pSum.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }
    cin >> m;

    int l = 0, r = 0, curSum = 0;
    while (r <= n)
    {
        curSum += v[r];
        if (r - l + 1 == m)
        {
            pSum[r] = curSum;
            curSum -= v[l];
            l++;
        }
        r++;
    }

    for (int i = m; i <= n; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
        }
        dp[i][1][1] = pSum[i];
        dp[i][2][1] = max(dp[i - m][1][0], dp[i - m][1][1]) + pSum[i];
        dp[i][3][1] = max(dp[i - m][2][0], dp[i - m][2][1]) + pSum[i];
    }

    cout << max(dp[n][3][1], dp[n][3][0]);
    return 0;
}
