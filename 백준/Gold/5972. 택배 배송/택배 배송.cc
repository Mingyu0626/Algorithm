#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, m, s, e, d;
vector<int> dist;
Dim2Vec<pii> edges;

void dijkstra(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    dist.assign(n + 1, 1e9);
    edges.assign(n + 1, vector<pii>());
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e >> d;
        edges[s].emplace_back(d, e);
        edges[e].emplace_back(d, s);
    }

    dijkstra(1);
    cout << dist[n];
    return 0;
}

void dijkstra(int start)
{
    priority_queue<pii> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curDist)
        {
            continue;
        }

        for (int i = 0; i < edges[curNode].size(); i++)
        {
            int nextDist = curDist + edges[curNode][i].first;
            int nextNode = edges[curNode][i].second;

            if (nextDist < dist[nextNode])
            {
                pq.push({ -nextDist, nextNode });
                dist[nextNode] = nextDist;
            }
        }
    }
}