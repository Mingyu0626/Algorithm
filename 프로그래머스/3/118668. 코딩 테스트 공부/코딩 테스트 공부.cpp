#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
using Dim2Vec = vector<vector<T>>;

Dim2Vec<int> dist;
vector<bool> isClear;
int n, alp, cop, goalAlp, goalCop;

int dijkstra(const vector<vector<int>>& problems);

int solution(int ALP, int COP, vector<vector<int>> problems) 
{
    n = problems.size(), alp = ALP, cop = COP;
    dist.assign(151, vector<int>(151, 1e9));
    
    for (int i = 0; i < n; ++i)
    {
        goalAlp = max(goalAlp, problems[i][0]);
        goalCop = max(goalCop, problems[i][1]);
    }
    return dijkstra(problems);
}

int dijkstra(const vector<vector<int>>& problems)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {alp, cop}});
    dist[alp][cop] = 0;
    
    while (!pq.empty())
    {
        int curCost = -pq.top().first;
        int curAlp = pq.top().second.first, curCop = pq.top().second.second;
        pq.pop();
        
        if (curCost < dist[curAlp][curCop])
        {
            continue;
        }
        if (goalAlp <= curAlp && goalCop <= curCop)
        {
            return curCost;
        }
        
        if (curAlp < 150 && (curCost + 1 < dist[curAlp + 1][curCop]))
        {
            pq.push({(curCost + 1) * -1, {curAlp + 1, curCop}});
            dist[curAlp + 1][curCop] = curCost + 1;
        }
        if (curCop < 150 && (curCost + 1 < dist[curAlp][curCop + 1]))
        {
            pq.push({(curCost + 1) * -1, {curAlp, curCop + 1}});
            dist[curAlp][curCop + 1] = curCost + 1;
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (problems[i][0] <= curAlp && problems[i][1] <= curCop)
            {
                int newAlp = min(curAlp + problems[i][2], 150);
                int newCop = min(curCop + problems[i][3], 150);
                int newCost = curCost + problems[i][4];
                
                if (newCost < dist[newAlp][newCop])
                {
                    pq.push({-newCost, {newAlp, newCop}});
                    dist[newAlp][newCop] = newCost;
                }
            }
        }
    }
}