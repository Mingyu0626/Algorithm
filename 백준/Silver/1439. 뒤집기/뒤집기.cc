#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string s;
int num[2];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	num[s[0] - '0']++;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i - 1] != s[i]) num[s[i]- '0']++;
	}

	cout << min(num[0], num[1]);
	return 0;
}