#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;
map<string, int> m;
pair<string, int> result;
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (m.find(str) != m.end()) m[str]++;
		else m.insert({ str, 1 });
	}

	for (const auto& p : m)
		if (result.second < p.second) result = p;
	
	cout << result.first;
	return 0;
}

