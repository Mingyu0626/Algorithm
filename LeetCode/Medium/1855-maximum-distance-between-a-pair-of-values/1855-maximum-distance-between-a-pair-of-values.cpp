class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), result = 0;
        for (int i = 0; i < n1; ++i) {
            int j = upper_bound(nums2.begin(), nums2.end(), nums1[i], greater<int>()) - nums2.begin() - 1;
            result = (i <= j) ? max(result, j - i) : result;
        }
        return result;
    }
};