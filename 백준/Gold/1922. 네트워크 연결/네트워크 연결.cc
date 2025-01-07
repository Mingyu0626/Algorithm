#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, a, b, c, mstSize, result;
vector<vector<pair<int, int>>> v;
vector<bool> visited;
priority_queue<pair<int, int>> pq;

void prim(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    visited.assign(n + 1, false);
    v.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].emplace_back(c, b);
        v[b].emplace_back(c, a);
    }
    prim(1);
    cout << result;
    return 0;
}

void prim(int start)
{
    visited[start] = true;
    mstSize = 1;
    for (int i = 0; i < v[start].size(); i++)
    {
        int nextCost = v[start][i].first;
        int nextNode = v[start][i].second;
        if (!visited[nextNode]) pq.push({ -nextCost, nextNode });
    }

    while (!pq.empty())
    {
        int curCost = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (visited[curNode]) continue;

        
        visited[curNode] = true;
        result += curCost;
        mstSize++;
        if (mstSize == n) return;

        for (int i = 0; i < v[curNode].size(); i++)
        {
            int nextCost = v[curNode][i].first;
            int nextNode = v[curNode][i].second;
            if(!visited[nextNode]) pq.push({ -nextCost, nextNode });
        }
    }
}