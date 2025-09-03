#include <iostream>
#include <vector>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, r, q, u, v;
Dim2Vec<int> edges;
vector<int> numOfSubTreeNodes;
vector<bool> visited;

int search(int r);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> r >> q;
    edges.assign(n + 1, vector<int>());
    numOfSubTreeNodes.assign(n + 1, 0);
    visited.assign(n + 1, false);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    numOfSubTreeNodes[r] = search(r);
    for (int i = 0; i < q; ++i)
    {
        cin >> u;
        cout << numOfSubTreeNodes[u] << '\n';
    }
    return 0;
}

int search(int r)
{
    visited[r] = true;
    int numOfNodes = 1;
    for (int i = 0; i < edges[r].size(); ++i)
    {
        int nextNode = edges[r][i];
        if (!visited[nextNode])
        {
            int nextNodeSubTree = search(nextNode);
            numOfSubTreeNodes[nextNode] = nextNodeSubTree;
            numOfNodes += nextNodeSubTree;
        }
    }
    return numOfNodes;
}