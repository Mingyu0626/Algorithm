class Solution {
public:
    int minOperations(string s) {
        int start0 = 0, start1 = 0;
        for (int i = 0; i < s.length(); ++i) {
            int cur = s[i] - '0';
            start0 += (cur == (i % 2)) ? 1 : 0;
            start1 += (cur != (i % 2)) ? 1 : 0;
        }
        return min(start0, start1);
    }
};