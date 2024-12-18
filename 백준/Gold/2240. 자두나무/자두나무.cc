#include <iostream>
#include <algorithm>

using namespace std;

int t, w, curTree, result;
int numOf1;
int dp[1001][31][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t >> w;
    for (int i = 1; i <= t; i++)
    {
        cin >> curTree;
        if (curTree == 1)
        {
            numOf1++;
            dp[i][0][1] = numOf1;
            for (int j = 1; j <= w; j++)
            {
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + 1;
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]);
            }
        }
        else
        {
            for (int j = 1; j <= w; j++)
            {
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]);
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + 1;
            }
        }

    }
    for (int i = 0; i <= w; i++)
    {
        result = max({ result, dp[t][i][1], dp[t][i][2] });
    }
    cout << result;
    return 0;
}