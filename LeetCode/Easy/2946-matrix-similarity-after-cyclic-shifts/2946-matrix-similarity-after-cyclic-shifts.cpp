class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        deque<deque<int>> dq(m, deque<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dq[i][j] = mat[i][j];
            }
        }

        while (0 < k--) {
            for (int i = 0; i < m; ++i) {
                if (i % 2 == 0) {
                    int f = dq[i].front(); dq[i].pop_front();
                    dq[i].push_back(f);
                }
                else {
                    int b = dq[i].back(); dq[i].pop_back();
                    dq[i].push_front(b);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dq[i][j] != mat[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};