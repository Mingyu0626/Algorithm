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
            const vector<int>& v = a.second;
            int s = v.size();
            if (s < 3) {
                continue;
            }

            for (int i = 2; i < s; ++i) {
               result = min(result, 2 * (v[i] - v[i - 2]));
            }
        }
        return (result != MAX) ? result : -1;
    }
};