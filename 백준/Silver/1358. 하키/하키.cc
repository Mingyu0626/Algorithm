#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int w, h, x, y, p, result;
vector<pair<int, int>> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> w >> h >> x >> y >> p;
	v.assign(p, { 0, 0 });
	int r = h / 2;
	for (int i = 0; i < p; i++)
	{
		cin >> v[i].first >> v[i].second;
		int c1 = pow((v[i].first - x), 2) + pow((v[i].second - (y + r)), 2);
		int c2 = pow((v[i].first - (x + w)), 2) + pow((v[i].second - (y + r)), 2);
		if (c1 <= pow(r, 2) || c2 <= pow(r, 2) ||
			(x <= v[i].first && v[i].first <= x + w && 
				y <= v[i].second && v[i].second <= y + h)) 
			result++;
		
	}

	cout << result;
	return 0;
}