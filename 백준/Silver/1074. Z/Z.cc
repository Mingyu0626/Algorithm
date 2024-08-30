#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, r, c, cnt;

void divideAndConquer(int a, int b, int size);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> r >> c;

	divideAndConquer(0, 0, pow(2, n));
	return 0;
}

void divideAndConquer(int a, int b, int size)
{
	if (a == r && b == c)
	{
		cout << cnt;
		return;
	}

	if (a <= r && r <= a + size - 1 && b <= c && c <= b + size - 1)
	{
		divideAndConquer(a, b, size / 2);
		divideAndConquer(a, b + size / 2, size / 2);
		divideAndConquer(a + size / 2, b, size / 2);
		divideAndConquer(a + size / 2, b + size / 2, size / 2);
	}
	else cnt += size * size;

}
