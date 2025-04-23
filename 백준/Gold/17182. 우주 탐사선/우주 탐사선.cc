#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k, result = 1e9;
vector<vector<int>> dist;
vector<bool> visited;

void dfs(int curNode, int visitedNode, int curTimeSum);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
	dist.assign(n, vector<int>(n, 0));
	visited.assign(n, false);
    for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
		}
    }

    for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
		{
            for (int k = 0; k < n; k++)
            {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
		}
    }
    visited[k] = true;
    dfs(k, 1, 0);
    cout << result;
    return 0;
}

void dfs(int curNode, int visitedNode, int curTimeSum)
{
    if (visitedNode == n)
    {
		result = min(result, curTimeSum);
    }

    for (int i = 0; i < n; i++)
    {
        if (curNode == i)
        {
            continue;
        }
        if (!visited[i])
        {
			visited[i] = true;
			dfs(i, visitedNode + 1, curTimeSum + dist[curNode][i]);
			visited[i] = false;
        }
    }
}