#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, result;
int dp[1001];
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
        dp[i] = v[i];
    }

    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++) dp[i] = max(dp[i], dp[i - j] + v[j]);
         
    cout << dp[n];
    return 0;
}


