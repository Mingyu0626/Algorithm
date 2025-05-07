#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b, temp;
vector<pair<int, int>> cost[1001];
vector<int> d(1001, 1e8);
vector<int> prevNode(1001);
vector<int> result;
priority_queue<pair<int, int>> pq;

void dijkstra();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, dest, costs;
        cin >> start >> dest >> costs;
        cost[start].push_back({ dest, costs });
    }
    cin >> a >> b;
    pq.push({ 0, a });
    d[a] = 0;

    dijkstra();

    temp = prevNode[b];
    result.push_back(b);
    while (temp != a) 
    {
        result.push_back(temp);
        temp = prevNode[temp];
    }
    result.push_back(a);

    cout << d[b] << "\n" << result.size() << "\n";
    for (int i = result.size() - 1; i >= 0; i--) cout << result[i] << " ";
    return 0;
}

void dijkstra()
{
    while (!pq.empty())
    {
        int distance = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if (d[curNode] < distance) continue;

        for (int i = 0; i < cost[curNode].size(); i++)
        {
            int destNode = cost[curNode][i].first;
            int total = distance + cost[curNode][i].second;
            if (total < d[destNode])
            {
                prevNode[destNode] = curNode;
                d[destNode] = total;
                pq.push({ -total, destNode });
            }
        }
    }
}