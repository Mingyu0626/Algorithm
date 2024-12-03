#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n)
    {
        vector<int> v(n), a;
        for (int i = 0; i < n; i++) cin >> v[i];

        a.push_back(v[0]);
        for (int i = 1; i < n; i++)
        {
            int cur = v[i];
            if (a[a.size() - 1] < cur)
            {
                a.push_back(cur);
            }
            else
            {
                int idx = lower_bound(a.begin(), a.end(), cur) - a.begin();
                a[idx] = cur;
            }
        }
        cout << a.size() << '\n';
    }
    return 0;
}