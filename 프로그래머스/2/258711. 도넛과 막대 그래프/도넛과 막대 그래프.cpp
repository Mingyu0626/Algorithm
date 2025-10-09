#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;

template <typename T>
using Dim2Vec = vector<vector<T>>;

Dim2Vec<int> v(1000001, vector<int>());

void dfs(int startNode, int curNode, int numOfVisitEdges, vector<int>& result);

vector<int> solution(vector<vector<int>> edges) 
{
    vector<int> result(4, 0);
    int n = edges.size();
    unordered_map<int, pii> um;
    pair<int, pii> createNodeInfo = {0, {0, 0}}; // {NodeNum, {NumOfIndegree, NumOfOutdegree}}
    for (int i = 0; i < n; ++i)
    {
        um[edges[i][0]].second++;
        um[edges[i][1]].first++;
        v[edges[i][0]].emplace_back(edges[i][1]);
    }
    
    for (const auto& a : um)
    {
        if (a.second.first == 0 && createNodeInfo.second.second < a.second.second)
        {
            createNodeInfo = a;
        }
    }

    result[0] = createNodeInfo.first;
    for (int i = 0; i < v[result[0]].size(); ++i)
    {
        dfs(v[result[0]][i], v[result[0]][i], 0, result);
    }
    
    return result;
}

void dfs(int startNode, int curNode, int numOfVisitEdges, vector<int>& result)
{
    if (startNode == curNode && 0 < numOfVisitEdges)
    {
        result[1]++;
        return;
    }
    
    if (v[curNode].size() == 0)
    {
        result[2]++;
        return;
    }
    
    if (1 < v[curNode].size())
    {
        result[3]++;
        return;
    }
    
    dfs(startNode, v[curNode][0], numOfVisitEdges + 1, result);
}