// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, result;
vector<int> v, dist;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("input.txt", "r", stdin);
	cin >> n >> k;
	v.assign(n, 0);
	dist.assign(n - 1, 0);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++)
		dist[i - 1] = v[i] - v[i - 1];

	sort(dist.begin(), dist.end());

	for (int i = 0; i < n - k; i++) 
		result += dist[i];
	
	cout << result;

	return 0;
}

