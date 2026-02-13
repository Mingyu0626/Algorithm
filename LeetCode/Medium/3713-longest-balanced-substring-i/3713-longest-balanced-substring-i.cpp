class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length(), result = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> v(26, 0);
            for (int j = i; j < n; ++j) {
                char cur = s[j];
                v[cur - 'a']++;
                result = isBalanced(v) ? max(j - i + 1, result) : result;
            }
        }
        return result;
    }
    bool isBalanced(const vector<int>& v) {
        int maxCnt = 0;
        for (const auto& a : v) {
            if (a == 0) {
                continue;
            }
            if (maxCnt != a && 0 < maxCnt) {
                return false;
            }
            maxCnt = a;
        }
        return true;
    }
};