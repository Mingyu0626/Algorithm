class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int, int> um;
        int maxCnt = 0, n = nums.size();
        for (const auto& a: nums) {
            um[a]++;
            maxCnt = max(maxCnt, um[a]);
        }
        if (n / 2 < maxCnt) {
            return maxCnt - (n - maxCnt);
        }
        return n % 2;
    }
};