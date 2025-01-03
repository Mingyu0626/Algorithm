#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int parent = -1;
    vector<int> children;
};
int n, a, b, m, x, y, result = -1;
vector<node> v(101);
vector<bool> visited(101, false);

void dfs(int chon, int n);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x].children.push_back(y);
        v[y].parent = x;
    }
    dfs(0, a);
    cout << result;
    return 0;
}

void dfs(int chon, int n)
{
    visited[n] = true;
    if (n == b) result = chon;

    if (v[n].parent != -1 && !visited[v[n].parent])
    {
        dfs(chon + 1, v[n].parent);
    }

    for (int i = 0; i < v[n].children.size(); i++)
    {
        int child = v[n].children[i];
        if (!visited[child])
        {
            dfs(chon + 1, child);
        }
    }
}