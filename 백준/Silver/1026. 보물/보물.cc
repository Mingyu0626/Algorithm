#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, result;
vector<int> a, b;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	a.assign(n, 0), b.assign(n, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	for (int i = 0; i < n; i++) result += a[i] * b[i];
	cout << result;
	return 0;
}