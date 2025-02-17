#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
using Dim2Vec = vector<vector<T>>;
template<typename T>
using Dim1Vec = vector<T>;

Dim2Vec<int> v;
Dim1Vec<bool> visited;
int n, m, a, b;

void dfs(const int cur, const int level);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, vector<int>());
    visited.assign(n, false);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
    }

    cout << 0;
    return 0;
}

void dfs(const int cur, const int level)
{
    if (5 <= level)
    {
        cout << 1;
        exit(0);
    }

    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];
        if (!visited[next])
        {
            visited[next] = true;
            dfs(next, level + 1);
            visited[next] = false;
        }
    }
}