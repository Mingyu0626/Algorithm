class Solution {
private:
    const int MAX = 1e9;
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < nums.size(); ++i) {
            um[nums[i]].emplace_back(i);
        }

        int result = MAX;
        for (const auto& a : um) {
            vector<int> v = a.second;
            int s = v.size();
            if (s < 3) {
                continue;
            }
            for (int i = 0; i < s; ++i) {
                for (int j = i + 1; j < s; ++j) {
                    for (int k = j + 1; k < s; ++k) {
                        result = min(result, 
                        abs(v[i] - v[j]) + abs(v[j] - v[k]) + abs(v[k] - v[i]));
                    }
                }
            }
        }
        return (result != MAX) ? result : -1;
    }
};