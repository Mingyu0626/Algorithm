class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min = nums[0], max = nums[nums.size() - 1], idx = 0;
        vector<int> result;
        for (int i = min; i <= max; ++i) {
            if (nums[idx] != i) {
                result.emplace_back(i);
            }
            else {
                idx++;
            }
        }
        return result;
    }
};