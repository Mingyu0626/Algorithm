class Solution {
public:
    char findTheDifference(string s, string t) {
        int addedLetter = 0;
        for (int i = 0; i < s.length(); ++i) {
            addedLetter -= (s[i] - '0');
        }
        for (int i = 0; i < t.length(); ++i) {
            addedLetter += (t[i] - '0');
        }
        return addedLetter + '0';
    }
};