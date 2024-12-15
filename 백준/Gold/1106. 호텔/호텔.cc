#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c, n, a, b, result = 1e9;
vector<int> dp(1101, 1e9);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> n;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        for (int j = b; j <= c + 100; j++)
        {
            if (dp[j - b] == 1e9) continue;
            dp[j] = min(dp[j], dp[j - b] + a);
        }
    }
    
    for (int i = c; i <= c + 100; i++) result = min(dp[i], result);
    cout << result;
    return 0;
}