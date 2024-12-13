#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, m, result = -1;
vector<int> v;
bool dp[51][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s >> m;
    v.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];

    dp[0][s] = true;
    for (int i = 1; i <= n; i++)
    {
        int volumeDiff = v[i];
        for (int j = 0; j <= 1000; j++)
        {
            if (dp[i - 1][j])
            {
                int big = j + volumeDiff, small = j - volumeDiff;
                if (big <= m) dp[i][big] = true;
                if (0 <= small) dp[i][small] = true;
            }
        }
    }
    for (int i = 1000; i >= 0; i--)
    {
        if (dp[n][i])
        {
            result = i;
            break;
        }
    }
    cout << result;
    return 0;
}