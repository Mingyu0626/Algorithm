#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, r;
vector<int> d, item;
vector<pair<int, int>> edge[1001];

int dijkstra(int startNode);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> r;
    d.assign(n + 1, 0), item.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> item[i];

    int a, b, l;
    for (int i = 0; i < r; i++)
    {
        cin >> a >> b >> l;
        if (m < l) continue;
        edge[a].emplace_back(b, l);
        edge[b].emplace_back(a, l);
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result = max(result, dijkstra(i));
    }
    cout << result;
    return 0;
}

int dijkstra(int startNode)
{
    for (int i = 1; i <= n; i++) d[i] = 1e9;
    d[startNode] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ startNode, 0 });

    while (!pq.empty())
    {
        int curNode = pq.top().first;
        int curDist = pq.top().second;
        pq.pop();

        if (d[curNode] < curDist) continue;

        for (int i = 0; i < edge[curNode].size(); i++)
        {
            int nextNode = edge[curNode][i].first;
            int nextDist = curDist + edge[curNode][i].second;
            if (nextDist < d[nextNode])
            {
                d[nextNode] = nextDist;
                pq.push({ nextNode, nextDist });
            }
        }
    }

    int numOfItems = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] <= m)
        {
            numOfItems += item[i];
        }
    }
    return numOfItems;
}