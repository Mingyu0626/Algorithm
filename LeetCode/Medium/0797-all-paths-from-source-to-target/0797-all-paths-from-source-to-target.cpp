class Solution {
    int n;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size() - 1;
        vector<vector<int>> result;
        vector<int> route{0};
        dfs(0, route, graph, result);
        return result;
    }

    void dfs(int curNode, vector<int>& curRoute, vector<vector<int>>& graph, vector<vector<int>>& result) {
        if (curNode == n) {
            result.emplace_back(curRoute);
            return;
        }

        for (int i = 0; i < graph[curNode].size(); ++i) {
            int nextNode = graph[curNode][i];
            curRoute.emplace_back(nextNode);
            dfs(nextNode, curRoute, graph, result);
            curRoute.pop_back();
        }
    }
};