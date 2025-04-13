#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, c, cur;
map<int, int> m;
vector<pair<int, int>> v;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> cur;
        if (m.find(cur) == m.end())
        {
            m.insert({ cur, v.size() });
            v.emplace_back( cur, 1 );
        }
        else
        {
            v[m[cur]].second++;
        }
    }
    stable_sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].second; j++)
        {
            cout << v[i].first << ' ';
        }
    }
    return 0;
}