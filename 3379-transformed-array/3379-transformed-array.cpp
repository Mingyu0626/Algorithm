class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            int idx = (i + nums[i]) % n;
            idx += (idx < 0) ? n : 0;
            result[i] = nums[idx];
        }
        return result;
    }
};