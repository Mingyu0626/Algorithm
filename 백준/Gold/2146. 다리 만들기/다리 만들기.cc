#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, landCount = 1, result = 1e9;
vector<vector<int>> v;
vector<vector<bool>> visited;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs1(int x, int y, int lc);
void bfs2(int x, int y, int lc, int d);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && v[i][j] == 1)
            {
                landCount++;
                bfs1(i, j, landCount);
            }
        }
    }

    fill(visited.begin(), visited.end(), vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && v[i][j] != 0)
            {
                bfs2(i, j, v[i][j], 0);
                fill(visited.begin(), visited.end(), vector<bool>(n, false));
            }
        }
    }
    cout << result;
    return 0;
}

void bfs1(int x, int y, int lc)
{
    queue<pair<int, int>> q;
    visited[x][y] = true;
    v[x][y] = lc;
    q.push({ x, y });
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];

            if (newX < 0 || n <= newX || newY < 0 || n <= newY) continue;
            if (!visited[newX][newY] && v[newX][newY] == 1)
            {
                q.push({ newX, newY });
                visited[newX][newY] = true;
                v[newX][newY] = lc;
            }
        }
    }
}

void bfs2(int x, int y, int lc, int d)
{
    queue<pair<pair<int, int>, int>> q;
    visited[x][y] = true;
    q.push({ { x, y }, d });
    while (!q.empty())
    {
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (newX < 0 || n <= newX || newY < 0 || n <= newY) continue;
            if (!visited[newX][newY] && v[newX][newY] == 0)
            {
                q.push({ { newX, newY }, dist + 1 });
                visited[newX][newY] = true;
            }
            if (v[newX][newY] != 0 && v[newX][newY] != lc) result = min(result, dist);
        }
    }
}