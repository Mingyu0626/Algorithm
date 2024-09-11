#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int t, n, result;
int dp[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	dp[1] = 1, dp[2] = 2, dp[3] = 2;
	for (int i = 4; i <= 1000; i++)
	{
		for (int j = 2; j * 2 <= i; j++) dp[i] += dp[j];
		dp[i] += 2;
	}

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}