#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, cur, furthest, result;
vector<int> l, r;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
		furthest = max(furthest, abs(cur));
		if (cur > 0) r.emplace_back(cur);
		else l.emplace_back(cur);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end(), greater<int>());
    for (int i = 0; i < l.size(); i += m) result += abs(l[i]) * 2;
    for (int i = 0; i < r.size(); i += m) result += r[i] * 2;

    result -= furthest;
    cout << result;
    return 0;
}