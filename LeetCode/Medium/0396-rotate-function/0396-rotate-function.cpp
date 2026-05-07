class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sum = 0, result = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[0] += i * nums[i];
            sum += nums[i];
        }
        
        result = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + sum - (n * nums[n - i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};