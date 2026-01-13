class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size(), lastWinPlayer = 0, winCount = 0;
        for (int i = 1; i < n; ++i) {
            if (skills[lastWinPlayer] < skills[i]) {
                lastWinPlayer = i;
                winCount = 0;
            }
            if (++winCount == k) {
                return lastWinPlayer;
            }
        }
        return lastWinPlayer;
    }
};