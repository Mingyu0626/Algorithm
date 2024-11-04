#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, result = 1e9;
vector<vector<char>> v;
bool visited[101][101];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    bfs();
    cout << result;
    return 0;
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = true;
    int level = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            if (curX == n - 1 && curY == m - 1)
            {
                result = level;
                return;
            }

            for (int j = 0; j < 4; j++)
            {
                int newX = curX + dx[j];
                int newY = curY + dy[j];
                if (newX < 0 || n <= newX || newY < 0 || m <= newY) continue;
                if (!visited[newX][newY] && v[newX][newY] == '1')
                {
                    q.push({ newX, newY });
                    visited[newX][newY] = true;
                }
            }
        }
        level++;
    }
}