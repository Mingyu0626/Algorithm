// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt", "r", stdin);

	int n, temp;
	string command;
	stack<int> s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push") {
			cin >> temp;
			s.push(temp);
		}
		else if (command == "top") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else
				cout << s.top() << "\n";
		}
		else if (command == "size") {
			cout << s.size() << "\n";
		}
		else if (command == "empty") {
			cout << s.empty() << "\n";
		}
		else {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
	}
	return 0;
}