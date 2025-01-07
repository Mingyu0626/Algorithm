#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int n, cur, result;
array<int, 1001> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) dp.at(i) = -1;

    dp.at(1) = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> cur;
        if (dp.at(i) == -1) continue;
        int iterSize = min(i + cur, n);
        for (int j = i + 1; j <= iterSize; j++)
        {
            if (dp.at(j) == -1) dp.at(j) = dp.at(i) + 1;
            else dp.at(j) = min(dp.at(j), dp.at(i) + 1);
        }
    }
    cout << dp.at(n);
    return 0;
}