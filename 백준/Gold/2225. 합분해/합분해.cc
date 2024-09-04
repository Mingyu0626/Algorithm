#define DIV 1000000000
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
long long dp[201][201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    for (int i = 1; i <= k; i++) dp[1][i] = i;
    
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= k; j++) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % DIV;
        
    cout << dp[n][k];
    return 0;
}