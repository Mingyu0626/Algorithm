class Solution {
public:
    string processStr(string s) {
        string result;
        for (int i = 0; i < s.length(); ++i) {
            char cur = s[i];
            switch (cur) {
                case '*':
                    if (0 < result.size()) {
                        result.pop_back();
                    }
                    break;
                case '#':
                    result += result;
                    break;
                case '%':
                    reverse(result.begin(), result.end());
                    break;
                default:
                    result += cur;
                    break;
            }
        }
        return result;
    }
};