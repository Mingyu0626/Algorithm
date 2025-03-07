#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            cout << 0;
            exit(0);
        }
        l++, r--;
    }
    cout << 1;
    return 0;
}