// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt", "r", stdin);

	int n, temp, cur;
	cin >> n;
	deque<pair<int, int>> dq;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		dq.push_back(make_pair(temp, i + 1));
	}

	while (!dq.empty()) {
		cur = dq.front().first;
		cout << dq.front().second << " ";
		dq.pop_front();

		if (dq.empty()) 
			break;

		if (cur > 0) {
			for (int i = 0; i < cur - 1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (int i = 0; i < abs(cur); i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}


	}
	return 0;
}