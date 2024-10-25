#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, result;
int f1, f2;
vector<pair<int, int>> adj[10001];

bool bfs(int midVal);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a, b, c;
    int left = 1, right = 0, mid = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
        right = max(c, right);
    }
    cin >> f1 >> f2;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        if (bfs(mid))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result;
    return 0;
}

bool bfs(int midVal)
{
    queue<int> q;
    q.push(f1);
    vector<bool> visited(n + 1, false);
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