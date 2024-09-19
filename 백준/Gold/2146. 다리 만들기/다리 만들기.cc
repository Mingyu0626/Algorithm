#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, landCount, result = 1e9;
vector<vector<int>> v, dist;
vector<vector<bool>> visited;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs1(int x, int y, int lc);
void bfs2();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<int>(n, 0));
    dist.assign(n, vector<int>(n, -1));
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

    bfs2();
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

void bfs2()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != 0)
            {
                dist[i][j] = 0;
                q.push({ i, j });
            }
        }
    }

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newx = curX + dx[i];
            int newy = curY + dy[i];
            if (newx < 0 || n <= newx || newy < 0 || n <= newy || (v[curX][curY] == v[newx][newy])) continue;
            if (v[newx][newy] == 0)
            {
                v[newx][newy] = v[curX][curY];
                dist[newx][newy] = dist[curX][curY] + 1;
                q.push({ newx, newy });
            }
            else result = min(result, dist[curX][curY] + dist[newx][newy]);
        }
    }
}