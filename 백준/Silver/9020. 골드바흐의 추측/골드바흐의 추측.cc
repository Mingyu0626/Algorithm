#define MAX 10000
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int t, n;
vector<int> v(MAX + 1, 0);

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;

	for (int i = 2; i <= MAX; i++) v[i] = i;

	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (v[i] == 0) continue;
		for (int j = i * i; j <= MAX; j += i) v[j] = 0;
	}

	while (t > 0)
	{
		cin >> n;
		int a = 0, b = 0;
		for (int i = n - 1; i >= n / 2; i--)
		{
			if (v[i] != 0 && v[n - i] != 0)
			{
				a = n - i, b = i;
			}
		}
		cout << a << ' ' << b << '\n';
		t--;
	}
	return 0;
}