#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, cnt;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
    {
		for (int j = 0; j < n - i - 1; j++)
			cout << ' ';
		for (int j = 0; j < i + 1; j++)
			cout <<  '*';
		cout << '\n';
	}
	return 0;
}
