#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m, a, b, c;
vector<vector<pii>> v;

void dijkstra(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n + 1, vector<pii>());
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].emplace_back(b, c);
    }

    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
    }

    return 0;
}

void dijkstra(int start)
{
    vector<int> dist(n + 1, 1e9);
    dist[start] = 0;
    priority_queue<pii> pq;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (dist[curNode] < curDist) continue;

        for (int i = 0; i < v[curNode].size(); i++)
        {
            int nextNode = v[curNode][i].first;
            int nextDist = dist[curNode] + v[curNode][i].second;
            if (nextDist < dist[nextNode])
            {
                dist[nextNode] = nextDist;
                pq.push({ nextDist, nextNode });
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == 1e9) cout << 0 << ' ';
        else cout << dist[i] << ' ';
    }
    cout << '\n';
}