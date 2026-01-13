class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size(), maxSkillPower = 0;
        deque<pair<int, int>> dq;
        for (int i = 0; i < n; ++i) {
            dq.emplace_back(i, skills[i]);
            maxSkillPower = max(maxSkillPower, skills[i]);
        }

        vector<int> winScore(n, 0);
        while (dq.front().second != maxSkillPower) {
            pair<int, int> playerInfo1 = dq.front(); dq.pop_front();
            pair<int, int> playerInfo2 = dq.front(); dq.pop_front();

            if (playerInfo1.second < playerInfo2.second) {
                dq.emplace_front(playerInfo2); dq.emplace_back(playerInfo1);
                winScore[playerInfo2.first]++;
                if (winScore[playerInfo2.first] == k) {
                    return playerInfo2.first;
                }
            }
            else {
                dq.emplace_front(playerInfo1); dq.emplace_back(playerInfo2);
                winScore[playerInfo1.first]++;
                if (winScore[playerInfo1.first] == k) {
                    return playerInfo1.first;
                }
            }
        }
        return dq.front().first;
    }
};