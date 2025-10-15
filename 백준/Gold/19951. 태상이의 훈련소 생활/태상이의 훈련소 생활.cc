#include <iostream>
#include <vector>

using namespace std;

int n, m, s, e, h;
vector<long long> v, diff;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n + 1, 0), diff.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= m; ++i)
    {
        cin >> s >> e >> h;
        diff[s] += h;
        if (e != n)
        {
            diff[e + 1] -= h;
        }
    }

    long long prefixDiff = 0;
    for (int i = 1; i <= n; ++i)
    {
        prefixDiff += diff[i];
        v[i] += prefixDiff;
        cout << v[i] << ' ';
    }
    return 0;
}