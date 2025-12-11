class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<set<int>> r(n + 1), c(n + 1);
        for (int i = 0; i < buildings.size(); ++i) {
            int row = buildings[i][0], col = buildings[i][1];
            r[row].insert(col), c[col].insert(row);
        }

        int result = 0;
        for (int i = 0; i < buildings.size(); ++i) {
            int row = buildings[i][0], col = buildings[i][1];
            if (r[row].upper_bound(col) == r[row].end() || 
                r[row].lower_bound(col) == r[row].begin() ||
                c[col].upper_bound(row) == c[col].end() || 
                c[col].lower_bound(row) == c[col].begin()) {
                    continue;
                }
            result++;
        }
        return result;
    }
};