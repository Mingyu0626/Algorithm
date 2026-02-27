#include <iostream>

using namespace std;

int x, result;
int attachStick(const int& x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> x;
    while (0 < x) {
        x -= attachStick(x);
        result++;
    }
    cout << result;
    return 0;
}

int attachStick(const int& x) {
    int stick = 1;
    while (stick * 2 <= x) {
        stick *= 2;
    }
    return stick;
}