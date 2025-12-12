class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), curPrice = prices[0];
        int result = 0;
        for (int i = 1; i < n; ++i) {
            int nextPrice = prices[i];
            if (curPrice < nextPrice) {
                result += nextPrice - curPrice;
                curPrice = nextPrice;
            }
            curPrice = nextPrice;
        }
        return result;
    }
};