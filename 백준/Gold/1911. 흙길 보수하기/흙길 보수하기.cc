#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int n, l, last, result;
vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> l;
    v.assign(n, {0, 0});
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i].second <= last) continue;
        last = max(last, v[i].first);
        int numOfBoard = (v[i].second - 1 - last) / l + 1;
        result += numOfBoard;
        last += numOfBoard * l;
    }
    cout << result;
    return 0;
}