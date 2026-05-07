class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sum = 0, lastSum = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            lastSum += i * nums[i];
            sum += nums[i];
        }
        
        result = lastSum;
        for (int i = 1; i < n; ++i) {
            lastSum += sum - (n * nums[n - i]);
            result = max(result, lastSum);
        }
        return result;
    }
};