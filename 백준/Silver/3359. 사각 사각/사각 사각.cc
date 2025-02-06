#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    struct square { int w, l; };
    vector<square> v(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; i++) cin >> v[i].w >> v[i].l;

    dp[1][0] = v[1].w, dp[1][1] = v[1].l;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = 
            max(dp[i - 1][0] + abs(v[i - 1].l - v[i].l), 
                dp[i - 1][1] + abs(v[i - 1].w - v[i].l)) + v[i].w;
        dp[i][1] = 
            max(dp[i - 1][0] + abs(v[i - 1].l - v[i].w),
                dp[i - 1][1] + abs(v[i - 1].w - v[i].w)) + v[i].l;
    }

    cout << max(dp[n][0], dp[n][1]);
    return 0;
}