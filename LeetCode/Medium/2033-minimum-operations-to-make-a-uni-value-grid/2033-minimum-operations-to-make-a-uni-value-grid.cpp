class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> v;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                v.emplace_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());

        int r = v[0] % x;
        for (int i = 0; i < m * n; ++i) {
            if (r != v[i] % x) {
                return -1;
            }
        }

        int midIdx = m * n / 2, target = v[midIdx], result = 0;
        for (int i = 0; i < m * n; ++i) {
            result += abs(target - v[i]) / x;
        }
        return result;
    }
};