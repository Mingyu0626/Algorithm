#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int l = 0, r = s.length() - 1;
    char prev = s[l];
    bool isSameAll = true;
    while (l <= r)
    {
        if (s[l] != s[r])
        {
            cout << s.length();
            return 0;
        }
        else
        {
            if (prev != s[l] || prev != s[r])
            {
                isSameAll = false;
            }
        }
        l++, r--;
    }
    if (isSameAll) cout << -1;
    else cout << s.length() - 1;
    return 0;
}