#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <limits>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>

using namespace std;
using pii = pair<int, int>;

vector<vector<pii>> edges;
vector<bool> visited;

int prim();

int solution(int n, vector<vector<int>> costs) 
{
    edges.assign(n, vector<pii>());
    visited.assign(n, false);
    for (int i = 0; i < costs.size(); ++i)
    {
        edges[costs[i][0]].emplace_back(-costs[i][2], costs[i][1]);
        edges[costs[i][1]].emplace_back(-costs[i][2], costs[i][0]);
    }
    return prim();
}

int prim()
{
    int result = 0;
    visited[0] = true;
    priority_queue<pii> pq;
    for (int i = 0; i < edges[0].size(); ++i)
    {
        pq.push(edges[0][i]);
    }
    
    while (!pq.empty())
    {
        int nextCost = -pq.top().first;
        int nextNode = pq.top().second;
        pq.pop();
        
        if (visited[nextNode])
        {
            continue;
        }
        
        visited[nextNode] = true;
        result += nextCost;
        
        for (int i = 0; i < edges[nextNode].size(); ++i)
        {
            if (!visited[edges[nextNode][i].second])
            {
                pq.push(edges[nextNode][i]);
            }
        }
    }
    return result;
}