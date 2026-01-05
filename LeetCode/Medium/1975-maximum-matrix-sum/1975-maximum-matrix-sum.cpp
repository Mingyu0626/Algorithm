class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int numOfNegative = 0, minAbsVal = 1e9;
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {          
                if (matrix[i][j] == 0) {
                    continue;
                }
                numOfNegative += (matrix[i][j] < 0) ? 1 : 0;
                minAbsVal = min(minAbsVal, abs(matrix[i][j]));
                result += abs(matrix[i][j]);
            }
        }

        bool canUseZero = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0) {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    int newX = i + dx[k], newY = j + dy[k];
                    if (0 <= newX && newX < n && 0 <= newY && newY < n &&
                    matrix[newX][newY] < 0) {
                        canUseZero = true;
                    }
                }
            }
        }
        
        if (numOfNegative % 2 != 0 && !canUseZero) {
            result -= minAbsVal * 2;
        }
        return result;
    }
};