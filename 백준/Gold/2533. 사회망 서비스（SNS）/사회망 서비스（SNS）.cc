#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <limits.h>

using namespace std;

int n, u, v;
vector<int> node[1000001];
int dp[1000001][2];
bool visited[1000001];

void dfs(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}

void dfs(int curNode)
{
    visited[curNode] = true;
    for (int i = 0; i < node[curNode].size(); i++)
    {
        int nextNode = node[curNode][i];
        if (!visited[nextNode])
        {
            dfs(nextNode);
            dp[curNode][0] += dp[nextNode][1];
            dp[curNode][1] += min(dp[nextNode][0], dp[nextNode][1]);
        }
    }
}