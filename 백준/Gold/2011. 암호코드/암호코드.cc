#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string n;
int dp[5001][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    dp[0][0] = 1, dp[1][0] = 1;
    if (n[0] == '0')
    {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < n.size(); i++)
    {
        int oneDigit = n[i] - '0';
        int twoDigits = (n[i - 1] - '0') * 10;

        if (oneDigit == 0 && 20 < twoDigits)
        {
            break;
        }

        if (oneDigit != 0)
        {
            dp[i + 1][0] = (dp[i][0] + dp[i][1]) % 1000000;
        }

        if (twoDigits != 0 && twoDigits + oneDigit <= 26)
        {
            dp[i + 1][1] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000;
        }
    }
    cout << (dp[n.size()][0] + dp[n.size()][1]) % 1000000;
    return 0;
}