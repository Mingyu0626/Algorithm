class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int minAbs = 1e9;
        for (int i = 0; i < arr.size() - 1; ++i) {
            int curAbs = abs(arr[i] - arr[i + 1]);
            if (curAbs < minAbs) {
                result.clear();
                minAbs = curAbs;
            }
            if (curAbs <= minAbs) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        return result;
    }
};