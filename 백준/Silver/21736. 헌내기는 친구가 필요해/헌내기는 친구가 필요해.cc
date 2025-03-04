#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, m, result;
pii start;
Dim2Vec<char> campus;
Dim2Vec<bool> visited;

void bfs(const pii& start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    campus.assign(n, vector<char>(m));
    visited.assign(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> campus[i][j];
            if (campus[i][j] == 'I')
            {
                start = { i, j };
            }
        }
    }

    bfs(start);
    if (result == 0) cout << "TT";
    else cout << result;
    return 0;
}

void bfs(const pii& start)
{
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        if (campus[curX][curY] == 'P') result++;

        int dx[4] = { 0, 0, 1, -1 };
        int dy[4] = { 1, -1, 0, 0 };
        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (newX < 0 || n <= newX || newY < 0 || m <= newY) continue;
            if (!visited[newX][newY] && campus[newX][newY] != 'X')
            {
                q.push({ newX, newY });
                visited[newX][newY] = true;
            }
        }
    }
}