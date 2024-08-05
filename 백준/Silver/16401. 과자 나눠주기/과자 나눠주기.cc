#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, result;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];

	int left = 1, right = *max_element(v.begin(), v.end());
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		int numOfSnacks = 0;

		for (int i = 0; i < n; i++) numOfSnacks += v[i] / mid;
		
		if (numOfSnacks < m) right = mid - 1;
		
		else
		{
			result = mid;
			left = mid + 1;
		}
	}
	cout << result;
	return 0;
}