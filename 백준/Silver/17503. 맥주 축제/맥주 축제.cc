#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m, k;
priority_queue<int> pq;
vector<pii> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    v.assign(k, {});
    for (int i = 0; i < k; ++i) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());

    int preferenceSum = 0, levaLevel = 0, idx = 0;
    while (idx < k) {
        if (pq.size() == n && m <= preferenceSum) {
            break;
        }
        if (pq.size() == n) {
            int lowestPreference = -pq.top();
            pq.pop();
            preferenceSum -= lowestPreference;
        }

        preferenceSum += v[idx].second;
        levaLevel = v[idx].first;
        pq.push({ -v[idx].second });
        idx++;
    }

    if (preferenceSum < m) {
        levaLevel = -1;
    }
    cout << levaLevel << '\n';
}