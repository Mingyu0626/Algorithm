#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, m, x, y, a, b, result;
Dim2Vec<bool> isBright, visited;
map<pii, vector<pii>> switchInfo;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs();
bool isValid(int x, int y);
bool accessible(int x, int y);
void calculateResult();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    isBright.assign(n + 1, vector<bool>(n + 1, false));
    visited.assign(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> a >> b;
        switchInfo[{x, y}].emplace_back(a, b);
    }

    bfs();
    calculateResult();
    cout << result;
    return 0;
}

void bfs()
{
    queue<pii> q;
    q.push({ 1, 1 });
    visited[1][1] = true;
    isBright[1][1] = true;
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        if (switchInfo.find({ curX, curY }) != switchInfo.end())
        {
            for (auto& brightedRoom : switchInfo[{curX, curY}])
            {
                if (isBright[brightedRoom.first][brightedRoom.second])
                {
                    continue;
                }

                isBright[brightedRoom.first][brightedRoom.second] = true;

                if (accessible(brightedRoom.first, brightedRoom.second))
                {
                    visited[brightedRoom.first][brightedRoom.second] = true;
                    q.push({ brightedRoom.first, brightedRoom.second });
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!visited[i][j] && isBright[i][j] && accessible(i, j))
                {
                    visited[i][j] = true;
                    q.push({ i, j });
                }
            }
        }
    }
}

bool isValid(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

bool accessible(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY) && visited[newX][newY])
        {
            return true;
        }
    }
    return false;
}

void calculateResult()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (isBright[i][j])
            {
                result++;
            }
        }
    }
}