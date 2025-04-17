#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, m, s, e, result;
vector<vector<pair<int, int>>> v;

bool bfs(int mid);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n + 1, vector<pair<int, int>>());

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }
    cin >> s >> e;
    int left = 1, right = 1e9, mid = 0;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        if (bfs(mid))
        {
            left = mid + 1;
            result = max(result, mid);
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result;
    return 0;
}

bool bfs(int mid)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == e)
        {
            return true;
        }

        for (int i = 0; i < v[cur].size(); i++)
        {
            int nextIsland = v[cur][i].first;
            int nextBridge = v[cur][i].second;

            if (!visited[nextIsland] && mid <= nextBridge)
            {
                q.push(nextIsland);
                visited[nextIsland] = true;
            }
        }
    }
    return false;
}