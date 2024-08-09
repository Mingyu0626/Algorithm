#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, result = 1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if (n == 2) result = min(4, (m + 1) / 2);
	if (n > 2)
	{
		if (m < 7) result = min(4, m);
		else result = 5 + m - 7;
	}
	cout << result;
	return 0;
}