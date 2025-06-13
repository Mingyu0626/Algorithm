#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, m, X1, Y1, X2, Y2, result = 1;
Dim2Vec<char> v;
Dim2Vec<bool> visited;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool bfs();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> X1 >> Y1 >> X2 >> Y2;
	v.assign(n + 1, vector<char>(m + 1));
    visited.assign(n + 1, vector<bool>(m + 1, false));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
		}
    }
    while (!bfs())
    {
        result++;
    }
    cout << result;
    return 0;
}

bool bfs()
{
    queue<pair<int, int>> q;
    Dim2Vec<bool> visited(n + 1, vector<bool>(m + 1, false));
    q.push({ X1, Y1 });
    visited[X1][Y1] = true;

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (newX < 1 || n < newX || newY < 1 || m < newY
                || visited[newX][newY])
            {
                continue;
            }

            if (v[newX][newY] == '#')
            {
                return true;
            }

            visited[newX][newY] = true;
            if (v[newX][newY] == '1')
            {
                v[newX][newY] = 0;
            }
            else
            {
                q.push({ newX, newY });
            }
        }
    }
    return false;
}