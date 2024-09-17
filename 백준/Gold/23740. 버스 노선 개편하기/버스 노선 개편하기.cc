#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, s, e, c, k = 1;
vector<pair<pair<int, int>, int>> v, result;

bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e >> c;
        v.push_back({ { s, e }, c });
    }
    sort(v.begin(), v.end(), compare);

    s = v[0].first.first, e = v[0].first.second, c = v[0].second;
    for (int i = 1; i < n; i++)
    {  
        if (v[i].first.first <= e)
        {
            c = min(c, v[i].second);
            e = max(e, v[i].first.second);
        }
        else
        {
            result.push_back({ {s, e}, c });
            s = v[i].first.first, e = v[i].first.second;
            c = v[i].second;
            k++;
        }
    }
    result.push_back({ {s, e}, c });

    cout << k << '\n';
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].first.first << ' ' << result[i].first.second
            << ' ' << result[i].second << '\n';
    }
    return 0;
}

bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b)
{
    if (a.first.first == b.first.first)
    {
        if (a.first.second == b.first.second) return a.second < b.second;
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}