class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1e9 + 7;
        int n = complexity.size(), rootPw = complexity[0];
        long long result = 1;
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= rootPw) {
                return 0;
            }
            result = result * i % MOD;
        }
        return static_cast<int>(result);
    }
};