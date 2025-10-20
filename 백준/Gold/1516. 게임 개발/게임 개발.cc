#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, m;
vector<int> id, t, result;
Dim2Vec<int> edges;

void topologySort();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    id.assign(n + 1, 0), t.assign(n + 1, 0), result.assign(n + 1, 0);
    edges.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i];
        while (cin >> m && m != -1)
        {
            id[i]++;
            edges[m].emplace_back(i);
        }
    }

    topologySort();
    for (int i = 1; i <= n; ++i)
    {
        cout << result[i] << '\n';
    }
    return 0;
}

void topologySort()
{
    queue<pii> q;
    for (int i = 1; i <= n; ++i)
    {
        if (id[i] == 0)
        {
            q.push({i, t[i]});
            result[i] = t[i];
        }
    }

    while (!q.empty())
    {
        int curNode = q.front().first;
        int curTime = q.front().second;
        q.pop();

        for (int j = 0; j < edges[curNode].size(); ++j)
        {
            int nextNode = edges[curNode][j];
            result[nextNode] = max(result[nextNode], curTime);

            id[nextNode]--;
            if (id[nextNode] == 0)
            {
                result[nextNode] += t[nextNode];
                q.push({nextNode, result[nextNode]});
            }
        }
    }
}