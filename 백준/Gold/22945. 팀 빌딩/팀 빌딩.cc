#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int l = 0, r = n - 1, result = 0;
    while (l < r) {
        result = max(result, min(v[l], v[r]) * (r - l - 1));

        if (v[l] < v[r]) {
            l++;
        }
        else {
            r--;
        }
    }
    cout << result;
}