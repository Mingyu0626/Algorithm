#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, circumference, result;
vector<int> v, preSum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, 0), preSum.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        circumference += v[i];
        preSum[i] = v[i] + preSum[i - 1];
    }

    int l = 0, r = 1;
    while (l < r && r <= n)
    {
        int clock = preSum[r] - preSum[l];
        int halfClock = circumference - clock;
        result = max(result, min(clock, halfClock));

        if (clock < circumference / 2) r++;
        else l++;
    }
    cout << result;
    return 0;
}