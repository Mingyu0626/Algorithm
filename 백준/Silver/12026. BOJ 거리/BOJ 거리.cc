#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<char> v;
vector<int> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, ' ');
    dp.assign(n + 1, 1e9);
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        char cur = v[i];
        for (int j = i + 1; j <= n; j++)
        {
            if (cur == 'B' && v[j] == 'O' ||
                cur == 'O' && v[j] == 'J' ||
                cur == 'J' && v[j] == 'B')
            {
                dp[j] = min(dp[j], dp[i] + (int)pow(j - i, 2));
            }
        }
    }
    
    if (dp[n] == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << dp[n];
    }
    return 0;
}