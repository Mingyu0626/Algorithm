#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c, result;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> c;
    v.assign(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l = 0, r = *max_element(v.begin(), v.end()), m;
    while (l <= r)
    {
        m = (l - r) / 2 + r;
        int modemCnt = 1, lastHouse = v[0];
        for (int i = 1; i < n; ++i)
        {
            if (m <= v[i] - lastHouse)
            {
                modemCnt++;
                lastHouse = v[i];
            }
        }

        if (c <= modemCnt)
        {
            l = m + 1;
            result = max(result, m);
        }
        else
        {
            r = m - 1;
        }
    }
    cout << result;
    return 0;
}