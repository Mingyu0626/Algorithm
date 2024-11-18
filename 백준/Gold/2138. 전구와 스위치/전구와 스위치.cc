#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int n, result = 1e9;
string a, b, cur;

void go(string& s, int curResult);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;

    if (a[0] == b[0])
    {
        cur = a;
        if (n > 2) cur[2] = (cur[2] == '0') ? '1' : '0';
        go(cur, 2);

        cur = a;
        go(cur, 0);
    }
    else
    {
        cur = a;
        cur[0] = b[0], cur[1] = (cur[1] == '0') ? '1' : '0';
        if (n > 2) cur[2] = (cur[2] == '0') ? '1' : '0';
        go(cur, 1);


        cur = a;
        cur[0] = b[0];
        cur[1] = (cur[1] == '0') ? '1' : '0';
        go(cur, 1);
    }

    if (result == 1e9) cout << -1;
    else cout << result;
    return 0;
}

void go(string& s, int curResult)
{
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == b[i]) continue;
        else
        {
            curResult++;
            s[i] = b[i];
            s[i + 1] = (s[i + 1] == '0') ? '1' : '0';
            if (i < n - 2)
            {
                s[i + 2] = (s[i + 2] == '0') ? '1' : '0';
            }
        }
    }
    if (s[n - 1] == b[n - 1]) result = min(result, curResult);
}