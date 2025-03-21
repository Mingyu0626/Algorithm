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

    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int clock = preSum[j] - preSum[i];
            int halfClock = circumference - clock;
            result = max(result, min(clock, halfClock));
        }
    }
    cout << result;
    return 0;
}