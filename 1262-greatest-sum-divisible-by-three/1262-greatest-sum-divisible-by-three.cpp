class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> dp;

    int maxSumDivThree(vector<int>& numbers) {
        initialize(numbers);
        sortDesc();
        fillDPArray();
        return dp[n - 1][0];
    }

    void initialize(vector<int>& numbers) {
        n = numbers.size();
        nums = numbers;
        dp.assign(n, vector<int>(3, 0));
    }

    void sortDesc() {
        sort(nums.rbegin(), nums.rend());
    }

    void fillDPArray() {
        dp[0][nums[0] % 3] = nums[0];
        for (int i = 1; i < n; ++i) {
            int cur = nums[i], remainder = cur % 3;
            int prevOne = (remainder + 1) % 3, prevTwo = (remainder + 2) % 3;
            dp[i][remainder] = (dp[i - 1][0] != 0) ? max(dp[i - 1][remainder], dp[i - 1][0] + cur) : cur;
            dp[i][prevOne] = (dp[i - 1][1] != 0) ? max(dp[i - 1][prevOne], dp[i - 1][1] + cur) : dp[i - 1][prevOne];
            dp[i][prevTwo] = (dp[i - 1][2] != 0) ? max(dp[i - 1][prevTwo], dp[i - 1][2] + cur) : dp[i - 1][prevTwo];
        }
    }
};