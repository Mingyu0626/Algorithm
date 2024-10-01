#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, result;
int v[501][501], dp[501][501];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i <= 500; i++) fill_n(dp[i], 501, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) result = max(result, dfs(i, j));
        
    cout << result;
}

int dfs(int x, int y)
{
    if (dp[x][y] != 1) return dp[x][y];

    int moveNum = 1;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i], newY = y + dy[i];
        if (newX < 0 || n <= newX || newY < 0 || n <= newY) continue;

        if (v[x][y] < v[newX][newY])
        {
            if (dp[newX][newY] != 1)
            {
                moveNum = max(moveNum, dp[newX][newY] + 1);
            }
            else
            {
                moveNum = max(moveNum, dfs(newX, newY) + 1);
            }
        }
    }
    dp[x][y] = moveNum;
    return moveNum;
}