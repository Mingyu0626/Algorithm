#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>

using namespace std;

int n, result = 1;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	v.assign(n, "");
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = v[0].size() - 1; i >= 0; i--)
	{
		set<string> s;
		for (int j = 0; j < n; j++) s.insert(v[j].substr(i));
		if (s.size() == n) break;
		result++;
	}
	cout << result;
	return 0;
}