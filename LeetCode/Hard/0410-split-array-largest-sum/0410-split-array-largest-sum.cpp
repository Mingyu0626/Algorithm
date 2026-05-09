class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if (nums.empty() || m == 0) {
            return 0;
        }

        int left = 0, right = 0;
        for(const auto& n : nums) {
            left = max(left, n); 
            right += n; 
        }

        while (left < right) 
        {
            int mid = (right - left) / 2 + left;
            int curBagSize = 0, currentM = 1;
            for(const auto& n : nums) {
                if (mid < curBagSize + n) { 
                    currentM++;
                    curBagSize = 0;
                }
                curBagSize += n;
            } 
            if (m < currentM) {
                left = mid + 1;
            } 
            else {
                right = mid;
            }
        }
        return left;
    }
};