#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 

struct studentInfo
{
    int h;
    int k;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<studentInfo> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].h >> v[i].k;
    
    sort(v.begin(), v.end(), 
        [](const studentInfo& a, const studentInfo& b)
        {
            return a.h > b.h;
        });

    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        auto it = ms.lower_bound(-v[i].k + 1);
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