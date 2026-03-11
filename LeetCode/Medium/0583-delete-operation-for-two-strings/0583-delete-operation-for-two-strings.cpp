class Solution {
private:
    int w1, w2;
    vector<vector<int>> dp;
public:
    int minDistance(string word1, string word2) {
        w1 = word1.length(), w2 = word2.length();
        dp.assign(w1 + 1, vector<int>(w2 + 1, 0));
        for (int i = 0; i <= w1; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= w2; ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= w1; ++i) {
            for (int j = 1; j <= w2; ++j) {
                dp[i][j] = (word1[i - 1] == word2[j - 1]) 
                ? dp[i - 1][j - 1]
                : min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2});
            }
        }
        return dp[w1][w2];
    }
};