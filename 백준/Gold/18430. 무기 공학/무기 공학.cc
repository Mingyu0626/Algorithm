#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, m, result;
Dim2Vec<int> v;
Dim2Vec<bool> visited;

int dx[5] = { 1, 0, -1, 0, 1 };
int dy[5] = { 0, -1, 0, 1, 0 };

void makeBoomerang(int x, int y, int sum);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    makeBoomerang(0, 0, 0);
    cout << result;
    return 0;
}

void makeBoomerang(int x, int y, int sum)
{
    result = max(result, sum);
    if (y == m)
    {
        y = 0, x++;
        if (x == n)
        {
            return;
        }
    }

    if (!visited[x][y])
    {
        for (int i = 0; i < 4; i++)
        {
            int newX1 = x + dx[i], newY1 = y + dy[i];
            int newX2 = x + dx[i + 1], newY2 = y + dy[i + 1];

            if (0 <= newX1 && newX1 < n && 0 <= newY1 && newY1 < m &&
                0 <= newX2 && newX2 < n && 0 <= newY2 && newY2 < m &&
                !visited[newX1][newY1] && !visited[newX2][newY2])
            {
                visited[x][y] = true, visited[newX1][newY1] = true, visited[newX2][newY2] = true;
                int strength = (v[x][y] * 2) + v[newX1][newY1] + v[newX2][newY2];
                makeBoomerang(x, y + 1, sum + strength);
                visited[x][y] = false, visited[newX1][newY1] = false, visited[newX2][newY2] = false;
            }
        }
    }
    makeBoomerang(x, y + 1, sum);
}