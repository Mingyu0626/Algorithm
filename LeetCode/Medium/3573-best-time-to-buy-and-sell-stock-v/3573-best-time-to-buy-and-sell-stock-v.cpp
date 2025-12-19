class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k + 1, vector<long long>(3, -1)));
        for (int i = 0; i <= k; ++i) {
            dp[n][i][0] = 0, dp[n][i][1] = INT_MIN, dp[n][i][2] = INT_MIN;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j][0] = dp[i + 1][j][0];
                if (0 < j) {
                    dp[i][j][0] = max(dp[i][j][0], max(-prices[i] + dp[i + 1][j][1], prices[i] + dp[i + 1][j][2]));
                }

                dp[i][j][1] = dp[i + 1][j][1];
                if (0 < j) {
                    dp[i][j][1] = max(dp[i][j][1], prices[i] + dp[i + 1][j - 1][0]);
                }

                dp[i][j][2] = dp[i + 1][j][2]; 
                if (0 < j) {
                    dp[i][j][2] = max(dp[i][j][2], -prices[i] + dp[i + 1][j - 1][0]);
                }
            }
        }
        return dp[0][k][0];
    }
};