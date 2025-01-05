#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, result;
vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, { 0, 0 });
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int s = v[i].first, e = v[i].second;
        if (result <= s) result = s + e;
        else result += e;
    }
    cout << result;
    return 0;
}