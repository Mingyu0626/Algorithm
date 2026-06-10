class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>> dp(n / 2, vector<vector<long long>>(3, vector<long long>(3, LLONG_MAX)));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) {
                    continue;
                }
                dp[0][i][j] = cost[0][i] + cost[n - 1][j];
            }
        }

        for (int i = 1; i < n / 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (j == k) {
                        continue;
                    }
                    dp[i][j][k] = min({
                        dp[i - 1][(j + 1) % 3][(k + 1) % 3], 
                        dp[i - 1][(j + 1) % 3][(k + 2) % 3],
                        dp[i - 1][(j + 2) % 3][(k + 1) % 3], 
                        dp[i - 1][(j + 2) % 3][(k + 2) % 3]}) + cost[i][j] + cost[n - i - 1][k];
                }
            }
        }

        long long result = LLONG_MAX;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result = min(result, dp[n / 2 - 1][i][j]);
            }
        }
        return result;
    }
};