class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int result = nums[0];
        auto it = min_element(nums.begin() + 1, nums.end());
        result += *it, nums.erase(it);
        it =  min_element(nums.begin() + 1, nums.end());
        result += *it;
        return result;
    }
};