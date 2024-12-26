#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int n, a, b, idx;
long long result;
vector<long long> v1, v2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> a >> b;
	v1.assign(a, 0), v2.assign(b, 0);
	for (int i = 0; i < a; i++) cin >> v1[i];
	for (int i = 0; i < b; i++) cin >> v2[i];
	sort(v1.begin(), v1.end(), greater<long long>());

	if (n % 2 != 0)
	{
		result += v1[0];
		idx++;
	}
	for (int i = idx; i < a - 1; i += 2)
	{
		int tile22 = v1[i] + v1[i + 1];
		v2.push_back(tile22);
	}
	sort(v2.begin(), v2.end(), greater<long long>());

	for (int i = 0; i < n / 2; i++) result += v2[i];
	cout << result;
	return 0;
}