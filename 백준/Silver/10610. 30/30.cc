#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string s, result;
int num[10], sum;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		num[s[i] - '0']++;
		sum += s[i];
	}
	
	if (num[0] == 0)
	{
		cout << -1;
		return 0;
	}

	for (int i = 9; i >= 0; i--)
	{
		while (num[i] > 0)
		{
			result.push_back(i + '0');
			num[i]--;
		}
	}

	if (sum % 3 == 0) cout << result;
	else cout << -1;
	return 0;
}