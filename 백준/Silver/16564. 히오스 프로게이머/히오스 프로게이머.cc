#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k, result;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = 0, r = *max_element(v.begin(), v.end()) + k + 1;
    int m = 0;
    while (l <= r)
    {
        m = (r - l) / 2 + l;
        long long neededLevel = 0;
        for (int i = 0; i < n; i++)
        {
            neededLevel += max(0, m - v[i]);
        }
        if (neededLevel <= k)
        {
            l = m + 1;
            result = m;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << result;
    return 0;
}