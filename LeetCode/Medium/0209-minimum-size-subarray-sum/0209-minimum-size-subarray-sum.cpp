class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = 1e9, n = nums.size(), l = 0, r = 0, sum = nums[0];
        while (l < n && r < n) {
            if (sum < target) {
                r++;
                sum += (r < n) ? nums[r] : 0;
            }
            else {
                result = min(result, r - l + 1);
                sum -= nums[l++];
                sum = (r < l && l < n) ? nums[++r] : sum; 
            }
        }
        return (result == 1e9) ? 0 : result;
    }
};