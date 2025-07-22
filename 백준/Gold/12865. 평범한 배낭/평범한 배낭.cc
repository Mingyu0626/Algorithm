// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
pair<int, int> arr[101] = { {0, 0}, }; // weight, value
int dp[101][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	// freopen("input.txt", "r", stdin);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) 
		cin >> arr[i].first >> arr[i].second;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - arr[i].first >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].first] + arr[i].second);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];
	return 0;
}
