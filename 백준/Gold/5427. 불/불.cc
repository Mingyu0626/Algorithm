#define first x
#define second y
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>;
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int t, w, h, result;
vector<vector<char>> m(1000, vector<char>(1000));
queue<pii> q, qFire;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t > 0)
    {
        cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> m[i][j];
                if (m[i][j] == '@') q.push({ i, j });
                if (m[i][j] == '*') qFire.push({ i, j });
            }
        }

        result = bfs();
        if (result != -1) cout << result << '\n';
        else cout << "IMPOSSIBLE\n";

        while (!q.empty()) q.pop();
        while (!qFire.empty()) qFire.pop();
        t--;
    }
    return 0;
}

int bfs()
{
    int time = 0;
    while (!q.empty())
    {
        time++;
        int qfSize = qFire.size();
        for (int i = 0; i < qfSize; i++)
        {
            int curX = qFire.front().x;
            int curY = qFire.front().y;
            qFire.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = curX + dx[i];
                int newY = curY + dy[i];
                if (newX < 0 || h <= newX || newY < 0 || w <= newY)
                    continue;
                if (m[newX][newY] == '.')
                {
                    m[newX][newY] = '*';
                    qFire.push({ newX, newY });
                }
            }
        }
        
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int curX = q.front().x;
            int curY = q.front().y;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = curX + dx[i];
                int newY = curY + dy[i];
                if (newX < 0 || h <= newX || newY < 0 || w <= newY)
                    return time;
                if (m[newX][newY] == '.')
                {
                    m[newX][newY] = '@';
                    q.push({ newX, newY });
                }
            }
        }
    }
    return -1;
}