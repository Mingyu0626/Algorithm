#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int l, w, result;
vector<vector<char>> v;
vector<vector<bool>> visited;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> l >> w;
    v.assign(l, vector<char>(w, '0'));
    visited.assign(l, vector<bool>(w, false));
    for (int i = 0; i < l; i++)
        for (int j = 0; j < w; j++) cin >> v[i][j];
    
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (v[i][j] == 'L')
            {
                bfs(i, j);
                fill(visited.begin(), visited.end(), vector<bool>(w, false));
            }
        }
    }
    cout << result;
    return 0;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    int level = -1;
    while (!q.empty())
    {
        int qSize = q.size();
        level++;
        for (int i = 0; i < qSize; i++)
        {
            int curX = q.front().first, curY = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = curX + dx[i], newY = curY + dy[i];
                if (newX < 0 || l <= newX || newY < 0 || w <= newY) continue;
                if (v[newX][newY] == 'L' && !visited[newX][newY])
                {
                    q.push({ newX, newY });
                    visited[newX][newY] = true;
                }
            }
        }
    }
    result = max(result, level);
}
