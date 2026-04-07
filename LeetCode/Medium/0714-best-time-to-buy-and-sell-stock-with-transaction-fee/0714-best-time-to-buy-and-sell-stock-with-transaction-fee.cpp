class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[1][1] = -(prices[0] + fee); 
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - (prices[i - 1] + fee));
        }
        return max(dp[n][0], dp[n][1]);
    }
};