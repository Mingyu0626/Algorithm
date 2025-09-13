#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int t;
string s, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (cin >> s)
    {
        int cnt = 0;
        do
        {
            result = s;
            if (++cnt == 2)
            {
                break;
            }
        } while (next_permutation(s.begin(), s.end()));
        cout << result << '\n';
    }
    return 0;
}