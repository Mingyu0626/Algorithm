class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result = 1001;
        for (int i = 0; i < nums.size(); ++i) {
            result = (nums[i] == target) ? min(result, abs(i - start)) : result;
        }
        return result;
    }
};