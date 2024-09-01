#include <iostream>>
#include <vector>
#include <algorithm>

using namespace std;

int n, result = 1e9;
int dp[1001][3];
vector<vector<int>> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	v.assign(n + 1, vector<int>(3, 0));
	for (int i = 1; i <= n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];

	for (int i = 0; i < 3; i++)
	{
		dp[2][i] = 1e9;
		dp[2][(i + 1) % 3] = v[2][(i + 1) % 3] + v[1][i];
		dp[2][(i + 2) % 3] = v[2][(i + 2) % 3] + v[1][i];

		for (int j = 3; j <= n; j++)
		{
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + v[j][0];
			dp[j][1] = min(dp[j - 1][2], dp[j - 1][0]) + v[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + v[j][2];
		}
		result = min({ result, dp[n][(i + 1) % 3], dp[n][(i + 2) % 3] });
	}

	cout << result;
	return 0;
}