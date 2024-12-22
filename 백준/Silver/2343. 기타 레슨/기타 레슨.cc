#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s, p, l, r, m;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> p;
    v.assign(s, 0);
    for (int i = 0; i < s; i++)
    {
        cin >> v[i];
        l = max(v[i], l);
        r += v[i];
    }

    while (l <= r)
    {
        m = (r - l) / 2 + l;
        int cnt = 1, sum = 0;
        for (int i = 0; i < s; i++)
        {
            if (sum + v[i] <= m)
            {
                sum += v[i];
            }
            else
            {
                sum = v[i];
                cnt++;
            }
        }
        if (p < cnt)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << l;
    return 0;
}