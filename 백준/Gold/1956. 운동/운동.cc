#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int v, e, a, b, c, start, result = 1e9;
vector<vector<pair<int, int>>> adj(401, vector<pair<int, int>>());

int dijkstra(const int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    for (int i = 1; i <= v; i++)
    {
        result = min(result, dijkstra(i));
    }

    if (result == 1e9) cout << -1;
    else cout << result;
    return 0;
}

int dijkstra(const int start)
{
    vector<int> dist(401, 1e9);
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost) continue;

        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i].first;
            int newCost = cost + adj[cur][i].second;
 
            if (newCost < dist[next])
            {
                pq.push({ -newCost, next });
                dist[next] = newCost;
            }
        }
    }
    if (dist[start] != 1e9) return dist[start];
    return 1e9;
}