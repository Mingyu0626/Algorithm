#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string ps, s;
vector<string> v;
int n, num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> ps >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        v.emplace_back(s);
    }

    for (int i = 0; i <= 25; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (ps.find(v[j]) != ps.npos)
            {
                cout << ps;
                break;
            }
        }

        for (int j = 0; j < ps.length(); ++j)
        {
            ps[j] = ps[j] == 'z' ? 'a' : ps[j] + 1;
        }
    }
    return 0;
}