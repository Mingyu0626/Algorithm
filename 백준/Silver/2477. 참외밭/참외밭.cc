#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int k, gMax, sMax, prevDir, smallSquare, result;
vector<pair<int, int>> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> k;
	v.assign(6, { 0, 0 });
	for (int i = 0; i < 6; i++)
	{
		cin >> v[i].first >> v[i].second;
		if (v[i].first <= 2) gMax = max(v[i].second, gMax);
		else sMax = max(v[i].second, sMax);

		if ((prevDir == 1 && v[i].first == 3) ||
			(prevDir == 4 && v[i].first == 1) ||
			(prevDir == 2 && v[i].first == 4) ||
			(prevDir == 3 && v[i].first == 2))
		{
			smallSquare = v[i - 1].second * v[i].second;
		}
		prevDir = v[i].first;
	}

	if (smallSquare == 0) smallSquare = v[0].second * v[5].second;
	result = (gMax * sMax - smallSquare) * k;
	cout << result;
	return 0;
}