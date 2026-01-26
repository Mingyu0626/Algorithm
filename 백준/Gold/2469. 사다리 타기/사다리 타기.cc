#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int k, n, hiddenWidth;
char c;
string result;
vector<int> s, e;
vector<string> v;

void climbLadder();
void validate();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k >> n;
    s.assign(k, 0), e.assign(k, 0);
    result.assign(k - 1, '*');
    for (int i = 0; i < k; ++i) {
        cin >> c;
        s[i] = i, e[i] = c - 'A';
    }

    v.assign(n, "");
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i][0] == '?') {
            hiddenWidth = i;
        }
    }

    climbLadder();
    validate();
    cout << result;
}

void climbLadder() {
    for (int i = 0; i < hiddenWidth; ++i) {
        for (int j = 0; j < k - 1; ++j) {
            if (v[i][j] == '-') {
                swap(s[j], s[j + 1]);
            }
        }
    }

    for (int i = n - 1; i > hiddenWidth; --i) {
        for (int j = 0; j < k - 1; ++j) {
            if (v[i][j] == '-') {
                swap(e[j], e[j + 1]);
            }
        }
    }
}

void validate() {
    for (int i = 0; i < k - 1; ++i) {
        if (s[i] == e[i]) {
            result[i] = '*';
            continue;
        }
        if (s[i] == e[i + 1] && s[i + 1] == e[i]) {
            swap(s[i], s[i + 1]);
            result[i] = '-';
            continue;
        }
        fill(result.begin(), result.end(), 'x');
        return;
    }
}