#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, nodeNum;
int maxNode, maxDist, result;
vector<pair<int, int>> node[100001];
bool visited[100001] = { false };

void dfs(int a, int curDist);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> v;
  
    for (int i = 1; i <= v; i++)
    {
        cin >> nodeNum;
        int dest = 0, dist = 0;
        while (dest != -1)
        {
            cin >> dest;
            if (dest == -1) break;
            cin >> dist;
            node[nodeNum].push_back({ dest, dist });
        }
    }
    visited[1] = true;
    dfs(1, 0);

    for (int i = 1; i <= v; i++) visited[i] = false;
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
