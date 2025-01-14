#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int s;
    int e;
    int cost;
    edge(const int& s, const int& e, const int& cost)
        : s(s), e(e), cost(cost) {}
};

int n, c, result, numOfTakenEdges;
vector<int> root;
vector<vector<int>> edgeCostVec;
vector<edge> edges;

int getRoot(const int& a);
int Union(const edge& curEdge);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    root.assign(n + 1, 0);
    edgeCostVec.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
        cin >> c;
        edges.emplace_back(0, i, c);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> edgeCostVec[i][j];
        
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j) continue;
            edges.emplace_back(i, j, edgeCostVec[i][j]);
        }
    }

    sort(edges.begin(), edges.end(), [](const edge& a, const edge& b)
        { return a.cost < b.cost; });

    for (int i = 0; i < edges.size(); i++)
    {
        result += Union(edges[i]);
        if (numOfTakenEdges == n) break;
    }

    cout << result;
    return 0;
}

int getRoot(const int& a)
{
    if (root[a] == a) return a;
    return root[a] = getRoot(root[a]);
}

int Union(const edge& curEdge)
{
    int rootA = getRoot(curEdge.s);
    int rootB = getRoot(curEdge.e);
    if (rootA != rootB)
    {
        root[rootA] = rootB;
        numOfTakenEdges++;
        return curEdge.cost;
    }
    else return 0;
}