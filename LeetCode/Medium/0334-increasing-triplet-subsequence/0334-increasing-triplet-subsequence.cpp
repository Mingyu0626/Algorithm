class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i = INT_MAX, j = INT_MAX;
        for (const int& a : nums) {
            if (a <= i) {
                i = a;
            }
            else if (a <= j) {
                j = a;
            }
            else {
                return true;
            }
        }
        return false;
    }
};