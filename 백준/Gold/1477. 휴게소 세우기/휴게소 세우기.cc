#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, l, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> l;
    vector<int> v{ 0, l };
    int cur;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        v.emplace_back(cur);
    }
    sort(v.begin(), v.end());

    vector<int> diff;
    for (int i = 1; i < v.size(); i++)
    {
        diff.emplace_back(v[i] - v[i - 1]);
    }

    int left = 1, right = *max_element(diff.begin(), diff.end());
    while (left <= right)
    {
        int mid = left + (right - left) / 2, cnt = 0;
        for (int i = 0; i < diff.size(); i++)
        {
            int curDiff = diff[i];
            if (mid < curDiff)
            {
                cnt += (curDiff / mid) - (curDiff % mid == 0 ? 1 : 0);
            }
        }

        if (cnt <= m)
        {
            right = mid - 1;
            result = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << result;
    return 0;
}