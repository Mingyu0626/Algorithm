#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, k, l, r, result;
vector<int> v;
unordered_map<int, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.assign(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    l = 0, r = 0;
    while (r < n)
    {
        if (um[v[r]] < k)
        {
            um[v[r]]++;
            result = max(result, r - l + 1);
            r++;
        }
        else
        {
            um[v[l]]--;
            l++;
        }
    }

    cout << result;
    return 0;
}