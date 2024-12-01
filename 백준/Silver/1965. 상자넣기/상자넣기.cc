#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int n;
vector<int> v, a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    a.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        int cur = v[i];
        if (a[a.size() - 1] < cur)
        {
            a.push_back(v[i]);
        }
        else
        {
            int idx = lower_bound(a.begin(), a.end(), cur) - a.begin();
            a[idx] = cur;
        }
    }
    cout << a.size();
    return 0;
}