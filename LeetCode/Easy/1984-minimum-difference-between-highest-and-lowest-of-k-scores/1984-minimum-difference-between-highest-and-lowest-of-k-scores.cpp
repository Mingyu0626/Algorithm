class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        map<int, int> m;
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        while (r < k) {
            m[nums[r]]++;
            r++;
        }

        int result = m.rbegin()->first - m.begin()->first;
        while (r < nums.size()) {
            m[nums[l]]--, m[nums[r]]++;
            if (m[nums[l]] == 0) {
                m.erase(nums[l]);
            }
            result = min(result, m.rbegin()->first - m.begin()->first);
            l++, r++;
        }
        result = min(result,  m.rbegin()->first - m.begin()->first);
        return result;
    }
};