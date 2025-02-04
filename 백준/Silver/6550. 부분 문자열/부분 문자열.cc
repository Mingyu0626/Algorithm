#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, t;
    while (cin >> s >> t)
    {
        int a = 0, b = 0;
        while (a < s.size() && b < t.size())
        {
            if (s[a] == t[b]) a++;
            b++;
        }
        if (a == s.size()) cout << "Yes\n";
        else if (b == t.size()) cout << "No\n";
    }
    return 0;
}