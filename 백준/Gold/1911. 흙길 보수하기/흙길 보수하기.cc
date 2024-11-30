#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, result;
vector<pair<int, int>> v;

int main()
{
	cin >> n >> l;
	v.assign(n, { 0, 0 });
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	int lastBoard = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second <= lastBoard) continue;
		lastBoard = max(lastBoard, v[i].first);
		int numOfBoard = (v[i].second - (lastBoard + 1)) / l + 1;
		result += numOfBoard;
		lastBoard += l * numOfBoard;
	}

	cout << result;
	return 0;
}