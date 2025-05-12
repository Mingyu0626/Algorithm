#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int parent;
};

int t, n, a, b;
vector<node> v;
vector<bool> visited;

void dfs(int cur);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (0 < t--)
    {
        cin >> n;
        v.assign(n + 1, node{});
        visited.assign(n + 1, false);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            v[b].parent = a;
        }
        cin >> a >> b;
        dfs(a);
        dfs(b);

    }
}

void dfs(int cur)
{
    if (visited[cur])
    {
        cout << cur << '\n';
        return;
    }
    visited[cur] = true;
    if (v[cur].parent != 0)
    {
        dfs(v[cur].parent);
    }
}