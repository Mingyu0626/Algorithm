#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

template<typename T>
using Dim2Vec = vector<vector<T>>;

int n, m, k, a, b;
vector<int> candies;

Dim2Vec<int> adj;
vector<bool> visited;

vector<pair<int, int>> candyInfo;
Dim2Vec<int> dp;

void makeCandyInfo();
void bfs(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    candies.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> candies[i];
    }

    adj.assign(n + 1, vector<int>());
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    makeCandyInfo();

    dp.assign(candyInfo.size() + 1, vector<int>(k, 0));
    for (int i = 1; i <= candyInfo.size(); i++)
    {
        int numOfChildren = candyInfo[i - 1].first;
        int numOfCandies = candyInfo[i - 1].second;
        for (int j = 1; j < k; j++)
        {
            if (0 <= j - numOfChildren)
            {
                dp[i][j] =
                    max(dp[i - 1][j],
                        dp[i - 1][j - numOfChildren] + numOfCandies);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[candyInfo.size()][k - 1];
    return 0;
}

void makeCandyInfo()
{
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }
}

void bfs(int start)
{
    visited[start] = true;
    queue<int> q;
    q.push(start);

    int numOfCandies = 0, numOfChildren = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        numOfChildren++;
        numOfCandies += candies[cur];

        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    candyInfo.emplace_back(numOfChildren, numOfCandies);
}