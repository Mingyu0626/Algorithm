#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, info;
vector<int> v[201], road;
bool visited[201];

void bfs(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    road.assign(m, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> info;
            if (info == 1)
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < m; i++) cin >> road[i];
    bfs(road[0]);
    for (int i = 0; i < m; i++)
    {
        if (!visited[road[i]])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}