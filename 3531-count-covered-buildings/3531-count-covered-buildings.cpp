class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxRow(n + 1), minRow(n + 1, n + 1);
        vector<int> maxCol(n + 1), minCol(n + 1, n + 1);

        for (const auto& p : buildings) {
            int x = p[0], y = p[1];
            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);
            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);
        }

        int result = 0;
        for (const auto& p : buildings) {
            int x = p[0], y = p[1];
            if (x <= minRow[y] || maxRow[y] <= x || y <= minCol[x] || maxCol[x] <= y) {
                continue;
            } 
            result++;
        }
        return result;
    }
};