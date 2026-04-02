class Solution {
template <typename T>
using Dim3Vec = vector<vector<vector<T>>>;
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        Dim3Vec<int> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(3, 0)));

        for (int i = 0; i <= m; ++i) {
            dp[i][0][0] = dp[i][0][1] = dp[i][0][2] = -1e9;
        }
        for (int i = 0; i <= n; ++i) {
            dp[0][i][0] = dp[0][i][1] = dp[0][i][2] = -1e9;
        }

        dp[1][1][0] = coins[0][0];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) {
                    continue;
                }
                int curCoin = coins[i - 1][j - 1];
                int maxCoinAvoid0 = max(dp[i - 1][j][0], dp[i][j - 1][0]);
                int maxCoinAvoid1 = max(dp[i - 1][j][1], dp[i][j - 1][1]);
                int maxCoinAvoid2 = max(dp[i - 1][j][2], dp[i][j - 1][2]);

                dp[i][j][0] = maxCoinAvoid0 + curCoin;

                dp[i][j][1] = (curCoin < 0) ? max(maxCoinAvoid0, maxCoinAvoid1 + curCoin)
                : maxCoinAvoid1 + curCoin;

                dp[i][j][2] = (curCoin < 0) ? max(maxCoinAvoid1, maxCoinAvoid2 + curCoin)
                    : maxCoinAvoid2 + curCoin;
            }
        }
        return max({dp[m][n][0], dp[m][n][1], dp[m][n][2]});
    }
};