#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, m, a, b;
Dim2Vec<int> edges;
vector<bool> visited;

void bfs(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    edges.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edges[a].emplace_back(b);
        edges[b].emplace_back(a);
    }
    bfs(1);
    return 0;
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int minBarn = start, maxDistance = -1, sameDistanceBarn = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        minBarn = 20001;
        maxDistance++;
        sameDistanceBarn = qSize;
        for (int i = 0; i < qSize; i++)
        {
            int cur = q.front();
            q.pop();
            minBarn = min(minBarn, cur);
            for (int j = 0; j < edges[cur].size(); j++)
            {
                int next = edges[cur][j];
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    cout << minBarn << ' ' << maxDistance << ' ' << sameDistanceBarn << '\n';
}