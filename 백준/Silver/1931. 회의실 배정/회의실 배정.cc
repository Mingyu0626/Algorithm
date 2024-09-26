#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, endTime, result = 1;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) 
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, {0, 0});
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), compare);

    endTime = v[0].second;
    for (int i = 1; i < n; i++) 
    {
        if (endTime <= v[i].first) 
        {
            endTime = v[i].second;
            result++;
        }
    }
    cout << result;
    return 0;
}
