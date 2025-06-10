#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template<typename T>
using Dim2Vec = vector<vector<T>>;

int r, c, sheep, wolf;
Dim2Vec<char> v;
Dim2Vec<bool> visited;

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void bfs(int startR, int startC);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> r >> c;
    v.assign(r, vector<char>(c));
    visited.assign(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (v[i][j] != '#' && !visited[i][j])
            {
                bfs(i, j);
            }
        }
    }

    cout << sheep << ' ' << wolf;
    return 0;
}

void bfs(int startR, int startC)
{
    queue<pair<int, int>> q;
    q.push({ startR, startC });
    visited[startR][startC] = true;

    int sheepInArea = 0, wolfInArea = 0;
    while (!q.empty())
    {
        int curR = q.front().first;
        int curC = q.front().second;
        char cur = v[curR][curC];
        q.pop();

        if (cur == 'o')
        {
            sheepInArea++;
        }
        if (cur == 'v')
        {
            wolfInArea++;
        }

        for (int i = 0; i < 4; i++)
        {
            int newR = curR + dr[i];
            int newC = curC + dc[i];
            if (newR < 0 || r <= newR || newC < 0 || c <= newC
                || visited[newR][newC] || v[newR][newC] == '#')
            {
                continue;
            }
            q.push({ newR, newC });
            visited[newR][newC] = true;
        }
    }
    if (wolfInArea < sheepInArea)
    {
        sheep += sheepInArea;
    }
    else
    {
        wolf += wolfInArea;
    }
}