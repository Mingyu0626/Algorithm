#include <iostream>>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n, sum, low[3], num[3], maxNum, result;
pair<long long, long long> d[3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		cin >> d[i].first;
		sum += d[i].first;
		maxNum = max(maxNum, d[i].first);
	}
	for (int i = 2; i >= 0; i--)
	{
		cin >> d[i].second;
		sum += d[i].second;
		maxNum = max(maxNum, d[i].second);
	}
	for (int i = 0; i < 3; i++) low[i] = min(d[i].first, d[i].second);
	sort(low, low + 3);
	
	if (n == 1) result = sum - maxNum;
	if (n > 1)
	{
		num[0] = (n - 2) * (n - 2) * 5 + (n - 2) * 4;
		num[1] = 4 + (4 * (n - 2) * 2);
		num[2] = 4;
		result = num[0] * low[0] +
			num[1] * (low[0] + low[1]) +
			num[2] * (low[0] + low[1] + low[2]);
	}

	cout << result;
	return 0;
}