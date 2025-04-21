#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b, result;
vector<vector<int>> v;
vector<bool> visited;

void bfs(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    bfs(1);
    cout << result;
    return 0;
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int level = 1;
    while (!q.empty() && level <= 2)
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < v[cur].size(); j++)
            {
                int next = v[cur][j];
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                    result++;
                }
            }
        }
        level++;
    }
}