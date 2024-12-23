#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d;
struct shortcut
{
    int s, e, l;
};
vector<shortcut> v;
vector<int> dp;

bool compare(const shortcut& a, const shortcut& b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> d;
    v.assign(n, {}), dp.assign(d + 1, 0);
    for (int i = 1; i <= d; i++) dp[i] = i;

    for (int i = 0; i < n; i++) cin >> v[i].s >> v[i].e >> v[i].l;
    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < n; i++)
    {
        int originDist = v[i].e - v[i].s;
        if (originDist <= v[i].l || d < v[i].e) continue;
        if (dp[v[i].s] + v[i].l < dp[v[i].e])
        {
            int shortcutDist = dp[v[i].s] + v[i].l;
            dp[v[i].e] = shortcutDist;
            for (int j = v[i].e + 1; j <= d; j++)
            {
                dp[j] = min(dp[j], j - v[i].e + shortcutDist);
            }
        }
    }

    cout << dp[d];
    return 0;
}

bool compare(const shortcut& a, const shortcut& b)
{
    if (a.s == b.s)
    {
        if (a.e == b.e)
        {
            return a.l < b.l;
        }
        return a.e < b.e;
    }
    return a.s < b.s;
}