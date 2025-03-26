#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template<typename T>
using Dim2Vec = vector<vector<T>>;

int n, m, result;
Dim2Vec<char> v;
Dim2Vec<int> walls;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int startX, int startY);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(m, vector<char>(n));
    walls.assign(m, vector<int>(n, 1e9));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    bfs(0, 0);

    cout << walls[m - 1][n - 1];
    return 0;
}

void bfs(int startX, int startY)
{
    queue<pair<pair<int, int>, int>> q;
    walls[startX][startY] = 0;
    q.push({ {0, 0}, 0 });

    while (!q.empty())
    {
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curWalls = q.front().second;
        q.pop();

        if (walls[curX][curY] < curWalls) continue;
        
        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (newX < 0 || m <= newX || newY < 0 || n <= newY) continue;

            int nextWalls = curWalls + (v[newX][newY] - '0');
            if (nextWalls < walls[newX][newY])
            {
                q.push({ {newX, newY}, nextWalls });
                walls[newX][newY] = nextWalls;
            }
        }
    }
}