class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for (int i = 0; i < k; ++i) {
            result += max(happiness[i] - i, 0);
        }
        return result;
    }
};