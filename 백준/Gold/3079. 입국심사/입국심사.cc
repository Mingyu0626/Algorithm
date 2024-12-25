#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

long long n, m, l, mid, r, people;
vector<long long> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	l = 1, r = v[n - 1] * m;
	while (l <= r) 
	{
		people = 0;
		mid = (l - r) / 2 + r;
		for (int i = 0; i < n; i++) 
		{
			people += mid / v[i];
			if (m <= people) break;
		}
		if (m <= people) r = mid - 1;
		else l = mid + 1;
	}
	cout << l;
	return 0;
}