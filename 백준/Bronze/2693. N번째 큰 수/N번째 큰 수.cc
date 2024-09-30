#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t > 0)
	{
		vector<int> v(10);
		for (int i = 0; i < 10; i++) cin >> v[i];
		sort(v.begin(), v.end());
		cout << v[7] << '\n';
		t--;
	}
	return 0;
}