#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> a, k, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, { 0, 0 }), k.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    a.push_back(v[0].second);
    k[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int cur = v[i].second;
        if (a[a.size() - 1] < cur)
        {
            a.push_back(cur);
            k[i] = a.size() - 1;
        }
        else
        {
            int idx = lower_bound(a.begin(), a.end(), cur) - a.begin();
            a[idx] = cur;
            k[i] = idx;
        }
    }

    vector<bool> check(a.size(), false);
    int cnt = a.size() - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int cur = k[i];
        if (cur == cnt)
        {
            check[cnt] = true;
            cnt--;
        }
        else
        {
            result.push_back(v[i].first);
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}