#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int n;
string s;
map<string, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        s = s.substr(s.find('.') + 1);
        m[s]++;
    }
    for (auto a : m) cout << a.first << ' ' << a.second << '\n';
    return 0;
}