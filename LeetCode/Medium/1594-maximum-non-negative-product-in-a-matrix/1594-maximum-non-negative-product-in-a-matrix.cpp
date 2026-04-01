class Solution {
using pllll = pair<long long, long long>;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1000000007;
        int m = grid.size(), n = grid[0].size();
        vector<vector<pllll>> dp(m + 1, vector<pllll>(n + 1, {LLONG_MAX, LLONG_MIN}));

        if (grid[0][0] == 0) {
            return 0;
        }
        dp[1][1].first = (0 < grid[0][0]) ? grid[0][0] : LLONG_MAX;
        dp[1][1].second = (grid[0][0] < 0) ? grid[0][0] : LLONG_MIN;

        bool hasZero = false;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) {
                    continue;
                }
                long long cur = grid[i - 1][j - 1];
                long long topP = dp[i - 1][j].first != LLONG_MAX ? dp[i - 1][j].first : 0;
                long long topN = dp[i - 1][j].second != LLONG_MIN ? dp[i - 1][j].second : 0;
                long long leftP = dp[i][j - 1].first != LLONG_MAX ? dp[i][j - 1].first : 0;
                long long leftN = dp[i][j - 1].second != LLONG_MIN ? dp[i][j - 1].second : 0;
                if (cur == 0) {
                    dp[i][j] = {0, 0};
                    hasZero = true;
                }
                else if (0 < cur) {
                    dp[i][j].first = max(topP, leftP) * cur;
                    dp[i][j].second = min(topN, leftN) * cur;
                }
                else {
                    dp[i][j].first = min(topN, leftN) * cur;
                    dp[i][j].second = max(topP, leftP) * cur;
                }
            }
        }
        return dp[m][n].first == 0 ? hasZero ? 0 : -1 : (int)(dp[m][n].first % MOD);
    }
};