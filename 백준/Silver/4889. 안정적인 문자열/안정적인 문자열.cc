#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cnt = 1, result, open;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (true)
    {
        cin >> s;
        result = open = 0;
        for (char& c : s)
        {
            if (c == '-') return 0;
            else if (c == '{')
            {
                open++;
            }
            else if (c == '}')
            {
                if (open > 0)
                {
                    open--;
                }
                else
                {
                    open++;
                    result++;
                }
            }
        }
        if (open > 0)
        {
            result += (open / 2);
        }
        cout << cnt << ". " << result << '\n';
        cnt++;
    }
    return 0;
}