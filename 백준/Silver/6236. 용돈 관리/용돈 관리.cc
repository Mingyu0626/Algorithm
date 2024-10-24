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
int n, m, k, result = 1e9;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, 0);
    int left = 0, mid = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        left = max(left, v[i]);
        right += v[i];
    }
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        int cnt = 1, cur = mid;
        for (int i = 0; i < n; i++)
        {
            if (cur - v[i] >= 0)
            {
                cur -= v[i];
            }
            else
            {
                cnt++;
                cur = mid - v[i];
            }
        }

        if (cnt > m)
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