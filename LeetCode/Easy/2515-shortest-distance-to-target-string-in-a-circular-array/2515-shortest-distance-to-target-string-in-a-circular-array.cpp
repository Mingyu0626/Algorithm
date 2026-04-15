class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        unordered_map<string, vector<int>> um;
        int n = words.size(), minDist = n;
        for (int i = 0; i < n; ++i) {
            um[words[i]].emplace_back(i);
        }

        if (um[target].size() == 0) {
            return -1;
        }
        for (int i = 0; i < um[target].size(); ++i) {
            int targetIdx = um[target][i];
            int dist = abs(startIndex - targetIdx);
            minDist = min({minDist, dist, n - dist});
        }
        return minDist;
    }
};