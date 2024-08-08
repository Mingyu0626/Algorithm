#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int x, y, w, h;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> x >> y >> w >> h;

	cout << min({x, y, w - x, h - y});
	return 0;
}