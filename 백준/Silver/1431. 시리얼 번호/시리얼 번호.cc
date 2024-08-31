#include <iostream>>
#include <vector>
#include <algorithm>

using namespace std;

int n, sum, result;
string str;
vector<pair<string, int>> v;

bool compare1(const pair<string, int>& a, const pair<string, int>& b);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	v.assign(n, {"", 0});
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if ('0' <= str[j] && str[j] <= '9')
			{
				v[i].second += str[j] - '0';
			}
		}
		v[i].first = str;
	}
	sort(v.begin(), v.end(), compare1);
	for (int i = 0; i < n; i++) cout << v[i].first << '\n';
	return 0;
}

bool compare1(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.first.size() != b.first.size()) return a.first.size() < b.first.size();
	else if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}