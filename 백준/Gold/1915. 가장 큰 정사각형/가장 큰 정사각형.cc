#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, result;
vector<vector<char>> v;
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> v[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i][j] == '1')
            {
                dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
                result = max(result, dp[i][j]);
            }
        }
    }
    cout << result * result;
    return 0;
}