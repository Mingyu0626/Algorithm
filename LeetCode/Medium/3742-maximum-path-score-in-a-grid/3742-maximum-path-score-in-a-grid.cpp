class Solution {
private:
    int m, n;
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(1001, -1)));

        if (grid[0][0] == 0) {
            dp[1][1][0] = 0;
        }
        else {
            dp[1][1][1] = grid[0][0];
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int c = 0; c < i + j; ++c) {
                    int prev = max(dp[i - 1][j][c], dp[i][j - 1][c]);
                    if (prev == -1) {
                        continue;
                    }
                    int cost = grid[i - 1][j - 1] == 0 ? 0 : 1;
                    int score = grid[i - 1][j - 1];
                    dp[i][j][c + cost] = prev + score;
                }
            }
        }

        int result = -1;
        for (int i = 0; i <= k; ++i) {
            result = max(result, dp[m][n][i]);
        }
        return result;
    }
};