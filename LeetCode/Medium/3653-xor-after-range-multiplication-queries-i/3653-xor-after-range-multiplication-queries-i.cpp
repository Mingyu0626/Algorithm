class Solution {
public:
    int xorAfterQueries(vector<int>& n, vector<vector<int>>& q) {
        vector<long long> nums;
        for (const auto& a : n) {
            nums.emplace_back(a);
        }

        const int MOD = 1000000007;
        for (int i = 0; i < q.size(); ++i) {
            int l = q[i][0], r = q[i][1], k = q[i][2], v = q[i][3];
            for (int j = l; j <= r; j += k) {
                nums[j] = (nums[j] * v) % MOD; 
            }
        }

        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result ^= nums[i];
        }
        return result;
    }
};