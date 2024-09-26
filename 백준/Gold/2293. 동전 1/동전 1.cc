#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, temp;
vector<int> coin;
int dp[10001];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
    {
		cin >> temp;
		coin.push_back(temp);
	}

	dp[0] = 1;
	for (int i = 0; i < coin.size(); i++) 
    {
		int c = coin[i];
		for (int j = c; j <= k; j++) dp[j] += dp[j - c];
	}
	
	cout << dp[k];
	return 0;
}