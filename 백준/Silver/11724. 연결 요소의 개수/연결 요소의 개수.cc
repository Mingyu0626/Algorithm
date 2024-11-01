#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, m, result;
vector<int> adj[1001];
bool visited[1001];

void bfs(int s);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
            result++;
        }
    }
    cout << result;
    return 0;
}

void bfs(int s)
{
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}