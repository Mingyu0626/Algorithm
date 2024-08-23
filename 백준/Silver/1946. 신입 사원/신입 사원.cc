#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;

    for (int i = 0; i < t; i++) 
    {
        cin >> n;
        v.resize(n, { 0, 0 });
        for (int j = 0; j < n; j++) 
            cin >> v[j].first >> v[j].second;

        sort(v.begin(), v.end());

        int cnt = 1, mjScore = v[0].second;
        for (int j = 1; j < n; j++) 
        {
            if (mjScore > v[j].second) 
            {
                mjScore = v[j].second;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}