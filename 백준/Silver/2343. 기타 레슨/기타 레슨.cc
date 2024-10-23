#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int n, m;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, 0);
    int l = 0, r = 0, mid = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        l = max(l, v[i]);
        r += v[i];
    }
    
    while (l <= r)
    {
        mid = (l - r) / 2 + r;
        int sum = 0, cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (sum + v[i] <= mid)
            {
                sum += v[i];
            }
            else
            {
                sum = v[i];
                cnt++;
            }

        }
        if (cnt <= m) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}