#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;
using plli = pair<long long, int>;

int n, m, k, u, v, c;
vector<long long> dist;
Dim2Vec<pii> edges;
plli result = { 0, 0 };

void dijkstra();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    dist.assign(n + 1, LLONG_MAX);
    edges.assign(n + 1, vector<pii>());
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        edges[v].emplace_back(c, u);
    }

    dijkstra();
    cout << result.second << '\n' << result.first;
    return 0;
}

void dijkstra()
{
    priority_queue<plli> pq;
    int interviewRoomNum;
    for (int i = 0; i < k; i++)
    {
        cin >> interviewRoomNum;
        pq.push({ 0, interviewRoomNum });
        dist[interviewRoomNum] = 0;
    }

    while (!pq.empty())
    {
        long long curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curDist)
        {
            continue;
        }

        for (int i = 0; i < edges[curNode].size(); i++)
        {
            long long nextDist = curDist + edges[curNode][i].first;
            int nextNode = edges[curNode][i].second;

            if (nextDist < dist[nextNode])
            {
                pq.push({ -nextDist, nextNode });
                dist[nextNode] = nextDist;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != LLONG_MAX && result.first < dist[i])
        {
            result.second = i, result.first = dist[i];
        }
    }
}