#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int l, c;
vector<char> v, result;
vector<bool> visited;

void go(int cnt, int j, int m);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> l >> c;
	v.assign(c, '0'), visited.assign(c, false);
	for (int i = 0; i < c; i++) cin >> v[i];
	sort(v.begin(), v.end());
	go(0, 0, 0);
	return 0;
}

void go(int cnt, int j, int m)
{
	if (cnt == l)
	{
		if (j >= 2 && m >= 1)
		{
			for (int i = 0; i < l; i++) cout << result[i];
			cout << '\n';
		}
		return;
	}

	for (int i = 0; i < c; i++)
	{
		if (!visited[i] && (cnt == 0 || (cnt != 0 && result.back() < v[i])))
		{
			int newJ = j, newM = m;
			visited[i] = true;
			result.push_back(v[i]);
			if (v[i] == 'a' || v[i] == 'i' ||
				v[i] == 'e' || v[i] == 'o' || v[i] == 'u') newM++;
			else newJ++;
			go(cnt + 1, newJ, newM);
			result.pop_back();
			visited[i] = false;
		}
	}
}