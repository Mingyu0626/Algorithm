#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, result;
int sideR, sideB, numOfR, numOfB;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;

    char sideColor = s[0];
    int cnt = 1;
    for (int i = 1; i < n; i++, cnt++)
    {
        if (sideColor != s[i])
        {
            if (sideColor == 'R')
            {
                sideR = max(sideR, cnt);
            }
            else
            {
                sideB = max(sideB, cnt);
            }
            break;
        }
    }

    sideColor = s[n - 1], cnt = 1;
    for (int i = n - 2; i >= 0; i--, cnt++)
    {
        if (sideColor != s[i])
        {
            if (sideColor == 'R')
            {
                sideR = max(sideR, cnt);
            }
            else
            {
                sideB = max(sideB, cnt);
            }
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R') numOfR++;
        else numOfB++;
    }
    cout << min(numOfR - sideR, numOfB - sideB);
    return 0;
}