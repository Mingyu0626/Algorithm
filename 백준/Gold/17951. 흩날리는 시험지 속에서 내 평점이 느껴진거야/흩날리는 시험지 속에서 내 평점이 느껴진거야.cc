#include <iostream>
#include <vector>

using namespace std; 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i],
        sum += v[i];
    }

    int l = 0, r = sum, result = 0;
    while (l <= r)
    {
        int m = (r - l) / 2 + l;
        int groupCount = 0, curSum = 0;
        for (int i = 0; i < n; i++)
        {
            curSum += v[i];
            if (m <= curSum) groupCount++, curSum = 0;
        }
        if (groupCount < k)
        {
            r = m - 1;
        }
        else
        {
            result = max(result, m);
            l = m + 1;
        }
    }
    cout << result;
    return 0;
}