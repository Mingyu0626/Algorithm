#define MAX 1000000
#include <iostream>>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> v(MAX + 1, 0);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 2; i <= MAX; i++) v[i] = i;

	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (v[i] == 0) continue;

		for (int j = i * i; j <= MAX; j += i) v[j] = 0;
	}

	while (true)
	{
		cin >> n;
		if (n == 0) break;
		bool dekimasuka = false;
		for (int i = n - 1; i >= n / 2; i--)
		{
			if (v[i] != 0 && v[n - i] != 0)
			{
				cout << n << " = " << n - i << " + " << i << '\n';
				dekimasuka = true;
				break;
			}
		}
		if (!dekimasuka) cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}