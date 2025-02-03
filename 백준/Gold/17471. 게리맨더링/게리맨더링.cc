#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, result = 1e9;
vector<int> p;
vector<vector<int>> edges;

void dfs(const int nodeNum, int sum1, vector<int> ward1, vector<int>& visited);
bool bfs(const int wardNum, const vector<int>& ward, vector<int> visited);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    p.assign(n + 1, 0);
    vector<int> visited(n + 1, 2);
    edges.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) cin >> p[i];

    
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        edges[i].assign(k, 0);
        for (int j = 0; j < k; j++) cin >> edges[i][j];
    }

    int sum1 = 0;
    vector<int> ward1;

    for (int i = 1; i <= n; i++)
    {
        visited[i] = 1;
        dfs(i, sum1, ward1, visited);
        visited[i] = 2;
    }

    if (result == 1e9) cout << -1;
    else cout << result;
    return 0;
}

void dfs(const int nodeNum, int sum1, vector<int> ward1, vector<int>& visited)
{
    sum1 += p[nodeNum];
    ward1.emplace_back(nodeNum);

    if (ward1.size() == n) return;

    int sum2 = 0;
    vector<int> ward2;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 2)
        {
            ward2.emplace_back(i);
            sum2 += p[i];
        }
    }

    if (bfs(1, ward1, visited) && bfs(2, ward2, visited))
    {
        result = min(result, abs(sum1 - sum2));
    }
    
    for (int i = nodeNum; i <= n; i++)
    {
        if (visited[i] == 2)
        {
            visited[i] = 1;
            dfs(i, sum1, ward1, visited);
            visited[i] = 2;
        }
    }
}

bool bfs(const int wardNum, const vector<int>& ward, vector<int> visited)
{
    if (ward.size() == 0) return false;
    queue<int> q;
    visited[ward[0]] = 0;
    int wardSize = 1;
    q.push(ward[0]);

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        for (int i = 0; i < edges[curNode].size(); i++)
        {
            int nextNode = edges[curNode][i];
            if (visited[nextNode] == wardNum)
            {
                visited[nextNode] = 0;
                wardSize++;
                q.push(nextNode);
            }
        }
    }
    return wardSize == ward.size();
}