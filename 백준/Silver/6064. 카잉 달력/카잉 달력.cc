#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int t, m, n, x, y;
long long LCM;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (0 < t--)
    {
        cin >> m >> n >> x >> y;
        bool hasResult = false;
        LCM = lcm(m, n);
        for (int i = 0; i <= n; ++i)
        {
            int candidate = (m * i) + x;
            if ((candidate - y) % n == 0)
            {
                cout << candidate << '\n';
                hasResult = true;
                break;
            }
        }
        if (!hasResult)
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}