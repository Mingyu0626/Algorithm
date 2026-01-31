class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char result = letters[0];
        int minDifference = 26;
        for (int i = 0; i < letters.size(); ++i) {
            int curDifference = letters[i] - target;
            if (0 < curDifference && curDifference < minDifference) {
                result = letters[i];
                minDifference = curDifference;
            }
        }
        return result;
    }
};