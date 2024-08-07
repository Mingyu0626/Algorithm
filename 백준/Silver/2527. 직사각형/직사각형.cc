#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int X1, Y1, P1, Q1, X2, Y2, P2, Q2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++)
	{
		cin >> X1 >> Y1 >> P1 >> Q1 >> X2 >> Y2 >> P2 >> Q2;

		if (P2 < X1 || Q2 < Y1 || Q1 < Y2 || P1 < X2)
			cout << 'd';

		else if ((X1 == P2 && Y1 == Q2) || (X2 == P1 && Y2 == Q1) || (X1 == P2 && Q1 == Y2) || (X2 == P1 && Q2 == Y1))
			cout << 'c';

		else if (X1 == P2 || X2 == P1 || Y1 == Q2 || Y2 == Q1 )
			cout << 'b';

		else
			cout << 'a';

		cout << '\n';
	}
	return 0;
}