class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long> dp(n, 1);
        long long result = 1;
        for (int i = 1; i < n; ++i) {
            if (prices[i - 1] - 1 == prices[i]) {
                dp[i] += dp[i - 1];
            }
            result += dp[i];
        }
        return result;
    }
};