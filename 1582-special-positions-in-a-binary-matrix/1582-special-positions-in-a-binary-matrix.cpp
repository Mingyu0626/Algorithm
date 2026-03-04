class Solution {
private:
    int m, n;
    vector<int> rowSpecial, colSpecial;
public:
    int numSpecial(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        rowSpecial.assign(m, -1), colSpecial.assign(n, -1);
        
        for (int i = 0; i < m; ++i) {
            int cnt = 0, idx = -1;
            for (int j = 0; j < n; ++j) {
                cnt += (mat[i][j] == 1) ? 1 : 0;
                idx = (mat[i][j] == 1) ? j : idx;
            }
            rowSpecial[i] = (cnt == 1) ? idx : -1;
        }

        for (int i = 0; i < n; ++i) {
            int cnt = 0, idx = -1;
            for (int j = 0; j < m; ++j) {
                cnt += (mat[j][i] == 1) ? 1 : 0;
                idx = (mat[j][i] == 1) ? j : idx;
            }
            colSpecial[i] = (cnt == 1) ? idx : -1;
        }

        int result = 0;
        for (int i = 0; i < m; ++i) {
            if (rowSpecial[i] == -1) {
                continue;
            }
            result += (colSpecial[rowSpecial[i]] == i) ? 1 : 0;
        }
        return result;
    }
};