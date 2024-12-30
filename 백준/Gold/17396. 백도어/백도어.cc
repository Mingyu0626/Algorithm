#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int n, m, a, b, t;
vector<int> v;
vector<long long> d;
vector<vector<pair<int, int>>> edge;
priority_queue<pair<long long, int>> pq;

void dijkstra();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, 0), d.assign(n, LLONG_MAX), edge.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        if ((v[a] == 1 && a != n - 1) ||
            v[b] == 1 && b != n - 1) continue;
        
        edge[a].push_back({ t, b });
        edge[b].push_back({ t, a });
    }
    pq.push({0, 0});
    d[0] = 0;
    dijkstra();

    if (d[n - 1] == LLONG_MAX) cout << -1;
    else cout << d[n - 1];
    return 0;
}

void dijkstra()
{
    while (!pq.empty())
    {
        long long curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (d[curNode] < curDist) continue;

        for (int i = 0; i < edge[curNode].size(); i++)
        {
            long long nextDist = edge[curNode][i].first;
            int nextNode = edge[curNode][i].second;
            if (curDist + nextDist < d[nextNode])
            {
                d[nextNode] = curDist + nextDist;
                pq.push({ -d[nextNode], nextNode });
            }
        }
    }
}