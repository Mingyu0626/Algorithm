#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, t, s;
bool canEnd = true;
vector<pii> v;

bool compare(const pii& a, const pii& b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> s;
        v.emplace_back(t, s);
    }
    sort(v.begin(), v.end(), compare);
    
    int curEndTime = v[0].second - v[0].first;
    for (int i = 1; i < n; i++)
    {
        if (curEndTime < 0)
        {
            canEnd = false;
            break;
        }

        if (v[i].second < curEndTime)
        {
            curEndTime = v[i].second;
        }
        curEndTime -= v[i].first;
    }

    if (canEnd && 0 <= curEndTime)
    {
        cout << curEndTime;
    }
    else
    {
        cout << -1;
    }
    return 0;
}