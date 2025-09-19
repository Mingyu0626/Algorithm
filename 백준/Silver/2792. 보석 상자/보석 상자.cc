#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int jealous;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(m, 0);
    int l = 1, r = 0, mid;
    for (int i = 0; i < m; ++i)
    {
        cin >> v[i];
        r = max(r, v[i]);
    }

    jealous = r;
    while (l <= r)
    {
        mid = (r - l) / 2 + l;

        int children = 0;
        for (int i = 0; i < m; ++i)
        {
            children += v[i] / mid;
            children += (v[i] % mid != 0) ? 1 : 0;
        }

        if (children <= n)
        {
            jealous = min(jealous, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << jealous;
    return 0;
}