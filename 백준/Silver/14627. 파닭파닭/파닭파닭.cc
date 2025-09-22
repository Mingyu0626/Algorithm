#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s, c, l, r;
long long result, sum, m, maximumLength;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> c;
    v.assign(s, 0);
    l = 1;
    for (int i = 0; i < s; ++i)
    {
        cin >> v[i];
        r = max(r, v[i]);
        sum += v[i];
    }

    while (l <= r)
    {
        m = (r - l) / 2 + l;
        long long cnt = 0;
        for (int i = 0; i < s; ++i)
        {
            cnt += v[i] / m;
        }
        if (c <= cnt)
        {
            l = m + 1;
            maximumLength = max(maximumLength, m);
        }
        else
        {
            r = m - 1;
        }
    }
    
    result = sum - (maximumLength * c);
    cout << result;
    return 0;
}