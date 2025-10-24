#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, result;
Dim2Vec<int> edges;
vector<bool> candidates;


void bfs(int curNode, int curSheep, int curWolf, const vector<int>& info);


int solution(vector<int> info, vector<vector<int>> e) 
{
    n = info.size();
    edges.assign(n, vector<int>());
    candidates.assign(n, false);
    for (int i = 0; i < e.size(); ++i)
    {
        edges[e[i][0]].emplace_back(e[i][1]);
    }
    
    
    bfs(0, 0, 0, info);
    return result;
}

void bfs(int curNode, int curSheep, int curWolf, const vector<int>& info)
{
    if (0 < curSheep && curSheep <= curWolf)
    {
        return;
    }
    
    if (info[curNode] == 0) curSheep++;
    else curWolf++;
    
    result = max(result, curSheep);
    
    for (int i = 0; i < edges[curNode].size(); ++i)
    {
        int nextNode = edges[curNode][i];
        candidates[nextNode] = true;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (candidates[i])
        {
            candidates[i] = false;
            bfs(i, curSheep, curWolf, info);
            candidates[i] = true;
        }
    }
    
    for (int i = 0; i < edges[curNode].size(); ++i)
    {
        int nextNode = edges[curNode][i];
        candidates[nextNode] = false;
    }
}