#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std; 

struct coord
{
    int x;
    int y;
    int z;
};

int l, r, c, result;
char map[30][30][30];
bool visited[30][30][30];
int dx[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 1, -1, 0, 0, 0, 0 };

int bfs(coord s);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (true)
    {
        cin >> l >> r >> c;
        if (l == 0) break;
        coord start({0, 0, 0});
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    cin >> map[i][j][k];
                    if (map[i][j][k] == 'S')
                    {
                        start = { i, j, k };
                    }
                    visited[i][j][k] = false;
                }
            }
        }
        result = bfs(start);
        if (result != -1) cout << "Escaped in " << result << " minute(s).\n";
        else cout << "Trapped!\n";
    }
    return 0;
}

int bfs(coord s)
{
    visited[s.x][s.y][s.z] = true;
    queue<coord> q;
    q.push(s);
    int level = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            coord cur = q.front();
            q.pop();
            if (map[cur.x][cur.y][cur.z] == 'E') return level;
            
            for (int i = 0; i < 6; i++)
            {
                int newX = cur.x + dx[i];
                int newY = cur.y + dy[i];
                int newZ = cur.z + dz[i];
                if (newX < 0 || l <= newX ||
                    newY < 0 || r <= newY || newZ < 0 || c <= newZ) continue;
                if (!visited[newX][newY][newZ] && map[newX][newY][newZ] != '#')
                {
                    q.push({ newX, newY, newZ });
                    visited[newX][newY][newZ] = true;
                }
            }
        }
        level++;
    }
    return -1;
}