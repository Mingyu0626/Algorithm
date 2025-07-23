#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, t, k, s;
vector<int> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> t;
    dp.assign(t + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> k >> s;
        for (int j = t; j >= k; j--)
        {
            dp[j] = max(dp[j], dp[j - k] + s);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}