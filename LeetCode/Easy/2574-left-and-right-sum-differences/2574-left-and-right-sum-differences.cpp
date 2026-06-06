class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] + nums[i - 1];
        }

        int prev = 0;
        for (int i = n - 2; 0 <= i; --i) {
            int cur = prev + nums[i + 1];
            prev = cur;
            result[i] = abs(result[i] - cur);
        }
        return result;
    }
};