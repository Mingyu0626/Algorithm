#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int n, m;
string s;
vector<pair<string, int>> v;
unordered_map<string, int> um;

bool compare(pair<string, int>& a, pair<string, int>& b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s.size() >= m) um[s]++;
    }

    for (auto a : um) v.push_back(a);
    sort(v.begin(), v.end(), compare);
    for (auto a : v) cout << a.first << '\n';
    return 0;
}

bool compare(pair<string, int>& a, pair<string, int>& b)
{
    if (a.second == b.second)
    {
        if (a.first.size() == b.first.size())
        {
            return a.first < b.first;
        }
        return a.first.size() > b.first.size();
    }
    return a.second > b.second;
}