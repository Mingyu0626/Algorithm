#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, nodeNum, dest, dist;
int maxNode, maxDist;
vector<pair<int, int>> node[100001];
bool visited[100001] = { false };

void dfs(int a, int curDist);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
  
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> nodeNum >> dest >> dist;
        node[nodeNum].push_back({ dest, dist });
        node[dest].push_back({ nodeNum, dist });
    }
    visited[1] = true;
    dfs(1, 0);

    for (int i = 1; i <= n; i++) visited[i] = false;
    visited[maxNode] = true;
    dfs(maxNode, 0);

    cout << maxDist;
    return 0;
}

void dfs(int a, int curDist)
{
    if (maxDist < curDist)
    {
        maxNode = a;
        maxDist = curDist;
    }

    for (int i = 0; i < node[a].size(); i++)
    {
        int next = node[a][i].first;
        int nextDist = node[a][i].second;

        if (!visited[next])
        {
            visited[next] = true;
            dfs(next, curDist + nextDist);
        }
    }
    return;
}