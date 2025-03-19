#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct node
{
    int s;
    int e;
    int d;
};

int n, m;
vector<long long> dist;
vector<node> v;

bool checkAllEdges();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    dist.assign(n + 1, LLONG_MAX), dist[0] = 1;
    v.assign(m, {});

    for (int i = 0; i < m; i++)
    {
        cin >> v[i].s >> v[i].e >> v[i].d;
    }

    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        checkAllEdges();
    }

    if (checkAllEdges())
    {
        cout << -1;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] == LLONG_MAX)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << dist[i] << '\n';
            }
        }
    }
    return 0;
}
bool checkAllEdges()
{
    bool isDistUpdated = false;
    int start, end, distance;
    for (int i = 0; i < m; i++)
    {
        start = v[i].s, end = v[i].e, distance = v[i].d;
        if (dist[start] == LLONG_MAX) continue;

        long long newDistance = dist[start] + distance;

        if (newDistance < dist[end])
        {
            dist[end] = newDistance;
            isDistUpdated = true;
        }
    }
    return isDistUpdated;
}