class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false), upper(26, false);
        for (int i = 0; i < word.length(); ++i) {
            char cur = word[i];
            if (cur <= 'Z') {
                upper[cur - 'A'] = true;
            }
            else {
                lower[cur - 'a'] = true;
            }
        }
        
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            result += (lower[i] && upper[i]) ? 1 : 0;
        }
        return result;
    }
};