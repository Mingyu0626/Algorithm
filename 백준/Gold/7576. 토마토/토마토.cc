#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, temp, days = -1, cnt, qSize;
vector<vector<int>> map;
queue<pair<int, int>> q;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y);

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;

	for (int i = 0; i < n; i++) 
	{
		vector<int> mapTemp;
		for (int j = 0; j < m; j++) 
		{
			cin >> temp;
			if (temp == 1) 
			{
				q.push({ i, j });
				cnt++;
			}
			if (temp == -1) cnt++;
			mapTemp.push_back(temp);
		}
		map.push_back(mapTemp);
	}

	if (cnt != n * m) bfs(q.front().first, q.front().second);
	else days = 0;
	cout << days;
	return 0;
}

void bfs(int x, int y) 
{
	while (!q.empty()) 
	{
		qSize = q.size();
		for (int i = 0; i < qSize; i++) 
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) 
			{
				int newX = x + dx[j];
				int newY = y + dy[j];

				if (newX < 0 || newX >= n || newY < 0 || newY >= m)
					continue;
				if (map[newX][newY] == 0) 
				{
					map[newX][newY] = 1;
					q.push({ newX, newY });
					cnt++;
				}
			}
		}
		days++;
	}
	if (cnt != n * m) days = -1;
	return;
}