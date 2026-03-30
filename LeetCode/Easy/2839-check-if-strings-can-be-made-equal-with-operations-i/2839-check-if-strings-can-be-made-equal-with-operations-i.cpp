class Solution {
public:

    bool swap(int cnt, string s1, const string& s2) {
        if (s1 == s2) {
            return true;
        }
        for (int i = cnt; i < 2; ++i) {
            string newStr(s1);
            char l = s1[i], r = s1[i + 2];
            newStr[i] = r, newStr[i + 2] = l;
            if (swap(i + 1, newStr, s2)) {
                return true;
            }
        }
        return false;
    }

    bool canBeEqual(string s1, string s2) {
        return swap(0, s1, s2);
    }
};