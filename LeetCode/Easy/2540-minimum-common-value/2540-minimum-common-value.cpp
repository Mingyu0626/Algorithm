class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us;
        for (int i = 0; i < nums1.size(); ++i) {
            us.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); ++i) {
            if (us.find(nums2[i]) != us.end()) {
                return nums2[i];
            }
        }
        return -1;
    }
};