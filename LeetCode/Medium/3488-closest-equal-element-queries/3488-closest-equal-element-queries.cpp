class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> um;
        int n =  nums.size();
        for (int i = 0; i < n; ++i) {
            um[nums[i]].emplace_back(i);
        }

        vector<int> result;
        for (int i = 0; i < queries.size(); ++i) {
            int targetIdx = queries[i], targetNum = nums[targetIdx];
            if (um[targetNum].size() == 1) {
                result.emplace_back(-1);
                continue;
            }

            const vector<int>& v = um[targetNum];
            int idxUpper = upper_bound(v.begin(), v.end(), targetIdx) - v.begin();
            idxUpper = (idxUpper == v.size()) ? 0 : idxUpper;

            int idxLower = lower_bound(v.begin(), v.end(), targetIdx) - v.begin() - 1;
            idxLower = (idxLower == -1) ? v.size() - 1 : idxLower;

            int minDist = n;
            if (v[idxUpper] != targetIdx) {
                int dist = abs(v[idxUpper] - targetIdx);
                minDist = min({ minDist, dist, n - dist});
            }

            if (v[idxLower] != targetIdx) {
                int dist = abs(v[idxLower] - targetIdx);
                minDist = min({ minDist, dist, n - dist});
            }
            result.emplace_back(minDist);
        }
        return result;
    }
};