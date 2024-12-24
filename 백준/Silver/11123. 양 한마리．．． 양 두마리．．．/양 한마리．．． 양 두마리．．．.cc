#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

int t, h, w, result;
vector<vector<char>> v(100, vector<char>(100));
vector<vector<bool>> visited(100, vector<bool>(100));

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t > 0)
    {
        cin >> h >> w;
        result = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> v[i][j];
                visited[i][j] = false;
            }
        }
        
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (v[i][j] == '#' && !visited[i][j])
                {
                    bfs(i, j);
                    result++;
                }
            }
        }
        cout << result << '\n';
        t--;
    }
    return 0;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    visited[x][y] = true;
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
            if (newX < 0 || h <= newX || newY < 0 || w <= newY) continue;
            if (v[newX][newY] == '#' && !visited[newX][newY])
            {
                q.push({ newX, newY });
                visited[newX][newY] = true;
            }
        }
    }
}