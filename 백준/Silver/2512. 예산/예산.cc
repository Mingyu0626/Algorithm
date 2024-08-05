#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sum, y, result;
int l, r, m;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) 
	{
		cin >> v[i];
		sum += v[i];
	}
	cin >> y;

	l = y / n, r = *max_element(v.begin(), v.end());

	if (sum <= y)
	{
		cout << r;
		return 0;
	}

	else
	{
		while (l <= r)
		{
			m = l + (r - l) / 2;

			int curSum = 0;
			for (int i = 0; i < n; i++)
			{
				if (v[i] <= m) curSum += v[i];
				else curSum += m;
			}

			if (y < curSum)
			{
				r = m - 1;
			}
			
			else
			{
				result = m;
				l = m + 1;
			}
		}

	}
	cout << result;
	return 0;
}