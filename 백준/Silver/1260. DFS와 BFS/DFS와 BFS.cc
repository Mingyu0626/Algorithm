#include <iostream>>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, V, a, b, result;
vector<vector<int>> v;
vector<bool> visited;

void dfs(int s);
void bfs(int s);

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> V;
	v.assign(n + 1, vector<int>());
	visited.assign(n + 1, false);

	for (int i = 0; i < m; i++) 
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
	
	dfs(V);
	fill(visited.begin(), visited.end(), false);
	bfs(V);
	return 0;
}

void dfs(int s) 
{
	cout << s << ' ';
	visited[s] = true;
	for (int i = 0; i < v[s].size(); i++) 
		if (!visited[v[s][i]]) dfs(v[s][i]);
}

void bfs(int s) 
{
	cout << '\n';
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) 
	{
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int i = 0; i < v[cur].size(); i++) 
		{
			if (!visited[v[cur][i]]) 
			{
				q.push(v[cur][i]);
				visited[v[cur][i]] = true;
			}
		}
	}
}