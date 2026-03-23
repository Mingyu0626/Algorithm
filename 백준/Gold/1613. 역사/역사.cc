#include <iostream>
#include <vector>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, k, s, a, b;
Dim2Vec<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        v[a][b] = -1, v[b][a] = 1;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                v[i][j] = (v[i][k] == v[k][j] && v[i][k] != 0) ? v[i][k] : v[i][j];
            }
        }
    }

    cin >> s;
    for (int i = 0; i < s; ++i) {
        cin >> a >> b;
        cout << v[a][b] << '\n';
    }
    return 0;
}