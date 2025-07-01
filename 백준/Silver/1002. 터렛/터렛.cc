#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int t, X1, Y1, R1, X2, Y2, R2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t > 0)
	{
		cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
		if (X1 == X2 && Y1 == Y2 && R1 == R2)
		{
			cout << -1 << '\n';
			t--;
			continue;
		}

		int rSum = (R1 + R2) * (R1 + R2);
		int rDiff = (R1 - R2) * (R1 - R2);
		int dX = X2 - X1, dY = Y2 - Y1;
		int dist = dX * dX + dY * dY;

		if (rDiff < dist && dist < rSum) cout << 2;
		else if (rDiff == dist || rSum == dist) cout << 1;
		else cout << 0;
		cout << '\n';
		t--;
	}
	return 0;
}