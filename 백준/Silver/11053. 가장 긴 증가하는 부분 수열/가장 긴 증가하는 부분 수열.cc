// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, result = 1;
int arr[1001] = { 0, };
vector<int> dp(1001, 1);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("input.txt", "r", stdin);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(result, dp[i]);
	}

	cout << result;
	return 0;
}
