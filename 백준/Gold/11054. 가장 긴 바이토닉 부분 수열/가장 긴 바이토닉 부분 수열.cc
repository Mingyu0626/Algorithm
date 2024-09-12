#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, result;
int dp[2][1001];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, 0);
    fill(dp[0], dp[2], 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (v[i] > v[j]) dp[0][i] = max(dp[0][i], dp[0][j] + 1);
        }
    }
        
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = n; j > i; j--)
        {
            if (v[i] > v[j]) dp[1][i] = max(dp[1][i], dp[1][j] + 1);
        }
    }
        
    for (int i = 1; i <= n; i++) result = max(result, dp[0][i] + dp[1][i] - 1);
    cout << result;
    return 0;
}