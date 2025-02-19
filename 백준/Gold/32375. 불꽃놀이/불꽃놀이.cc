#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, cur;
vector<int> result, v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        if (k <= cur) result.push_back(cur);
        else v.push_back(cur);
    }
    sort(v.begin(), v.end());

    int l = 0, r = v.size() - 1;
    while (l < r)
    {
        int sum = v[l] + v[r];
        if (k <= sum)
        {
            result.push_back(sum);
            r--;
        }
        l++;
    }

    if (result.size() == 0) cout << -1;
    else cout << result.size();
    return 0;
}