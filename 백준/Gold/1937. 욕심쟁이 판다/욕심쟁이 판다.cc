#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, result;
vector<vector<int>> v, dp;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<int>(n));
    dp.assign(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == 1)
            {
                dfs(i, j);
            }
            result = max(result, dp[i][j]);
        }
    }
    cout << result;
}

int dfs(int x, int y)
{
    int moveNum = 1;
    int curVal = v[x][y];
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX < 0 || n <= newX || newY < 0 || n <= newY) continue;

        int newVal = v[newX][newY];

        if (curVal < newVal)
        {
            if (dp[newX][newY] != 1)
            {
                moveNum = max(moveNum, dp[newX][newY] + 1);
            }
            else
            {
                moveNum = max(moveNum, dfs(newX, newY));
            }
        }
    }
    dp[x][y] = moveNum;
    return moveNum + 1;
}