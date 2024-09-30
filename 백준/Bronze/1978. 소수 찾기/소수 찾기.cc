#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, num, result;
vector<bool> v(1001, true);

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	v[1] = false;
	for (int i = 2; i * i <= 1000; i++)
	{
		if (v[i])
		{
			for (int k = i * i; k <= 1000; k += i)
			{
				v[k] = false;
			}
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (v[num]) result++;
	}
	cout << result;
	return 0;
}