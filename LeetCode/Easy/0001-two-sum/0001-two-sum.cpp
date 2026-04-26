class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            v.emplace_back(nums[i], i);
        }
        sort(v.begin(), v.end());

        int l = 0, r = n - 1;
        vector<int> result(2, 0);
        while (l < r) {
            if (v[l].first + v[r].first == target) {
                result[0] = v[l].second, result[1] = v[r].second;
                break;
            }
            else if (v[l].first + v[r].first < target) {
                l++;
            }
            else {
                r--;
            }
        }
        return result;
    }
};