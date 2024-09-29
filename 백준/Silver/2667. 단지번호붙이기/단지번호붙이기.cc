#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, cnt;
vector<int> result;
vector<vector<char>> v;
vector<vector<bool>> visited;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int r, int c);

int main() 
{
	ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin >> n;
	v.assign(n, vector<char>(n));
	visited.assign(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> v[i][j];

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (visited[i][j] == false && v[i][j] == '1') 
			{
				cnt = 1;
				visited[i][j] = true;
				dfs(i, j);
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) cout << result[i] << '\n';
	return 0;
}

void dfs(int r, int c) 
{
	for (int i = 0; i < 4; i++) 
	{
		int newR = r + dx[i];
		int newC = c + dy[i];

		if (newR < 0 || newR >= n || newC < 0 || newC >= n)
			continue;

		if (visited[newR][newC] == false && v[newR][newC] == '1')
		{
			cnt++;
			visited[newR][newC] = true;
			dfs(newR, newC);
		}
	}
	return;
}