class Solution {
public:
    int minimumPushes(string word) {
        unordered_set<char> cnt;
        for (const auto& c : word) {
            cnt.insert(c);
        }
        int c = cnt.size(), result = 0;
        if (c <= 8) {
            result = c;
        } 
        if (8 < c && c <= 16) {
            result = 8 + (c - 8) * 2;
        }
        if (16 < c && c <= 24) {
            result = 24 + (c - 16) * 3;
        }
        if (24 < c) {
            result = 48 + (c - 24) * 4;
        }
        return result;
    }
};