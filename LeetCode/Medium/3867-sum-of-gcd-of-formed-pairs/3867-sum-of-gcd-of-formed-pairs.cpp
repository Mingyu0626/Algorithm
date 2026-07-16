class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        vector<int> p(n, 0);
        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            p[i] = gcd(nums[i], mx);
        }
        sort(p.begin(), p.end());

        long long result = 0;
        int l = 0, r = n - 1, leftVal = 0, rightVal = INT_MAX;
        while (l < r) {
            leftVal = p[l++], rightVal = p[r--];
            result += gcd(leftVal, rightVal);
        }
        return result;
    }
};