#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, m;
Dim2Vec<int> v, dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n + 1, vector<int>(m + 1, 0));
    dp.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + v[i][j];
        }
    }
    cout << dp[n][m];
    return 0;
}