class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), leftSum = 0, rightSum = 0;
        for (int i = 0; i < n; ++i) {
            rightSum += nums[i];
        }

        int result = 0;
        for (int i = 0; i < n - 1; ++i) {
            leftSum += nums[i];
            rightSum -= nums[i];
            int diff = leftSum - rightSum;
            result += diff % 2 == 0 ? 1 : 0;
        }
        return result;
    }
};