#include <iostream>
#include <vector>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int r, c, q;
Dim2Vec<int> v, dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> r >> c >> q;
    v.assign(r + 1, vector<int>(c + 1));
    dp.assign(r + 1, vector<int>(c + 1));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> v[i][j];
        }
    }
    dp[1][1] = v[1][1];
    for (int i = 2; i <= r; i++) dp[i][1] += dp[i - 1][1] + v[i][1];
    for (int i = 2; i <= c; i++) dp[1][i] += dp[1][i - 1] + v[1][i];

    for (int i = 2; i <= r; i++)
    {
        for (int j = 2; j <= c; j++)
        {
            dp[i][j] = v[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
  
    int r1, c1, r2, c2, num, sum;
    for (int i = 0; i < q; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        num = (r2 - r1 + 1) * (c2 - c1 + 1);
        sum = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
        cout << sum / num << '\n';
    }
    return 0;
}