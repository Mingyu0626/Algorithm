class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size(), r = grid[0][0] % x;
        vector<int> v;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (r != grid[i][j] % x) {
                    return -1;
                }
                v.emplace_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());

        int midIdx = m * n / 2, target = v[midIdx], result = 0;
        for (int i = 0; i < m * n; ++i) {
            result += abs(target - v[i]) / x;
        }
        return result;
    }
};