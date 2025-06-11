#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, m, result;
Dim2Vec<int> v, visited;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int dfs(int y, int x);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin >> n >> m;
	v.assign(n, vector<int>(m));
	visited.assign(n, vector<int>(m, 0));

    char temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            switch (temp)
            {
                case 'U':
                    v[i][j] = 0;
                    break;
                case 'D':
                    v[i][j] = 1;
                    break;
                case 'L':
                    v[i][j] = 2;
                    break;
                case 'R':
                    v[i][j] = 3;
                    break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0)
            {
                dfs(i, j);
            }
        }
    }
    cout << result;
    return 0;
}

int dfs(int y, int x)
{
    visited[y][x] = -1;
    int oper = v[y][x];
    int newY = y + dy[oper];
    int newX = x + dx[oper];

    if (newY < 0 || n <= newY || newX < 0 || m <= newX ||
        visited[newY][newX] != 0)
    {
        if (visited[newY][newX] == -1)
        {
            result++;
        }
        visited[newY][newX] = 1;
        return visited[y][x] = 1;
    }
    return visited[y][x] = dfs(newY, newX);
}