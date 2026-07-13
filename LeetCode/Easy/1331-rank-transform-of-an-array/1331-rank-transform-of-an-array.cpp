class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i].first = arr[i], v[i].second = i;
        }
        sort(v.begin(), v.end());

        vector<int> result(n, 0);
        int rank = 0, prev = INT_MIN;
        for (int i = 0; i < n; ++i) {
            result[v[i].second] = (prev < v[i].first) ? ++rank : rank;
            prev = v[i].first;
        }
        return result;
    }
};