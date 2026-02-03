class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool increasingNow = true;
        int changeCnt = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int p = nums[i - 1], c = nums[i];
            if (p == c) {
                return false;
            }

            if (p < c) {
                if (!increasingNow) {
                    changeCnt++;
                    increasingNow = true;
                }
            }
            if (c < p) {
                if (changeCnt != 0 && increasingNow) {
                    return false;
                }
                if (changeCnt == 0) {
                    if (1 < i) {
                        changeCnt++;
                        increasingNow = false;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return changeCnt == 2;
    }
};