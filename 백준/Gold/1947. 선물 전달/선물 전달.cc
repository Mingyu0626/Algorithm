#include <iostream>
#include <vector>

using namespace std;

int n;
const int MOD = 1000000000;
vector<long long> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    dp.assign(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1) % MOD;
    }
    cout << dp[n];
    return 0;
}