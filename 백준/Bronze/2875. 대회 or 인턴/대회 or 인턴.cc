#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k, result;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	result = min(n / 2, m);
	n -= result * 2;
	m -= result;

	if (n + m < k)
	{
		k -= n + m;
		result -= (k / 3);
		if (k % 3 != 0) result -= 1;
	}
	cout << result;
	return 0;
}