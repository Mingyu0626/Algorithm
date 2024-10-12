#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std; 

int n, result;
vector<vector<char>> v;
vector<vector<bool>> visited;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y, bool isRGCB);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    visited.assign(n, vector<bool>(n, false));
    v.assign(n, vector<char>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs(i, j, false);
                result++;
            }
        }
    }

    cout << result << ' ';
    result = 0;
    visited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs(i, j, true);
                result++;
            }
        }
    }
    cout << result;
    return 0;
}

void bfs(int x, int y, bool isRGCB)
{
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({ x, y });

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        char curColor = v[curX][curY];
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (newX < 0 || n <= newX || newY < 0 || n <= newY) continue;
            char newColor = v[newX][newY];

            if (!visited[newX][newY])
            {
                if (curColor == newColor)
                {
                    q.push({ newX, newY });
                    visited[newX][newY] = true;
                }
                else if (isRGCB && ((curColor == 'R' && newColor == 'G') ||
                    (curColor == 'G' && newColor == 'R')))
                {
                    q.push({ newX, newY });
                    visited[newX][newY] = true;
                }
            }
        }
    }
}