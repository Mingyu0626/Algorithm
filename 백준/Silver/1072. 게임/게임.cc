#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
long long x, y, z;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> x >> y;
    z = y * 100 / x;
    int left = 1, right = 1e9, mid = 0;
    if (z >= 99)
    {
        cout << -1;
        return 0;
    }
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        long long newZ = ((y + mid) * 100) / ((x + mid));
        if (newZ <= z)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << left;
    return 0;
}