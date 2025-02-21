#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, result;
vector<pair<int, int>> v;
int dp[21][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, {});
    for (int i = 1; i <= n; i++) cin >> v[i].first;
    for (int i = 1; i <= n; i++) cin >> v[i].second;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            if (j < v[i].first)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
            }
        }
    }
    
    for (int i = 1; i < 100; i++) result = max(dp[n][i], result);
    cout << result;
    return 0;
}