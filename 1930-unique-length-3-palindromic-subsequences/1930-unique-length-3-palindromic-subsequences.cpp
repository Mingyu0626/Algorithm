class Solution {
public:
    unordered_map<char, pair<int, int>> charAppearIndexMap;
    unordered_map<char, unordered_set<char>> middleCharMap;

    int countPalindromicSubsequence(string s) {
        int n = s.length();
        for (int i = 0; i < 26; ++i) {
            charAppearIndexMap['a' + i] = {-1, -1};
        }

        for (int i = 0; i < n; ++i) {
            char cur = s[i];
            if (charAppearIndexMap[cur].first == -1) {
                charAppearIndexMap[cur].first = i;
            }
            else {
                charAppearIndexMap[cur].second = i;
            }
        }

        int result = 0;
        for (const auto& a : charAppearIndexMap) {
            char curChar = a.first;
            int leftIdx = a.second.first, rightIdx = a.second.second;
            if (leftIdx == -1 || rightIdx == -1) {
                continue;
            }

            auto middleCharSet = middleCharMap[curChar];
            for (int i = leftIdx + 1; i < rightIdx; ++i) {
                char middleChar = s[i];
                if (middleCharSet.find(middleChar) != middleCharSet.end()) {
                    continue;
                }
                middleCharSet.insert(middleChar);
            }
            result += middleCharSet.size();
        }
        return result;
    }
};