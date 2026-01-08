class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int, int> um;
        for (const auto& a : nums) {
            um[a]++;
        }
        for (const auto& a : um) {
            if (a.second == n) {
                return a.first;
            }
        }
        return -1;
    }
};