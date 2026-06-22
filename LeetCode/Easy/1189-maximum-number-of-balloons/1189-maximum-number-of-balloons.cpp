class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> counts(26, 0);
        for (const char& c : text) {
            counts[c - 'a']++;
        }
        return min({counts['a' - 'a'], counts['b' - 'a'], 
        counts['l' - 'a'] / 2, counts['o' - 'a'] / 2, counts['n' - 'a']});
    }
};