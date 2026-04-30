class Solution {
private:
    int m, n;
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(1001, -1)));

        if (grid[0][0] == 0) {
            dp[0][0][0] = 0;
        }
        else {
            dp[0][0][1] = grid[0][0];
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int c = 0; c <= i + j; ++c) {
                    if (dp[i][j][c] == -1) {
                        continue;
                    }

                    if (j + 1 < n) {
                        int newCost = c + (grid[i][j + 1] == 0 ? 0 : 1);
                        if (newCost <= k){
                            dp[i][j + 1][newCost] = max(dp[i][j + 1][newCost], dp[i][j][c] + grid[i][j + 1]);
                        }
                    }

                    if (i + 1 < m) {
                        int newCost = c + (grid[i + 1][j] == 0 ? 0 : 1);
                        if (newCost <= k) {
                            dp[i + 1][j][newCost] = max(dp[i + 1][j][newCost], dp[i][j][c] + grid[i + 1][j]);
                        }
                    }
                }
            }
        }

        int result = -1;
        for (int i = 0; i <= k; ++i) {
            result = max(result, dp[m - 1][n - 1][i]);
        }
        return result;
    }
};