#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int t, x, y, diff;
vector<long long> v(1, 0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    long long moveable = 0, cnt = 0;
    while (moveable < INT_MAX)
    {
        moveable += cnt / 2 + 1;
        v.emplace_back(moveable);
        cnt++;
    }
    while (cin >> x >> y)
    {
        diff = y - x;
        cout << lower_bound(v.begin(), v.end(), diff) - v.begin() << '\n';
    }
    return 0;
}