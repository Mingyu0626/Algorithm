#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end(), greater<int>());
        result = 0;

        for (int i = 0; i < n; i++)
        {
            int cur = v[i];
            for (int j = i + 1; j < i + 3; j++)
            {
                result = max(result, v[i] - v[j % n]);
            }
        }
        cout << result << '\n';
        t--;
    }
    return 0;
}