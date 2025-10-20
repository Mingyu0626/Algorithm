#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int t[501], dp[501];
vector<int> nb[501];

int recursion(int a);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		cin >> t[i];
		while (temp != -1)
		{
			cin >> temp;
			nb[i].push_back(temp);
		}
	}

	for (int i = 1; i <= n; i++) cout << recursion(i) << "\n";
	return 0;
}

int recursion(int a)
{
	if (dp[a] != 0) return dp[a];

	int maxNB = 0;
	for (int i = 0; i < nb[a].size(); i++) maxNB = max(maxNB, recursion(nb[a][i]));

	dp[a] = maxNB + t[a];
	return dp[a];
}

