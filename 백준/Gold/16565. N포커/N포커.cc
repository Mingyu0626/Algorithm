#include <iostream>
#include <vector>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, result;
const int MOD = 10007;
Dim2Vec<int> comb(53, vector<int>(53, 0));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i <= 52; ++i) {
        comb[i][0] = 1;
    }
    for (int i = 1; i <= 52; ++i) {
        for (int j = 1; j <= 52; ++j) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }

    for (int i = 1; i * 4 <= n; ++i) {
        int cases = comb[13][i] * comb[52 - i * 4][n - i * 4];
        result += (i % 2 == 1) ? cases : -cases;
        result %= MOD;
        result = (result < 0) ? (result + MOD) : result;
    }
    cout << result;
}