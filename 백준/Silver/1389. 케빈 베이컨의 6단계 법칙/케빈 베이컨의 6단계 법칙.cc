#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, m;
Dim2Vec<int> v;
vector<int> kb;

void bfs(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n + 1, vector<int>());
    kb.assign(n + 1, 0);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

    for (int i = 1; i <= n; i++) bfs(i);
    
    int minKb = 1e9, result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (kb[i] < minKb)
        {
            minKb = kb[i];
            result = i;
        }
    }
    cout << result;
    return 0;
}

void bfs(int start)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int level = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < v[cur].size(); j++)
            {
                int next = v[cur][j];
                if (dist[next] == -1)
                {
                    q.push(next);
                    dist[next] = level;
                }
            }
        }
        level++;
    }
    for (int i = 1; i <= n; i++) kb[start] += dist[i];
}