class Solution {
public:
    bool checkOnesSegment(string s) {
        int continuousCnt = 0;
        char prev = s[0];
        for (int i = 1; i < s.length(); ++i) {
            continuousCnt += (prev == '1' && s[i] == '0') ? 1 : 0;
            prev = s[i];
        }
        continuousCnt += (prev == '1') ? 1 : 0;
        return continuousCnt == 1;
    }
};