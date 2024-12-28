#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

int n, m, a, b;
vector<pair<int, int>> cost[1001];
vector<int> d(1001, 1e9);
priority_queue<pair<int, int>> pq;

void dijkstra();

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, dest, costs;
        cin >> start >> dest >> costs;
        cost[start].push_back({ dest, costs });
    }
    cin >> a >> b;
    pq.push({ a, 0 });
    d[a] = 0;
    dijkstra();
    cout << d[b];
    return 0;
}

void dijkstra()
{
    while (!pq.empty())
    {
        int curNode = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if (d[curNode] < distance) continue;
        for (int i = 0; i < cost[curNode].size(); i++)
        {
            int destNode = cost[curNode][i].first;
            int newDistance = distance + cost[curNode][i].second;
            if (newDistance < d[destNode])
            {
                d[destNode] = newDistance;
                pq.push({ destNode, -newDistance });
            }
        }
    }
}