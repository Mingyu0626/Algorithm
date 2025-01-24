#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        auto it = ms.lower_bound(-v[i].second + 1);
        if (it != ms.end())
        {
            int cur = *it;
            ms.erase(it);
            ms.insert(cur - 1);
        }
        else
        {
            ms.insert(-1);
        }
    }

    cout << ms.size();
    return 0;
}