#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, t, p, result;
int dp[1500001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
    { 
        cin >> t >> p;
        dp[i] = max(dp[i - 1], dp[i]);
        if (i + t - 1 <= n)
        {
            dp[i + t - 1] = max(dp[i + t - 1], dp[i - 1] + p);
        }
    }
    cout << dp[n];
    return 0;
}