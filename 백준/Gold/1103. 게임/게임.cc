#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template<typename T>
using Dim2Vec = vector<vector<T>>;

int n, m, result;
Dim2Vec<char> v;
Dim2Vec<int> dp;
Dim2Vec<bool> visited;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int level);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, vector<char>(m));
    dp.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> v[i][j];
        
    dfs(0, 0, 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) result = max(result, dp[i][j]);
        
    cout << result;
    return 0;
}

void dfs(int x, int y, int level)
{
    visited[x][y] = true;
    dp[x][y] = max(dp[x][y], level);
    int num = v[x][y] - '0';
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i] * num;
        int newY = y + dy[i] * num;
        if (newX < 0 || n <= newX || newY < 0 || m <= newY || v[newX][newY] == 'H')
        {
            continue;
        }
        if (!visited[newX][newY])
        {
            if (dp[newX][newY] < level + 1)
            {
                dfs(newX, newY, level + 1);
            }
        }
        else
        {
            cout << -1;
            exit(0);
        }
    }
    visited[x][y] = false;
}