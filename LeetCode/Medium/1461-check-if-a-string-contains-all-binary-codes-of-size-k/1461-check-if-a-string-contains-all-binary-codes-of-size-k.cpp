class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> us;
        if (s.length() < k) {
            return false;
        }
        for (int i = 0; i < s.length() - k + 1; ++i) {
            us.insert(s.substr(i, k));
        }
        return us.size() == pow(2, k);
    }
};