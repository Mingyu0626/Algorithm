#include <iostream>
#include <algorithm>

using namespace std; 

int n;
int cur[3][2], previous[3][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int a, b, c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        cur[0][0] = max(previous[0][0], previous[1][0]) + a;
        cur[1][0] = max({ previous[0][0], previous[1][0], previous[2][0] }) + b;
        cur[2][0] = max(previous[1][0], previous[2][0]) + c;

        cur[0][1] = min(previous[0][1], previous[1][1]) + a;
        cur[1][1] = min({ previous[0][1], previous[1][1], previous[2][1] }) + b;
        cur[2][1] = min(previous[1][1], previous[2][1]) + c;

        for (int j = 0; j < 3; j++)
        {
            previous[j][0] = cur[j][0];
            previous[j][1] = cur[j][1];
        }
    }
    cout << max({ cur[0][0], cur[1][0], cur[2][0] }) << ' ';
    cout << min({ cur[0][1], cur[1][1], cur[2][1] });
    return 0;
}