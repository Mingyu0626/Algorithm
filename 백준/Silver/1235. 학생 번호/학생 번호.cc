#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>

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
		bool allDiff = true;
		unordered_set<int> us;
		for (int j = 0; j < n; j++)
		{
			string s = v[j].substr(i);
			int a = stoi(s);
			if (us.find(a) == us.end()) us.insert(a);
			else allDiff = false;
		}
		if (allDiff) break;
		result++;
	}
	cout << result;
	return 0;
}