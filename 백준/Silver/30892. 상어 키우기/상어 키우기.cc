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
    int idx = 0;
    while (k--)
    {
        while (idx + 1 < n && v[idx + 1] < t)
        {
            s.push(v[idx++]);
        }
        if (idx < n && v[idx] < t)
        {
            t += v[idx++];
        }
        else if (!s.empty())
        {
            t += s.top();
            s.pop();
        }
    }
    cout << t;
    return 0;
}