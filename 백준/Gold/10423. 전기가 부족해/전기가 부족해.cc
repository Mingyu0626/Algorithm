#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, num, result;
vector<bool> hasPlant;
vector<int> root;
vector<pair<int, pair<int, int>>> edges;

int getRoot(int a);
void Union(const int a, const int b);
bool hasTwoPlants(const int a, const int b);
bool isSameRoot(const int a, const int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    hasPlant.assign(n + 1, false), root.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
    }

    int cur;
    for (int i = 0; i < k; i++)
    {
        cin >> cur;
        hasPlant[cur] = true;
    }

    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({ w, { u, v } });
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++)
    {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (!hasTwoPlants(a, b) && !isSameRoot(a, b))
        {
            Union(a, b);
            num++;
            result += cost;
        }
        if (num == n) break;
    }
    cout << result;
    return 0;
}

int getRoot(int a)
{
    if (root[a] == a) return a;
    return root[a] = getRoot(root[a]);
}

void Union(const int a, const int b)
{
    int rootA = getRoot(a);
    int rootB = getRoot(b);
    if (hasPlant[rootA]) root[rootB] = rootA;
    else root[rootA] = rootB;
}

bool hasTwoPlants(const int a, const int b)
{
    return hasPlant[getRoot(a)] && hasPlant[getRoot(b)];
}

bool isSameRoot(const int a, const int b)
{
    return getRoot(a) == getRoot(b);
}