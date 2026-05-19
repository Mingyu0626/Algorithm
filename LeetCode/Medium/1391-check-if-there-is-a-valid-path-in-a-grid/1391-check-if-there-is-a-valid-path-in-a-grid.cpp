class Solution {
private:
    vector<int> dx{-1, 1, 0, 0};
    vector<int> dy{0, 0, -1, 1};
    vector<vector<int>> dirs{{}, {2, 3}, {0, 1}, {1, 2}, {1, 3}, {0, 2}, {0, 3}};
    vector<vector<int>> visited;
    int m, n;
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited.assign(m, vector<int>(n, false));
        return bfs(grid);
    }

    bool bfs(const vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int startStreetNum = grid[0][0];
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            int curX = q.front().first, curY = q.front().second;
            q.pop();

            int curStreetNum = grid[curX][curY];
            for (int i = 0; i < 2; ++i) {
                int dir = dirs[curStreetNum][i];
                int newX = curX + dx[dir], newY = curY + dy[dir];
                if (newX < 0 || m <= newX || newY < 0 || n <= newY || visited[newX][newY]) {
                    continue;
                }

                int newStreetNum = grid[newX][newY];
                for (int i = 0; i < 2; ++i) {
                    int nextDir = dirs[newStreetNum][i];
                    if (converseDirection(dir) != nextDir) {
                        continue;
                    }
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
        return visited[m - 1][n - 1];
    }

    int converseDirection(const int& dir) {
        return (dir % 2 == 0) ? dir + 1 : dir - 1;
    }
};