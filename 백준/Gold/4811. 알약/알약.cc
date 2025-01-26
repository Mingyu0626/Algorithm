#include <iostream>

using namespace std;

int n;
long long dp[31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= 30; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    while (cin >> n)
    {
        if (n == 0) break;
        cout << dp[n] << '\n';
    }
    return 0;
}