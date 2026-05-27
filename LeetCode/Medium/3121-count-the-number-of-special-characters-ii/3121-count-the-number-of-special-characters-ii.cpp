class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1), firstUpper(26, -1);

        for (int i = word.length() - 1; 0 <= i; --i) {
            char cur = word[i];
            if (cur <= 'Z') {
                firstUpper[cur - 'A'] = i;
            }
            else {
                lastLower[cur - 'a'] = max(lastLower[cur - 'a'], i);
            }
        }

        int result = 0;
        for (int i = 0; i < 26; ++i) {
            if (lastLower[i] == -1 || firstUpper[i] == -1) {
                continue;
            }
            result += (lastLower[i] < firstUpper[i]) ? 1 : 0;
        }
        return result;
    }
};