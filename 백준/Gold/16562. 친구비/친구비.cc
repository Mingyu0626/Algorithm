#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, k, result;
int parent[10001];
vector<int> cost;

int GetRoot(int a);
void Union(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    cost.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        parent[i] = i;
    }

    int f1, f2;
    for (int i = 1; i <= m; i++)
    {
        cin >> f1 >> f2;
        Union(f1, f2);
    }

    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
        {
            result += cost[i];
        }
    }
    if (result <= k) cout << result;
    else cout << "Oh no";
    return 0;
}

int GetRoot(int a)
{
    if (parent[a] == a) return a;
    else return parent[a] = GetRoot(parent[a]);
}

void Union(int a, int b)
{
    a = GetRoot(a);
    b = GetRoot(b);
    if (a != b)
    {
        parent[b] = a;
        cost[a] = min(cost[a], cost[b]);
    }
}