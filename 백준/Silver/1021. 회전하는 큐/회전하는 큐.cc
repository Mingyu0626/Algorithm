#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n, m, target, result;
int moveAmount;
deque<int> dq;

void move(int dir);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) dq.push_back(i);

	for (int i = 0; i < m; i++)
	{
		cin >> target;
		int dir = 0;
		int pos = distance(dq.begin(), find(dq.begin(), dq.end(), target));
		if (pos > dq.size() / 2) dir = 1;
		
		while (dq.front() != target)
		{
			move(dir);
			result++;
		}
		dq.pop_front();
	}
	cout << result;
	return 0;
}

void move(int d)
{
	if (d == 0)
	{
		int l = dq.front();
		dq.pop_front();
		dq.push_back(l);
	}

	else
	{
		int r = dq.back();
		dq.pop_back();
		dq.push_front(r);
	}
}
