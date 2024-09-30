#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
long long dp[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;
    for (int i = 6; i <= 100; i++) dp[i] = dp[i - 1] + dp[i - 5];
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}


