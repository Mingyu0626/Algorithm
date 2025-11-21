#include <iostream>
#include <vector>

using namespace std;

int t, n, m;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (0 < t--)
    {
        cin >> n;
        v.clear(), v.assign(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        cin >> m;
        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = v[i]; j <= m; ++j)
            {
                dp[j] = dp[j] + dp[j - v[i]];
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}
