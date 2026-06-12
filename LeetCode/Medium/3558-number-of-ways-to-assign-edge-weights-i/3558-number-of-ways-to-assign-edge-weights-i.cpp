class Solution {
private:
    vector<vector<int>> edges;
    vector<bool> visited;
    int maxDepth;
    const int MOD = 1000000007;
public:
    int assignEdgeWeights(vector<vector<int>>& vec) {
        init(vec);
        maxDepth = getMaxDepth(1, 0);
        return calcResult();
    }

    void init(vector<vector<int>>& vec) {
        edges.assign(100001, vector<int>());
        visited.assign(100001, false);
        for (int i = 0; i < vec.size(); ++i) {
            int u = vec[i][0], v = vec[i][1];
            edges[u].emplace_back(v);
            edges[v].emplace_back(u);
        }
    }

    int getMaxDepth(int nodeNum, int curDepth) {
        visited[nodeNum] = true;
        int updatedDepth = curDepth;
        for (int i = 0; i < edges[nodeNum].size(); ++i) {
            int next = edges[nodeNum][i];
            if (visited[next]) {
                continue;
            }
            updatedDepth = max(updatedDepth, getMaxDepth(next, curDepth + 1));
        }
        return updatedDepth;
    }

    int calcResult() {
        int result = 1;
        for (int i = 0; i < maxDepth - 1; ++i) {
            result *= 2;
            result %= MOD;
        }
        return result;
    }
};