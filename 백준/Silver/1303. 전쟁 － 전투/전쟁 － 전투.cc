#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
vector<vector<char>> v;
vector<vector<bool>> visited;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
pair<int, int> result;

void bfs(int y, int x, char t);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(m, vector<char>(n, 0));
    visited.assign(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j]) bfs(i, j, v[i][j]);
        }
    }
    cout << result.first << ' ' << result.second;
    return 0;
}

void bfs(int y, int x, char t)
{
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;
    int power = 1;
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newY = curY + dy[i];
            int newX = curX + dx[i];
            if (newY < 0 || m <= newY || newX < 0 || n <= newX) continue;
            if (!visited[newY][newX] && v[newY][newX] == t)
            {
                q.push({ newY, newX });
                visited[newY][newX] = true;
                power++;
            }
        }
    }
    if (t == 'W') result.first += pow(power, 2);
    else result.second += pow(power, 2);
}