class Solution {
private:
    set<pair<int, int>> s;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int curDir = 0, result = 0;
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for (const auto& a : obstacles) {
            s.insert({a[0], a[1]});
        }

        int curX = 0, curY = 0;
        for (int i = 0; i < commands.size(); ++i) {
            int curCommand = commands[i];
            if (curCommand == -2) {
                curDir = (curDir + 3) % 4;
            }
            else if (curCommand == -1) {
                curDir = (curDir + 1) % 4;
            }
            else {
                move(curX, curY, curCommand);
                updateResult(curX, curY);
            }
        }
        return result;
    }

    void move(int& curX , int& curY, int command) {
        while (0 < command-- && s.find({curX + dx[curDir], curY + dy[curDir]}) == s.end()) {
            curX += dx[curDir], curY += dy[curDir];
        }
    }

    void updateResult(const int curX, const int curY) {
        result = max(result, curX * curX + curY * curY);
    }
};