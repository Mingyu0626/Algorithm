#include <iostream>
#include <vector>

using namespace std;

int n, m, t, a, b;
vector<int> dp;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n + 1, 0), dp.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        dp[a] += b;
    }

    cout << dp[1] << ' ';
    for (int i = 2; i <= n; ++i)
    {
        int bossNum = v[i];
        dp[i] += dp[bossNum];
        cout << dp[i] << ' ';
    }
}