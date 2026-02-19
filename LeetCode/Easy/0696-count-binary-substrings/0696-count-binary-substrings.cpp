class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;
        int prevBinary = s[0], cnt = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (prevBinary != s[i]) {
                counts.emplace_back(cnt);
                prevBinary = s[i];
                cnt = 0;
            }
            cnt++;
        }
        counts.emplace_back(cnt);

        int result = 0;
        for (int i = 1; i < counts.size(); ++i) {
            result += min(counts[i - 1], counts[i]);
        }
        return result;
    }
};