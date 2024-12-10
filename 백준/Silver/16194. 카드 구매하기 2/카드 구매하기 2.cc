#include <iostream>

using namespace std;

int n, cur;
int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) dp[i] = 1e9;

    for (int i = 1; i <= n; i++)
    {
        cin >> cur;
        for (int j = i; j <= n; j++)
        {
            dp[j] = min(dp[j], dp[j - i] + cur);
        }
    }

    cout << dp[n];
    return 0;
}