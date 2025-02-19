#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, cur, result;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        if (k <= cur) result++;
        else v.emplace_back(cur);
    }
    sort(v.begin(), v.end());

    int l = 0, r = v.size() - 1;
    while (l < r)
    {
        int sum = v[l] + v[r];
        if (k <= sum)
        {
            result++;
            r--;
        }
        l++;
    }
    cout << (result == 0 ? -1 : result);
    return 0;
}