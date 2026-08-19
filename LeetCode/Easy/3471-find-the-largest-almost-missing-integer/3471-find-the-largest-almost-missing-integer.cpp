class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int n = nums.size();
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        for (int i = 0; i < n; ++i) {
            um[nums[i]]++;
        }
        
        if (k == 1) {
            int maxVal = -1;
            for (int i = 0; i < n; ++i) {
                maxVal = (um[nums[i]] == 1) ? max(maxVal, nums[i]) : maxVal;
            }
            return maxVal;
        }

        int result = -1;
        result = (um[nums[0]] == 1) ? nums[0] : result;
        result = (um[nums[n - 1]] == 1) ? max(result, nums[n - 1]) : result;
        return result;
    }
};