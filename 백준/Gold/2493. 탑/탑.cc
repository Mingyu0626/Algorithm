#include <iostream>
#include <stack>

using namespace std;

int n, h;
stack<pair<int, int>> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> h;
		while (!s.empty()) 
		{
			if (h < s.top().second) 
			{
				cout << s.top().first + 1 << ' ';
				break;
			}
			s.pop();
		}
		if (s.empty())
		{
			cout << 0 << ' ';
		}
		s.push({i, h});
	}
    return 0;
}