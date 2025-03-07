#include <iostream>
#include <string>

using namespace std;

int n, lineSize;
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    lineSize = 2 * n - 1;
    str.assign(lineSize, ' ');
    int l = lineSize / 2, r = lineSize / 2;
    while (0 <= l && r < lineSize)
    {
        str[l] = str[r] = '*';
        for (int i = 0; i <= r; i++)
        {
            cout << str[i];
        }
        cout << '\n';
        l--, r++;
    }

    l++, r--;
    while (l < r)
    {
        str[l] = str[r] = ' ';
        for (int i = 0; i <= r; i++)
        {
            cout << str[i];
        }
        cout << '\n';
        l++, r--;
    }
    return 0;
}