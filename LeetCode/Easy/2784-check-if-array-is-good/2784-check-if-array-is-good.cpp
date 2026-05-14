class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> cnt(201, 0);
        int maxVal = 0;
        for (const int& n : nums) {
            cnt[n]++;
            maxVal = max(maxVal, n);
        }

        for (int i = 1; i < maxVal; ++i) {
            if (cnt[i] != 1) {
                return false;
            }
        }
        return cnt[maxVal] == 2;
    }
};