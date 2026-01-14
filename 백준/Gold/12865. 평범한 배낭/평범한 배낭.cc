#include <iostream>
#include <vector>

using namespace std;

int n, k, w, v;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    dp.assign(k + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> w >> v;
        for (int j = k; j >= 0; --j) {
            dp[j] = (w <= j) ? max(dp[j], dp[j - w] + v) : dp[j];
        }
    }
    cout << dp[k];
    return 0;
}