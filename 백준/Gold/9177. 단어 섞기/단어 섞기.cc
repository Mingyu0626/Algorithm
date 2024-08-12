#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int n;
int dp[201][201];
string str1, str2, str3, result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		result = "yes";
		for (int j = 0; j <= 200; j++)
			for (int k = 0; k <= 200; k++) dp[j][k] = 0;
		dp[0][0] = 1;
		cin >> str1 >> str2 >> str3;

		for (int j = 1; j <= str1.size(); j++)
			if (str1[j - 1] == str3[j - 1]) dp[j][0] = dp[j - 1][0];

		for (int j = 1; j <= str2.size(); j++)
			if (str2[j - 1] == str3[j - 1]) dp[0][j] = dp[0][j - 1];

		for (int j = 1; j <= str1.size(); j++)
		{
			for (int k = 1; k <= str2.size(); k++)
			{
				char c1 = str1[j - 1], c2 = str2[k - 1], c3 = str3[j + k - 1];
				if (c1 == c3) dp[j][k] = dp[j - 1][k];
				if (c2 == c3) dp[j][k] = dp[j][k - 1];
				if (c1 == c3 && c2 == c3 && (dp[j - 1][k] == 1 || dp[j][k - 1] == 1))
					dp[j][k] = 1;
			}
		}

		if (dp[str1.size()][str2.size()] != 1) result = "no";
		cout << "Data set " << i << ": " << result << '\n';
	}
	return 0;
}
