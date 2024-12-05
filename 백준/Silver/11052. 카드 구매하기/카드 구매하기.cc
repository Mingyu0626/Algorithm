#include <iostream>
#include <algorithm>

using namespace std;

int n, p, dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        for (int j = i; j <= n; j++)
        {
            dp[j] = max(dp[j - i] + p, dp[j]);
        }
    }
    cout << dp[n];
    return 0;
}