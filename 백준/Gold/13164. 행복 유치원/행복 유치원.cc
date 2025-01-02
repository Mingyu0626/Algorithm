// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, result;
vector<int> v, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> n >> k;
    v.assign(n, 0);
    d.assign(n - 1, 0);
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 1; i < n; i++)
        d[i - 1] = v[i] - v[i - 1];

    sort(d.begin(), d.end());

    for (int i = 0; i < n - k; i++)
        result += d[i];

    cout << result;
    return 0;
}
