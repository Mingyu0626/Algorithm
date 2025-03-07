#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, result;
int dp[100001][2]; // 0 : 삭제 안함, 1 : 삭제함
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    dp[1][0] = dp[1][1] = v[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + v[i], v[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v[i]);
    }

    result = -pow(10, 9);
    for (int i = 1; i <= n; i++)
    {
        result = max({ result, dp[i][0], dp[i][1]});
    }
    cout << result;
    return 0;
}