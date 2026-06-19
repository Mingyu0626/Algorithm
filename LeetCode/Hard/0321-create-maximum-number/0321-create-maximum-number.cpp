class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> result(k, 0);

        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            vector<int> v1 = getMaxArray(nums1, i), v2 = getMaxArray(nums2, k - i);
            vector<int> candidate = merge(v1, v2);
            if (compare(candidate, 0, result, 0)) {
                result = candidate;
            }
        }
        return result;
    }

private:
    vector<int> getMaxArray(const vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        int drop = n - k;
        
        for (const auto& num : nums) {
            while (0 < drop && !result.empty() && result.back() < num) {
                result.pop_back();
                drop--;
            }
            result.emplace_back(num);
        }
        result.resize(k);
        return result;
    }

    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (compare(nums1, i, nums2, j)) {
                result.emplace_back(nums1[i++]);
            } 
            else {
                result.emplace_back(nums2[j++]);
            }
        }
        return result;
    }

    bool compare(const vector<int>& nums1, int i, const vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++, j++;
        }
        if (j == nums2.size()) {
            return true;
        }
        if (i == nums1.size()) {
            return false;
        }
        return nums1[i] > nums2[j];
    }
};