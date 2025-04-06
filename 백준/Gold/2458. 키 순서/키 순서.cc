#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct node
{
    vector<int> parent;
    vector<int> child;
};

int n, m, small, big, result;
vector<node> v;
vector<bool> visited;

int dfsParent(int cur, int cnt);
int dfsChild(int cur, int cnt);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n + 1, {});
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        cin >> small >> big;
        v[small].parent.emplace_back(big);
        v[big].child.emplace_back(small);
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        fill(visited.begin(), visited.end(), false);
        cnt += dfsParent(i, 0);
        cnt += dfsChild(i, 0);
        if (cnt == n - 1)
        {
            result++;
        }
    }
    cout << result;
    return 0;
}

int dfsParent(int cur, int cnt)
{
    visited[cur] = true;
    int newCnt = cnt;
    for (int i = 0; i < v[cur].parent.size(); i++)
    {
        if (!visited[v[cur].parent[i]])
        {
            newCnt += dfsParent(v[cur].parent[i], 1);
        }
    }
    return newCnt;
}

int dfsChild(int cur, int cnt)
{
    visited[cur] = true;
    int newCnt = cnt;
    for (int i = 0; i < v[cur].child.size(); i++)
    {
        if (!visited[v[cur].child[i]])
        {
            newCnt += dfsChild(v[cur].child[i], 1);
        }
    }
    return newCnt;
}