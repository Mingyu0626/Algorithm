#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using Dim2PairIntInt = vector<vector<pair<int, int>>>;

int dijkstra(const int& n, const int& start, const int& end, Dim2PairIntInt& v);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    Dim2PairIntInt v(n + 1, vector<pair<int, int>>());
    int s, e, d;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> s >> e >> d;
        v[s].emplace_back(e, d);
        v[e].emplace_back(s, d);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        cout << dijkstra(n, s, e, v) << '\n';
    }
    return 0;
}

int dijkstra(const int& n, const int& start, const int& end, Dim2PairIntInt& v)
{
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    vector<int> dist(n + 1, 1e9);
    dist[start] = 0;
    while (!q.empty())
    {
        int curNode = q.front().first;
        int curDist = q.front().second;
        q.pop();

        if (dist[curNode] < curDist) continue;

        for (int i = 0; i < v[curNode].size(); i++)
        {
            int nextNode = v[curNode][i].first;
            int nextDist = curDist + v[curNode][i].second;
            if (nextDist < dist[nextNode])
            {
                q.push({ nextNode, nextDist });
                dist[nextNode] = nextDist;
            }
        }
    }
    return dist[end];
}