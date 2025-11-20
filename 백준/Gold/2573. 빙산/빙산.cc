#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, m, result;
Dim2Vec<int> v;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void meltIceberg(int x, int y, Dim2Vec<bool>& visited);
int countChunk();
void bfs(int x, int y, Dim2Vec<bool>& visited);
bool isValid(const int& x, const int& y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    while (countChunk() != 0 && countChunk() < 2)
    {
        Dim2Vec<bool> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] != 0 && !visited[i][j])
                {
                    meltIceberg(i, j, visited);
                }
            }
        }
        result++;
    }

    result = countChunk() == 0 ? 0 : result;
    cout << result;
    return 0;
}

void meltIceberg(int x, int y, Dim2Vec<bool>& visited)
{
    queue<pii> q;
    q.push({ x, y });
    visited[x][y] = true;
    while (!q.empty())
    {
        int curX = q.front().first, curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i], newY = curY + dy[i];
            if (isValid(newX, newY) && !visited[newX][newY])
            {
                if (v[newX][newY] == 0)
                {
                    v[curX][curY]--;
                }
                else
                {
                    q.push({ newX, newY });
                    visited[newX][newY] = true;
                }
            }
        }
        v[curX][curY] = max(0, v[curX][curY]);
    }
}

int countChunk()
{
    Dim2Vec<bool> visited(n, vector<bool>(m, false));
    int numOfChunks = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] != 0 && !visited[i][j])
            {
                bfs(i, j, visited);
                numOfChunks++;
            }
        }
    }
    return numOfChunks;
}

void bfs(int x, int y, Dim2Vec<bool>& visited)
{
    queue<pii> q;
    q.push({ x, y });
    visited[x][y] = true;
    while (!q.empty())
    {
        int curX = q.front().first, curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i], newY = curY + dy[i];
            if (isValid(newX, newY) && !visited[newX][newY] && v[newX][newY] != 0)
            {
                q.push({ newX, newY });
                visited[newX][newY] = true;
            }
        }
    }
}

bool isValid(const int& x, const int& y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}
