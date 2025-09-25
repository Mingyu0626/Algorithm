#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int m, n;
Dim2Vec<char> v;
Dim2Vec<bool> visited;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    v.assign(m, vector<char>(n)), visited.assign(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[i][j];
        }
    }
    bfs();
    return 0;
}

void bfs()
{
    queue<pii> q;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[0][i] && v[0][i] == '0')
        {
            q.push({ 0, i });
            visited[0][i] = true;
        }
    }

    while (!q.empty())
    {
        int curX = q.front().first, curY = q.front().second;
        q.pop();

        if (curX == m - 1)
        {
            cout << "YES";
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int newX = curX + dx[i], newY = curY + dy[i];
            if (0 <= newX && newX < m && 0 <= newY && newY < n &&
                !visited[newX][newY] && v[newX][newY] == '0')
            {
                q.push({ newX, newY });
                visited[newX][newY] = true;
            }
        }
    }
    cout << "NO";
}
