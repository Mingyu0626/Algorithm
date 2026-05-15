class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> lis;
        lis.emplace_back(nums[0]);
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            if (lis.back() < cur) {
                lis.emplace_back(cur);
            }
            else {
                int idx = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
                lis[idx] = cur;
            }
        }
        return 3 <= lis.size();
    }
};