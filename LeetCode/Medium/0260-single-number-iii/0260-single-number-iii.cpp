class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorResult = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xorResult ^= nums[i];
        }

        int mask = xorResult & -xorResult, x = 0, y = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i] & mask) == 0) {
                x ^= nums[i];
            }
            else {
                y ^= nums[i];
            }
        }
        return {x, y};
    }
};