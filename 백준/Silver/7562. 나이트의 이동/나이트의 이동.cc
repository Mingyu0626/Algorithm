#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int t, l, X1, Y1, X2, Y2, result;
int dx[8] = { 2, 2, 1, 1 , -2, -2, -1, -1 };
int dy[8] = { 1, -1, -2, 2, 1, -1, -2, 2 };

void bfs(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t > 0)
	{
		cin >> l >> X1 >> Y1 >> X2 >> Y2;
		bfs(X1, Y1);
		t--;
	}
	return 0;
}

void bfs(int a, int b)
{
	queue<pair<pair<int, int>, int>> q;
	vector<vector<bool>> visited(l, vector<bool>(l, false));
	q.push({ {a, b}, 0 });
	visited[a][b] = true;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curMove = q.front().second;
		q.pop();

		if (x == X2 && y == Y2)
		{
			cout << curMove << '\n';
			return;
		}

		for (int j = 0; j < 8; j++)
		{
			int newX = x + dx[j], newY = y + dy[j];

			if (newX < 0 || l <= newX || newY < 0 || l <= newY)
				continue;
			if (!visited[newX][newY])
			{
				q.push({ {newX, newY}, curMove + 1 });
				visited[newX][newY] = true;
			}
		}
	}
}