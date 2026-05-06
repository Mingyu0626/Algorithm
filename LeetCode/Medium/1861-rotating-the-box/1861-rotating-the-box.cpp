class Solution {
private:
    int m, n;
    vector<vector<char>> results;
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        m = boxGrid.size(), n = boxGrid[0].size();
        results.assign(n, vector<char>(m, ' '));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                results[j][m - i - 1] = boxGrid[i][j];
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (results[i][j] != '#') {
                    continue;
                }
                int curH = i + 1;
                while (curH < n && results[curH][j] == '.') {
                    results[curH][j] = '#';
                    results[curH - 1][j] = '.';
                    curH++;
                }
            }
        }
        return results;
    }
};