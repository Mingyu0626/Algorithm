#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int n;
string str;

void divide(int startIdx, int distance, bool isMiddle);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> n)
    {
        str.assign(pow(3, n), '-');
        divide(0, pow(3, n), false);
        cout << str << '\n';
    }
    return 0;
}

void divide(int startIdx, int distance, bool isMiddle)
{
    if (isMiddle)
    {
        for (int i = startIdx; i < startIdx + distance; i++)
        {
            str[i] = ' ';
        }
        return;
    }
    else if (distance != 1)
    {
        int nextDistance = distance / 3;
        divide(startIdx, nextDistance, false);
        divide(startIdx + nextDistance, nextDistance, true);
        divide(startIdx + nextDistance * 2, nextDistance, false);
    }
}