#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v, dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.assign(n, 0), dp.assign(k + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (k < v[i]) continue;
        int c = v[i];
        for (int j = c; j <= k; j++)
        {
            if (dp[j - c] != 1e9) dp[j] = min(dp[j], dp[j - c] + 1);
        }
    }
    if (dp[k] != 1e9) cout << dp[k];
    else cout << -1;
    return 0;
}