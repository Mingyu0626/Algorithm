#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

Dim2Vec<char> v;
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

void bfs();
bool isValid(int x, int y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    v.assign(8, vector<char>(8));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> v[i][j];
        }
    }

    bfs();
    return 0;
}

void bfs()
{
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    visited[7][0] = true;
    queue<pii> q;
    q.push({ 7, 0 });

    queue<pii> wallQueue;
    for (int i = 7; i >= 0; i--)
    {
        for (int j = 0; j < 8; j++)
        {
            if (v[i][j] == '#')
            {
                wallQueue.push({ i, j });
            }
        }
    }

    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            pii cur = q.front();
            q.pop();

            if (cur.first == 0 && cur.second == 7)
            {
                cout << 1;
                exit(0);
            }

            if (v[cur.first][cur.second] == '.')
            {
                for (int j = 0; j < 8; j++)
                {
                    int newX = cur.first + dx[j], newY = cur.second + dy[j];
                    if (isValid(newX, newY) && !visited[newX][newY]
                        && v[newX][newY] == '.')
                    {
                        q.push({ newX, newY });
                        visited[newX][newY] = true;
                    }
                }
                q.push({ cur.first, cur.second });
            }
        }

        int wallQueueSize = wallQueue.size();
        for (int i = 0; i < wallQueueSize; i++)
        {
            int curX = wallQueue.front().first;
            int curY = wallQueue.front().second;
            wallQueue.pop();
            v[curX][curY] = '.';
            if (isValid(curX + 1, curY))
            {
                v[curX + 1][curY] = '#';
                wallQueue.push({ curX + 1, curY });
            }
        }
        
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                visited[i][j] = false;
            }
        }
    }
    cout << 0;
}

bool isValid(int x, int y)
{
    return 0 <= x && x < 8 && 0 <= y && y < 8;
}