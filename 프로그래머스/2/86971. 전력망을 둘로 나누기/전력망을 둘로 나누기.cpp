#include <string>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int bfs(int n, const vector<vector<int>>& edges);

int solution(int n, vector<vector<int>> wires) 
{
    int result = n;
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; ++i)
    {
        edges.assign(n + 1, vector<int>());
        for (int j = 0; j < n - 1; ++j)
        {
            if (i == j)
            {
                continue;
            }
            edges[wires[j][0]].emplace_back(wires[j][1]);
            edges[wires[j][1]].emplace_back(wires[j][0]);
        }
        result = min(result, bfs(n, edges));
    }
    return result;
}

int bfs(int n, const vector<vector<int>>& edges)
{
    vector<bool> visited(n, false);
    visited[1] = true;
    queue<int> q;
    q.push(1);
    
    int cnt = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < edges[cur].size(); ++i)
        {
            int next = edges[cur][i];
            if (!visited[next])
            {
                q.push(next);
                cnt++;
                visited[next] = true;
            }
        }
    }
    return abs(cnt - (n - cnt));
}