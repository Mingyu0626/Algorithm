#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = n; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}