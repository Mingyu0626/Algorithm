#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int s;
    int e;
    int t;
};

int t, n, m, w;
vector<long long> dist;
vector<node> v;

bool checkAllEdges();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (0 < t--)
    {
        cin >> n >> m >> w;
        v.clear();
        dist.resize(n + 1, 1e9);
        int s, e, t;
        for (int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            v.push_back({ s, e, t });
            v.push_back({ e, s, t });
        }
        for (int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            v.push_back({ s, e, -t });
        }

        for (int i = 0; i < n - 1; i++)
        {
            checkAllEdges();
        }

        if (checkAllEdges())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}

bool checkAllEdges()
{
    int s, e, t;
    bool isTimeUpdated = false;
    for (int i = 0; i < v.size(); i++)
    {
        s = v[i].s, e = v[i].e, t = v[i].t;
        long long newTime = dist[s] + t;
        if (newTime < dist[e])
        {
            dist[e] = newTime;
            isTimeUpdated = true;
        }
    }
    return isTimeUpdated;
}