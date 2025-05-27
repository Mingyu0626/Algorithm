#include <iostream>
#include <stack>

using namespace std;

int n, m, a, t, result;
stack<pair<int, int>> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (0 < n--)
    {
        cin >> m;
        if (m == 1)
        {
            cin >> a >> t;
            s.push({ a, t });
        }

        if (!s.empty())
        {
            s.top().second -= 1;

            if (s.top().second == 0)
            {
                result += s.top().first;
                s.pop();
            }
        }
    }
    cout << result;
    return 0;
}
