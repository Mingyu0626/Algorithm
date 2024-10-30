#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a, b;
int dp[4001][4001], result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(dp[i][j], result);
            }
        }
    }
    cout << result;
    return 0;
}