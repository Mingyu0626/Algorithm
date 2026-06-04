class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            int a = nums[i];
            int j = i + 1, k = n - 1;
            while (j < k) {
                int b = nums[j], c = nums[k];                 
                if (a + b + c == 0) {
                    s.insert({a, b, c});
                }

                if (0 <= a + b + c) {
                    k--;
                }
                else {
                    j++;
                }                     
            }                 
        }

        for (const auto& a : s) {
            result.emplace_back(a);
        }
        return result;
    }
};