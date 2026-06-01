class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i] + k < nums[i + 2]) {
                return vector<vector<int>>();
            }

            vector<int> tmp;
            for (int j = i; j < i + 3; ++j) {
                tmp.emplace_back(nums[j]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};