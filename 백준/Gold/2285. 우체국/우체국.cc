#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n;
long long sum;
vector<pii> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, {});
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
        sum += v[i].second;
    }

    sort(v.begin(), v.end());
    long long currentSum = 0;
    for (int i = 0; i < n; ++i)
    {
        currentSum += v[i].second;
        if ((sum + 1) / 2 <= currentSum)
        {
            cout << v[i].first;
            break;
        }
    }
    return 0;
}