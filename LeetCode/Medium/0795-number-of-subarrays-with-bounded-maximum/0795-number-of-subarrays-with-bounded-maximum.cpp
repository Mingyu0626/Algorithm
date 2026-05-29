class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return getSubArrayCount(nums, right) - getSubArrayCount(nums, left - 1);
    }

    int getSubArrayCount(vector<int>& nums, const int& limit) {
        int curSize = 0, cnt = 0;
        for (const auto& a : nums) {
            if (a <= limit) {
                curSize++;
            }
            else {
                curSize = 0;
            }
            cnt += curSize;
        }
        return cnt;
    }
};