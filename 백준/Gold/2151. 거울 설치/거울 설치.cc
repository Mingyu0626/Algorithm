#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
using Dim3Vec = vector<vector<vector<T>>>;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

struct info
{
    int x, y, dir;
};

int n;
Dim2Vec<char> v;
Dim3Vec<int> visited;
pii goal;
queue<info> q;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs();
bool isValid(const int& x, const int& y);
pii getNewDir(const int& curDir);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<char>(n));
    visited.assign(n, Dim2Vec<int>(n, vector<int>(4, 1e9)));
    int doorCnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[i][j];
            if (v[i][j] == '#')
            {
                if (doorCnt == 0)
                {
                    for (int dir = 0; dir < 4; ++dir)
                    {
                        visited[i][j][dir] = 0;
                        q.push({ i, j, dir });
                    }
                    doorCnt++;
                }
                else
                {
                    goal.first = i, goal.second = j;
                }
            }
        }
    }

    cout << bfs();
    return 0;
}

int bfs()
{
    while (!q.empty())
    {
        info curInfo = q.front();
        q.pop();

        int curUsedMirror = visited[curInfo.x][curInfo.y][curInfo.dir];
        int newX = curInfo.x + dx[curInfo.dir], newY = curInfo.y + dy[curInfo.dir];
        if (!isValid(newX, newY))
        {
            continue;
        }
        info newInfo = { newX, newY, curInfo.dir };

        if (v[newX][newY] == '.' && curUsedMirror < visited[newX][newY][newInfo.dir])
        {
            q.push(newInfo);
            visited[newX][newY][newInfo.dir] = curUsedMirror;
        }
        if (v[newX][newY] == '!')
        {
            if (curUsedMirror < visited[newX][newY][newInfo.dir])
            {
                q.push(newInfo);
                visited[newX][newY][newInfo.dir] = curUsedMirror;
            }
            pii newDir = getNewDir(curInfo.dir);
            if (curUsedMirror + 1 < visited[newX][newY][newDir.first])
            {
                q.push({newX, newY, newDir.first});
                visited[newX][newY][newDir.first] = curUsedMirror + 1;
            }
            if (curUsedMirror + 1 < visited[newX][newY][newDir.second])
            {
                q.push({ newX, newY, newDir.second });
                visited[newX][newY][newDir.second] = curUsedMirror + 1;
            }
        }
        if (v[newX][newY] == '#' && newX == goal.first && newY == goal.second)
        {
            visited[newX][newY][newInfo.dir] =
                min(visited[newX][newY][newInfo.dir], curUsedMirror);
        }
    }

    int result = 1e9;
    for (int i = 0; i < 4; ++i)
    {
        result = min(result, visited[goal.first][goal.second][i]);
    }
    return result;
}

bool isValid(const int& x, const int& y)
{
    return 0 <= x && x < n && 0 <= y && y < n && v[x][y] != '*';
}

pii getNewDir(const int& curDir)
{
    return (curDir <= 1) ? pii{2, 3} : pii{0, 1};
}