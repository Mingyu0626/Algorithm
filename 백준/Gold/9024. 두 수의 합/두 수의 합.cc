#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());
        int l = 0, r = n - 1;
        int minDiff = 1e9, result = 0;
        while (l < r)
        {
            int sum = v[l] + v[r];
            int diff = abs(k - sum);
            if (diff < minDiff)
            {
                minDiff = diff;
                result = 1;
            }
            else if (diff == minDiff)
            {
                result++;
            }

            if (sum < k) l++;
            else r--;
        }
        cout << result << '\n';
    }
    return 0;
}