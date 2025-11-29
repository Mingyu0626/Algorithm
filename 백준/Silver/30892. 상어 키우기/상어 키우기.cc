#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

long long n, k, t;
vector<long long> v;
stack<long long> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> t;
    v.assign(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int idx = 0, prevIdx = -1;
    while (0 < k--)
    {
        int idx = lower_bound(v.begin(), v.end(), t) - v.begin() - 1;

        if (prevIdx == idx || idx == n)
        {
            if (!s.empty())
            {
                t += s.top();
                s.pop();
            }
        }
        else
        {
            t += v[idx];
            for (int i = prevIdx + 1; i < idx; ++i)
            {
                s.push(v[i]);
            }
        }
        prevIdx = idx;
    }
    cout << t;
    return 0;
}