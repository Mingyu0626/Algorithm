#include <vector>
#include <unordered_map>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n;
Dim2Vec<int> v(1000001, vector<int>());
vector<int> result(4, 0);

void dfs(int startNode, int curNode, int numOfVisitEdges);

vector<int> solution(vector<vector<int>> edges) {
    n = edges.size();
    unordered_map<int, pii> nodeInfos; // {NodeNum, {NumOfIndegree, NumOfOutdegree}}
    pair<int, pii> createNodeInfo = {0, {0, 0}};
    for (int i = 0; i < n; ++i) {
        nodeInfos[edges[i][0]].second++;
        nodeInfos[edges[i][1]].first++;
        v[edges[i][0]].emplace_back(edges[i][1]);
    }
    
    for (const auto& a : nodeInfos) {
        if (a.second.first == 0 && createNodeInfo.second.second < a.second.second) {
            createNodeInfo = a;
        }
    }

    int createNodeNum = result[0] = createNodeInfo.first;
    for (int i = 0; i < v[createNodeNum].size(); ++i) {
        dfs(v[createNodeNum][i], v[createNodeNum][i], 0);
    }
    return result;
}

void dfs(int startNode, int curNode, int numOfVisitEdges) {
    if (startNode == curNode && 0 < numOfVisitEdges) {
        result[1]++;
        return;
    }
    if (v[curNode].size() == 0) {
        result[2]++;
        return;
    }
    if (1 < v[curNode].size()) {
        result[3]++;
        return;
    }
    dfs(startNode, v[curNode][0], numOfVisitEdges + 1);
}