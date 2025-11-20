#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v, result;
vector<bool> visited;

bool dfs(int startIdx, int curIdx);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, 0), visited.assign(n + 1, false);
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i, i);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (visited[i])
        {
            result.emplace_back(i);
        }
    }
    cout << result.size() << '\n';
    for (const int& num : result)
    {
        cout << num << '\n';
    }
    return 0;
}

bool dfs(int startIdx, int curIdx)
{
    visited[curIdx] = true;
    if (v[curIdx] == startIdx)
    {
        return true;
    }
    if (!visited[v[curIdx]] && dfs(startIdx, v[curIdx]))
    {
        return true;
    }
    visited[curIdx] = false;
    return false;
}