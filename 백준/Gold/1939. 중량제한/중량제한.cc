#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, a, b, c, result;
int f1, f2, l = 1, r, mid;
vector<pair<int, int>> adj[10001];

bool bfs(int midVal);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
        r = max(c, r);
    }
    cin >> f1 >> f2;
    while (l <= r)
    {
        mid = (r - l) / 2 + l;
        if (bfs(mid))
        {
            result = max(result, mid);
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << result;
    return 0;
}

bool bfs(int midVal)
{
    queue<int> q;
    vector<bool> visited(n + 1, false);
    q.push(f1);
    visited[f1] = true;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        if (curNode == f2)
        {
            return true;
        }

        for (int i = 0; i < adj[curNode].size(); i++)
        {
            int nextNode = adj[curNode][i].first;
            int curLimit = adj[curNode][i].second;
            if (midVal <= curLimit && !visited[nextNode])
            {
                q.push(nextNode);
                visited[nextNode] = true;
            }
        }
    }
    return false;
}