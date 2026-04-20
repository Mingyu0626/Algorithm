class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), result = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                result = (colors[i] != colors[j]) ? max(result, j - i) : result;
            }
        }
        return result;
    }
};