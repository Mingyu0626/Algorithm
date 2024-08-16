#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, maxHeight, numOfArea, result;
vector<vector<int>> v;
vector<vector<bool>> visited;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int a, int b, int r);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	v.assign(n, vector<int>(n, 0));
	visited.assign(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			maxHeight = max(maxHeight, v[i][j]);
		}
	}
	for (int i = 0; i <= maxHeight; i++)
	{
		numOfArea = 0;
		for (vector<bool>& vRow : visited)
		{
			fill(vRow.begin(), vRow.end(), false);
		}

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (v[j][k] > i && !visited[j][k])
				{
					bfs(j, k, i);
					numOfArea++;
				}
			}
		}
		result = max(result, numOfArea);
	}
	cout << result;
	return 0;
}

void bfs(int a, int b, int r)
{
	queue<pair<int, int>> q;
	q.push({ a, b });
	visited[a][b] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int j = 0; j < 4; j++)
		{
			int newX = x + dx[j];
			int newY = y + dy[j];
			if (newX < 0 || n <= newX || newY < 0 || n <= newY)
				continue;
			if (v[newX][newY] > r && !visited[newX][newY])
			{
				q.push({ newX, newY });
				visited[newX][newY] = true;
			}
		}
	}
}